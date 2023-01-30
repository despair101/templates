struct Node {
    int x;
    int cnt;
    int dp;
    int y;
    Node* l;
    Node* r;

    Node() = default;
    explicit Node(int x_, int cnt_ = 1) : x(x_), cnt(cnt_), dp(cnt_), y(rnd()), l(nullptr), r(nullptr) {}
    ~Node() {
        if (l) delete l;
        if (r) delete r;
    }
};

inline int getCnt(Node* a) { return (a ? a->cnt : 0); }
inline int getDp(Node* a) { return (a ? a->dp : 0); }

void relax(Node* a) {
    if (!a) return;
    a->dp = getCnt(a) + getDp(a->l) + getDp(a->r);
}

Node* merge(Node* a, Node* b) {
    if (!a) return b;
    if (!b) return a;
    if (a->y > b->y) {
        a->r = merge(a->r, b);
        relax(a);
        return a;
    } else {
        b->l = merge(a, b->l);
        relax(b);
        return b;
    }
}

// split to (<v) and (>=v)
std::pair<Node*, Node*> split(Node* a, int v) { 
    if (!a) return { nullptr, nullptr };
    if (a->x < v) {
        auto [t1, t2] = split(a->r, v);
        a->r = t1;
        relax(a);
        return { a, t2 };
    } else {
        auto [t1, t2] = split(a->l, v);
        a->l = t2;
        relax(a);
        return { t1, a };
    }
}

Node* insert(Node* a, int v, int c = 1) {
    auto [t1, t2] = split(a, v);
    auto [t21, t22] = split(t2, v + 1);
    if (t21) {
        t21->cnt += c;
        relax(t21);
    } else {
        t21 = new Node(v, c);
    }
    return merge(t1, merge(t21, t22));
}

Node* erase(Node* a, int v, int c = 1) {
    auto [t1, t2] = split(a, v);
    auto [t21, t22] = split(t2, v + 1);
    if (getCnt(t21) > c) {
        t21->cnt -= c;
        relax(t21);
        return merge(t1, merge(t21, t22));
    } else {
        delete t21;
        return merge(t1, t22);
    }
}

class SegmentTreeOfTreaps {
  int size;
  std::vector<Node*> t;
  
  void add(int i, int v, int x, int lx, int rx) {
    t[x] = insert(t[x], v);
    if (rx - lx > 1) {
      int mx = (lx + rx) / 2;
      if (i < mx) {
        add(i, v, 2 * x + 1, lx, mx);
      } else {
        add(i, v, 2 * x + 2, mx, rx);
      }
    }
  }

  void remove(int i, int v, int x, int lx, int rx) {
    t[x] = erase(t[x], v);
    if (rx - lx > 1) {
      int mx = (lx + rx) / 2;
      if (i < mx) {
        remove(i, v, 2 * x + 1, lx, mx);
      } else {
        remove(i, v, 2 * x + 2, mx, rx);
      }
    }
  }
 
  int get(int l, int r, int v, int x, int lx, int rx) { 
    int ans = 0;
    if (lx >= r || rx <= l) {
      ans = 0;
    } else if (lx >= l && rx <= r) {
      auto [t1, t2] = split(t[x], v);
      ans = getDp(t1);
      t[x] = merge(t1, t2);
    } else {
      int mx = (lx + rx) / 2;
      ans = get(l, r, v, 2 * x + 1, lx, mx) + get(l, r, v, 2 * x + 2, mx, rx);
    }
    return ans;
  }
  
 public:
  void add(int i, int v) {
    add(i, v, 0, 0, size);
  }

  void remove(int i, int v) {
    remove(i, v, 0, 0, size);
  }
  
  int get(int l, int r, int v) {
    return get(l, r, v, 0, 0, size);
  }
  
  SegmentTreeOfTreaps() = default;
  explicit SegmentTreeOfTreaps(int n) : size(n), t(4 * size, nullptr) {}
};

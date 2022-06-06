struct Node {
  int v;
  int y;
  int cnt;
  int dp;
  Node* l;
  Node* r;
 
  Node(int v_) {
    v = v_;
    y = rnd();
    cnt = dp = 1;
    l = r = nullptr;
  }
};
 
int get(Node* t) {
  if (!t) return 0;
  return t->dp;
}
 
void relax(Node* t) {
  t->dp = t->cnt + get(t->l) + get(t->r);
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
 
pair<Node*, Node*> split(Node* a, int v) {
  // <= & >
  if (!a) return { nullptr, nullptr };
  if (a->v > v) {
    auto [t1, t2] = split(a->l, v);
    a->l = t2;
    relax(a);
    return { t1, a };
  } else {
    auto [t1, t2] = split(a->r, v);
    a->r = t1;
    relax(a);
    return { a, t2 };
  }
}
 
Node* insert(Node* a, int v) {
  auto [t1, t2] = split(a, v);
  // t1 <= v & t2 > v
  auto [t11, t12] = split(t1, v - 1);
  // t11 < v & t12 == v
  if (t12) {
    ++t12->cnt, ++t12->dp;
  } else {
    t12 = new Node(v);
  }
  return merge(t11, merge(t12, t2));
}
 
class SegmentTreeOfTreaps {
  int size;
  vector<Node*> t;
  
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
 
  int get_(int l, int r, int v, int x, int lx, int rx) {
    int ans = 0;
    if (lx >= r || rx <= l) {
      ans = 0;
    } else if (lx >= l && rx <= r) {
      auto [t1, t2] = split(t[x], v - 1);
      ans = get(t1);
      t[x] = merge(t1, t2);
    } else {
      int mx = (lx + rx) / 2;
      ans = get_(l, r, v, 2 * x + 1, lx, mx) + get_(l, r, v, 2 * x + 2, mx, rx);
    }
    return ans;
  }
  
public:
  void add(int i, int v) {
    add(i, v, 0, 0, size);
  }
  
  int get_(int l, int r, int v) {
    return get_(l, r, v, 0, 0, size);
  }
  
  MergeSortTree(int n) : size(n), t(4 * n, nullptr) {}
};

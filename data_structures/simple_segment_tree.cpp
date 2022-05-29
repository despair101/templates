struct Node {
}; //TODO

template<class A> class SegmentTree {
  const Node NEUTRAL{
  }; //TODO

  int size = 1;
  vector<Node> t;

  inline Node compose(Node l, Node r) {
    Node res; //TODO
    return res;
  }

  void build(int x, int lx, int rx, const vector<A>& a) {
    if (rx - lx == 1) {
      if (lx < a.size()) {
        //TODO
      } else {
        t[x] = NEUTRAL;
      }
    } else {
      int mx = (lx + rx) / 2;
      build(2 * x + 1, lx, mx, a);
      build(2 * x + 2, mx, rx, a);
      t[x] = compose(t[2 * x + 1], t[2 * x + 2]);
    }
  }

  void change(int i, Node v, int x, int lx, int rx) {
    if (rx - lx == 1) {
      t[x] = v;
    } else {
      int mx = (lx + rx) / 2;
      if (i < mx) {
        change(i, v, 2 * x + 1, lx, mx);
      } else {
        change(i, v, 2 * x + 2, mx, rx);
      }
      t[x] = compose(t[2 * x + 1], t[2 * x + 2]);
    }
  }

  Node get(int l, int r, int x, int lx, int rx) {
    if (lx >= l && rx <= r) {
      return t[x];
    }
    if (lx >= r || rx <= l) {
      return NEUTRAL;
    }
    int mx = (lx + rx) / 2;
    return compose(get(l, r, 2 * x + 1, lx, mx), get(l, r, 2 * x + 2, mx, rx));
  }

public:
  SegmentTree(const vector<A>& a) {
    while (size < a.size()) size *= 2;
    t.resize(2 * size - 1);
    build(0, 0, size, a);
  }
  
  void change(int i, Node v) {
    change(i, v, 0, 0, size);
  }
  
  Node get(int l, int r) {
    return get(l, r, 0, 0, size);
  }
};

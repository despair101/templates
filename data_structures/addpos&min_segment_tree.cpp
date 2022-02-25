class SegmentTree {
  struct Node {
    int mx = 0;
    int add = 0;
  };

  int size = 1;
  vector<Node> t;

  void build(int x, int lx, int rx, const vector<int>& a) {
    if (rx - lx == 1) {
      if (lx < a.size()) {
        t[x].mx = a[lx];
      }
    } else {
      int mx = (lx + rx) / 2;
      build(2 * x + 1, lx, mx, a);
      build(2 * x + 2, mx, rx, a);
      t[x].mx = max(t[2 * x + 1].mx, t[2 * x + 2].mx);
    }
  }

  void modify(int l, int r, int v, int x, int lx, int rx) {
    if (lx >= r || rx <= l) return;
    if (lx >= l && rx <= r) {
      t[x].mx += v;
      t[x].add += v;
    } else {
      int mx = (lx + rx) / 2;
      modify(l, r, v, 2 * x + 1, lx, mx);
      modify(l, r, v, 2 * x + 2, mx, rx);
      t[x].mx = max(t[2 * x + 1].mx, t[2 * x + 2].mx) + t[x].add;
    }
  }

  int get(int l, int r, int x, int lx, int rx) {
    if (lx >= r || rx <= l) return 0;
    if (lx >= l && rx <= r) return t[x].mx;
    int mx = (lx + rx) / 2;
    return max(get(l, r, 2 * x + 1, lx, mx), get(l, r, 2 * x + 2, mx, rx)) + t[x].add;
  }

public:
  SegmentTree(const vector<int>& a) {
    while (size < a.size()) size *= 2;
    t.resize(2 * size - 1);
    build(0, 0, size, a);
  }

  void modify(int l, int r, int v) {
    modify(l, r, v, 0, 0, size);
  }

  int get(int l, int r) {
    return get(l, r, 0, 0, size);
  }
};

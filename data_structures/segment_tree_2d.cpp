struct ST {
  int size;
  std::vector<int> t;
 
  void build(int x, int lx, int rx, const std::vector<int>& a) {
    if (rx - lx == 1) {
      if (lx < size) {
        t[x] = a[lx];
      }
    } else {
      int mx = (lx + rx) / 2;
      build(2 * x + 1, lx, mx, a);
      build(2 * x + 2, mx, rx, a);
      t[x] = std::min(t[2 * x + 1], t[2 * x + 2]);
    }
  }
 
  int get(int l, int r, int x, int lx, int rx) {
    if (lx >= r || rx <= l) return INT_MAX;
    if (lx >= l && rx <= r) return t[x];
    int mx = (lx + rx) / 2;
    return std::min(get(l, r, 2 * x + 1, lx, mx), get(l, r, 2 * x + 2, mx, rx));
  }
  int get(int l, int r) {
    return get(l, r, 0, 0, size);
  }
  
  ST() = default;
  explicit ST(const std::vector<int>& a) : size(a.size()), t(4 * size) {
    build(0, 0, size, a);
  }
};
 
class MainSegmentTree {
  struct Node {
    std::vector<int> v;
    ST st;
  };
  int size1, size2;
  std::vector<Node> t;
 
  void build(int x, int lx, int rx, const std::vector<std::vector<int>>& a) {
    t[x].v.assign(size2, INT_MAX);
    if (rx - lx == 1) {
      if (lx < size1) {
        t[x].v = a[lx];
      } 
      t[x].st = ST(t[x].v);
    } else {
      int mx = (lx + rx) / 2;
      build(2 * x + 1, lx, mx, a);
      build(2 * x + 2, mx, rx, a);
      for (int i = 0; i < size2; ++i) {
        t[x].v[i] = std::min(t[2 * x + 1].v[i], t[2 * x + 2].v[i]);
      }
      t[x].st = ST(t[x].v);
    }
  }
 
 public:
  int get(int l1, int r1, int l2, int r2, int x, int lx, int rx) {
    if (lx >= r1 || rx <= l1) return INT_MAX;
    if (lx >= l1 && rx <= r1) return t[x].st.get(l2, r2);
    int mx = (lx + rx) / 2;
    return std::min(get(l1, r1, l2, r2, 2 * x + 1, lx, mx), get(l1, r1, l2, r2, 2 * x + 2, mx, rx));
  }
 
  int get(int l1, int r1, int l2, int r2) {
    if (l1 >= r1 || l2 >= r2) return INT_MAX;
    return get(l1, r1, l2, r2, 0, 0, size1);
  }
  
  MainSegmentTree() = default;
  explicit MainSegmentTree(const std::vector<std::vector<int>>& a) {
    size1 = sz(a), size2 = sz(a[0]);
    t.resize(4 * size1);
    build(0, 0, size1, a);
  }
};

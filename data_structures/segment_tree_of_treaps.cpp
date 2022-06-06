//treap: https://github.com/despair101/templates/blob/main/data_structures/treap_ordered_set.cpp
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
      auto [t1, t2] = split(t[x], v);
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

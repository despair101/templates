const int LX = 0, RX = (1 << 30);

struct Node {
  int min_v;
  int cnt;
  int  add;
  Node* l;
  Node* r;

  Node(int lx, int rx) {
    l = r = nullptr;
    min_v = 0;
    cnt = rx - lx;
    add = 0;
  }
};

void compose(Node* nd) {
  nd->min_v = min(nd->l->min_v, nd->r->min_v);
  nd->cnt = 0;
  if (nd->l->min_v == nd->min_v) nd->cnt += nd->l->cnt;
  if (nd->r->min_v == nd->min_v) nd->cnt += nd->r->cnt;
  nd->min_v += nd->add;
}

void add(int l, int r, int v, Node* nd, int lx, int rx) {
  if (lx >= r || rx <= l) return;
  if (lx >= l && rx <= r) {
    nd->min_v += v;
    nd->add += v;
  } else {
    int mx = (lx + rx) / 2;
    if (!nd->l) nd->l = new Node(lx, mx);
    if (!nd->r) nd->r = new Node(mx, rx);
    add(l, r, v, nd->l, lx, mx);
    add(l, r, v, nd->r, mx, rx);
    compose(nd);
  }
}

void dfs(Node* nd) {
  if (nd->l) dfs(nd->l);
  if (nd->r) dfs(nd->r);
  delete nd;
}

struct rectangle {
  int x1, y1, x2, y2;
};

ll get_rectangles_union(vector<rectangle>& v) {
  struct event {
    int x, y1, y2;
    int type;
  };

  vector<event> vec(2 * sz(v));
  for (int i = 0; i < sz(v); ++i) {
    vec[2 * i] = { v[i].x1, v[i].y1, v[i].y2, 1 };
    vec[2 * i + 1] = { v[i].x2, v[i].y1, v[i].y2, -1 };
  }

  //v.clear();
  //v.shrink_to_fit();

  sort(vec.begin(), vec.end(), [&](event& a, event& b) {
    return a.x < b.x;
    });

  Node* tree = new Node(LX, RX);
  ll area = 0;

  for (int i = 0; i < sz(vec) - 1; ++i) {
    add(vec[i].y1, vec[i].y2, vec[i].type, tree, LX, RX);
    area += ll(vec[i + 1].x - vec[i].x) * (RX - LX - tree->cnt);
  }

  dfs(tree);
  return area;
}

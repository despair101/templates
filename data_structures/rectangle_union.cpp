const ll LX = 0, RX = 1ll << 30;
 
struct Node {
  ll min_v, cnt, add;
  Node* l, * r;
  Node(ll lx, ll rx) {
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
 
void add(ll l, ll r, int v, Node* nd, ll lx, ll rx) {
  if (lx >= r || rx <= l) return;
  if (!nd) nd = new Node(lx, rx);
  if (lx >= l && rx <= r) {
    nd->min_v += v;
    nd->add += v;
  } else {
    ll mx = (lx + rx) / 2;
    if (!nd->l) nd->l = new Node(lx, mx);
    if (!nd->r) nd->r = new Node(mx, rx);
    add(l, r, v, nd->l, lx, mx), add(l, r, v, nd->r, mx, rx);
    compose(nd);
  }
}
 
struct rectangle {
  ll x1, y1, x2, y2;
};
 
struct event {
  ll x, y1, y2;
  int type;
};
 
void dfs(Node* nd) {
  if (!nd) return;
  if (nd->l) dfs(nd->l);
  if (nd->r) dfs(nd->r);
  nd->l = nd->r = nullptr;
  delete nd;
}
 
ll get_rectangles_union(vector<rectangle>& v) {
  if (v.empty()) return 0;
  vector<event> vec(2 * sz(v));
  for (int i = 0; i < sz(v); ++i) {
    vec[2 * i] = { v[i].x1, v[i].y1, v[i].y2, 0 };
    vec[2 * i + 1] = { v[i].x2, v[i].y1, v[i].y2, 1 };
  }
  v.clear();
  v.shrink_to_fit();
  sort(vec.begin(), vec.end(), [&](event& a, event& b) {
    if (a.x < b.x) return true;
    if (a.x > b.x) return false;
    return a.type < b.type;
    });
  Node* tree = new Node(LX, RX);
  ll area = 0;
  add(vec[0].y1, vec[0].y2, 1, tree, LX, RX);
  for (int i = 1; i < sz(vec); ++i) {
    area += (vec[i].x - vec[i - 1].x) * (RX - LX - tree->cnt);
    if (!vec[i].type) {
      add(vec[i].y1, vec[i].y2, 1, tree, LX, RX);
    } else {
      add(vec[i].y1, vec[i].y2, -1, tree, LX, RX);
    }
  }
  dfs(tree);
  return area;
}

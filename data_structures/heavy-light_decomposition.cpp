const int N = 1e5; //TODO
const int K = 17; //TODO

vector<int> g[N], euler;
int s[N], he[N], ind[N], hp[N], lp[N], depth[N], bu[K][N];

class SegmentTree {
  int size = 1;
  vector<int> t;

  void change(int i, int v, int x, int lx, int rx) {
    if (rx - lx == 1) {
      t[x] = v;
    } else {
      int mx = (lx + rx) / 2;
      if (i < mx) {
        change(i, v, 2 * x + 1, lx, mx);
      } else {
        change(i, v, 2 * x + 2, mx, rx);
      }
      t[x] = max(t[2 * x + 1], t[2 * x + 2]);
    }
  }

  int get(int l, int r, int x, int lx, int rx) {
    if (lx >= r || rx <= l) return 0;
    if (lx >= l && rx <= r) return t[x];
    int mx = (lx + rx) / 2;
    return max(get(l, r, 2 * x + 1, lx, mx), get(l, r, 2 * x + 2, mx, rx));
  }

public:
  SegmentTree(int n) {
    while (size < n) size *= 2;
    t.assign(2 * size - 1, 0);
  }

  void change(int i, int v) {
    change(i, v, 0, 0, size);
  }

  int get(int l, int r) {
    return get(l, r, 0, 0, size);
  }
};

void calcSizes(int u, int p) {
  s[u] = 1;
  if (p != -1) g[u].erase(find(g[u].begin(), g[u].end(), p));

  for (int v : g[u]) {
    bu[0][v] = u;
    depth[v] = depth[u] + 1;
    calcSizes(v, u);
    s[u] += s[v];
  }
}

void dfs(int u, int hve) {
  ind[u] = sz(euler);
  euler.push_back(u);
  sort(g[u].begin(), g[u].end(), [&](int i, int j) {
    return s[i] > s[j];
    });

  for (int i = 0; i < sz(g[u]); ++i) {
    int v = g[u][i];
    if (i == 0) {
      hp[v] = hve;
      dfs(v, hve);
    } else {
      lp[v] = ind[u];
      dfs(v, sz(euler));
    }
    euler.push_back(u);
  }
}

void build() {
  memset(lp, -1, sizeof lp);
  memset(hp, -1, sizeof hp);

  calcSizes(0, -1);
  dfs(0, 0);

  for (int k = 1; k < K; ++k) {
    for (int i = 0; i < N; ++i) {
      bu[k][i] = bu[k - 1][bu[k - 1][i]];
    }
  }
}

int lca(int u, int v) {
  if (depth[u] != depth[v]) {
    if (depth[u] < depth[v]) swap(u, v);
    for (int k = K - 1; k >= 0; --k) {
      if (depth[bu[k][u]] > depth[v]) {
        u = bu[k][u];
      }
    }
    u = bu[0][u];
  }

  if (u == v) return u;

  for (int k = K - 1; k >= 0; --k) {
    if (bu[k][u] != bu[k][v]) {
      u = bu[k][u];
      v = bu[k][v];
    }
  }
  return bu[0][u];
}

int getMaxOnVert(int u, int v, SegmentTree& st) {
  int ans = 0;
  int i = ind[u];
  ans = max(ans, he[u]);
  while (i > ind[v]) {
    if (hp[u] != -1) {
      if (hp[u] >= ind[v]) {
        ans = max(ans, st.get(hp[u], i));
        i = hp[u];
      } else {
        ans = max(ans, st.get(ind[v], i));
        i = ind[v];
      }
    } else {
      i = lp[u];
      ans = max(ans, he[euler[i]]);
    }
    u = euler[i];
  }
  return ans;
}

int getMax(int u, int v, SegmentTree& st) {
  int w = lca(u, v);
  return max(getMaxOnVert(u, w, st), getMaxOnVert(v, w, st));
}

void solve() {
  int n;
  cin >> n;

  for (int i = 0; i < n; ++i) {
    cin >> he[i];
  }

  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  build();

  SegmentTree st(sz(euler));
  for (int i = 0; i < sz(euler); ++i) {
    st.change(i, he[euler[i]]);
  }
}

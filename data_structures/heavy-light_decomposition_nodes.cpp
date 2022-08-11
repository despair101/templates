class SegmentTree {
    int size;
    vector<ll> t;

    ll compose(ll x, ll y) {
        return x + y;
    }

    void change(int i, ll v, int x, int lx, int rx) {
        if (rx - lx == 1) {
            t[x] = v;
        } else {
            int mx = (lx + rx) / 2;
            if (i < mx) change(i, v, 2 * x + 1, lx, mx);
            else change(i, v, 2 * x + 2, mx, rx);
            t[x] = compose(t[2 * x + 1], t[2 * x + 2]);
        }
    }

    ll get(int l, int r, int x, int lx, int rx) {
        if (lx >= l && rx <= r) return t[x];
        if (lx >= r || rx <= l) return 1;
        int mx = (lx + rx) / 2;
        return compose(get(l, r, 2 * x + 1, lx, mx), get(l, r, 2 * x + 2, mx, rx));
    }

public:
    void change(int i, ll v) {
        change(i, v, 0, 0, size);
    }

    ll get(int l, int r) {
        return get(l, r, 0, 0, size);
    }

    explicit SegmentTree() {}
    explicit SegmentTree(int n) : size(n) {
        t.assign(4 * size, 0);
    }
};

struct HLD {
    int t = 0;
    vector<int> de;
    vector<int> up;
    vector<int> ti;
    vector<int> si;
    vector<int> pa;
    vector<vector<int>> g;
    SegmentTree st;

    void calc(int u) {
        si[u] = 1;
        for (int& v : g[u]) {
            pa[v] = u;
            de[v] = de[u] + 1;
            g[v].erase(find(g[v].begin(), g[v].end(), u));
            calc(v);
            si[u] += si[v];
            if (si[v] > si[g[u].front()]) swap(v, g[u].front());
        }
    }

    void dfs(int u) {
        ti[u] = t++;
        for (int v : g[u]) {
            up[v] = (v == g[u].front() ? up[u] : v);
            dfs(v);
        }
    }

    void change(int u, ll val) {
        st.change(ti[u], val);
    }

    int lca(int u, int v) {
        while (up[u] != up[v]) {
            if (de[up[u]] < de[up[v]]) swap(u, v);
            u = pa[up[u]];
        }
        if (de[u] < de[v]) swap(u, v);
        return v;
    }

    ll compose(ll x, ll y) {
        return x + y;
    }

    ll get(int u, int v) {
        ll ans = 0;
        while (up[u] != up[v]) {
            if (de[up[u]] < de[up[v]]) swap(u, v);
            ans = compose(ans, st.get(ti[up[u]], ti[u] + 1));
            u = pa[up[u]];
        }
        if (de[u] < de[v]) swap(u, v);
        ans = compose(ans, st.get(ti[v], ti[u] + 1));
        return ans;
    }

    explicit HLD() {}
    explicit HLD(int n, const vector<vector<int>>& gr) : de(n), up(n), ti(n), si(n), pa(n), g(gr), st(n) {
        calc(0);
        dfs(0);
    }
};

struct DSU {
    int cnt;
    vector<int> p;
    vector<int> r;

    pair<int, int> merge(int u, int v) {
        u = get(u), v = get(v);
        if (u == v) return { u, v };
        --cnt;
        if (r[u] < r[v]) swap(u, v);
        r[u] += r[v];
        p[v] = u;
        return { u, v };
    }

    void split(int u, int v) {
        if (u == v) return;
        ++cnt;
        r[u] -= r[v];
        p[v] = v;
    }

    int get(int u) {
        return (p[u] == u ? u : get(p[u]));
    }

    DSU(int n) : cnt(n), p(n), r(n, 1) {
        iota(p.begin(), p.end(), 0);
    }
};

struct SegmentTree {
    int size;
    vector<vector<pair<int, int>>> t;

    void insert(int l, int r, pair<int, int> e, int x, int lx, int rx) {
        if (lx >= r || rx <= l) return;
        if (lx >= l && rx <= r) {
            t[x].push_back(e);
            return;
        }
        int mx = (lx + rx) >> 1;
        insert(l, r, e, 2 * x + 1, lx, mx);
        insert(l, r, e, 2 * x + 2, mx, rx);
    }
    void insert(int l, int r, pair<int, int> e) {
        if (e.first > e.second) swap(e.first, e.second);
        insert(l, r, e, 0, 0, size);
    }

    void dfs(int x, int lx, int rx, vector<int>& c, DSU& d) {
        vector<pair<int, int>> kok;
        for (auto [u, v] : t[x]) {
            kok.push_back(d.merge(u, v));
        }
        if (rx - lx == 1) {
            c[lx] = d.cnt;
        } else {
            int mx = (lx + rx) >> 1;
            dfs(2 * x + 1, lx, mx, c, d);
            dfs(2 * x + 2, mx, rx, c, d);
        }
        reverse(kok.begin(), kok.end());
        for (auto [u, v] : kok) {
            d.split(u, v);
        }
    }
    vector<int> dfs(int n) {
        vector<int> c(size);
        DSU d(n);
        dfs(0, 0, size, c, d);
        return c;
    }

    SegmentTree(int n) : size(n), t(4 * n) {}
};

class DSU {
    int cnt;
    vector<int> p;
    vector<int> r;

public:
    int get(int u) {
        return (p[u] == u ? u : p[u] = get(p[u]));
    }

    inline int comps() { return cnt; }
    inline int rank(int u) { return r[get(u)]; }

    bool unite(int u, int v) {
        u = get(u), v = get(v);
        if (u == v) return false;
        if (r[u] < r[v]) swap(u, v);
        r[u] += r[v];
        p[v] = u;
        --cnt;
        return true;
    }

    explicit DSU() {}
    explicit DSU(int n) : cnt(n), p(n), r(n, 1) {
        iota(p.begin(), p.end(), 0);
    }
};

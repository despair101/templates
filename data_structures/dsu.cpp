class DSU {
    vector<int> p;
    vector<int> r;

public:
    int get(int u) {
        return (p[u] == u ? u : p[u] = get(p[u]));
    }

    inline int rank(int u) {
        return r[get(u)];
    }

    bool unite(int u, int v) {
        u = get(u), v = get(v);
        if (u == v) return false;
        if (r[u] < r[v]) swap(u, v);
        r[u] += r[v];
        p[v] = u;
        return true;
    }

    DSU(int n) : p(n), r(n) {
        iota(p.begin(), p.end(), 0);
        fill(r.begin(), r.end(), 1);
    }
};

class DSU {
    int cnt;
    vector<int> p;
    vector<int> r;

public:
    int get(int u) {
        return (p[u] == -1 ? u : p[u] = get(p[u]));
    }

    inline int getRank(int u) {
        return r[get(u)];
    }

    bool unite(int u, int v) {
        u = get(u), v = get(v);
        if (u == v) return false;
        if (r[u] < r[v]) swap(u, v);
        r[u] += r[v];
        p[v] = u;
        --cnt;
        return true;
    }

    DSU(int n) : p(n, -1), r(n), cnt(n) {}
};

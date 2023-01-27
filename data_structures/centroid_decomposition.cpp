struct CentroidDecomposition {
    int size;
    vector<bool> used;
    vector<int> si;
    vector<vector<pair<int, int>>> g;
    vector<vector<pair<int, ll>>> ca;

    void calcSizes(int u, int p, ll d, int c, int lvl) {
        si[u] = 1;
        for (auto [v, w] : g[u]) {
            if (v == p || used[v]) continue;
            calcSizes(v, u, d + w, c, lvl);
            si[u] += si[v];
        }
        if (lvl != -1) {
            ca[u].emplace_back(c, d);
        }
    };

    void findCentroid(int u, int p, int m, int lvl) {
        for (auto [v, w] : g[u]) {
            if (v == p || used[v]) continue;
            if (si[v] * 2 > m) {
                findCentroid(v, u, m, lvl);
                return;
            }
        }
        used[u] = true;
        ca[u].emplace_back(u, 0);
        for (auto [v, w] : g[u]) {
            if (!used[v]) {
                calcSizes(v, -1, w, u, lvl);
                findCentroid(v, -1, si[v], lvl + 1);
            }
        }
    };

    CentroidDecomposition() = default;
    explicit CentroidDecomposition(const vector<vector<pair<int, int>>>& g) : 
        size(g.size()), used(size), si(size), g(g), ca(size) {
        calcSizes(0, -1, 0, 0, -1);
        findCentroid(0, -1, si[0], 0);
    }
};

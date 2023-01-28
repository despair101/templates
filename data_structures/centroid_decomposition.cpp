template <class A>
struct CentroidDecomposition {
    int size;
    vector<bool> used;
    vector<int> si;
    vector<vector<pair<int, int>>> g;
    vector<vector<pair<int, A>>> ca;

    void calcSizes(int u, int p, A d, int c) {
        si[u] = 1;
        for (auto [v, w] : g[u]) {
            if (v == p || used[v]) continue;
            calcSizes(v, u, d + w, c);
            si[u] += si[v];
        }
        ca[u].emplace_back(c, d);
    };

    void findCentroid(int u, int p, int m) {
        for (auto [v, w] : g[u]) {
            if (v == p || used[v]) continue;
            if (si[v] * 2 > m) {
                findCentroid(v, u, m);
                return;
            }
        }
        used[u] = true;
        ca[u].emplace_back(u, 0);
        for (auto [v, w] : g[u]) {
            if (!used[v]) {
                calcSizes(v, -1, w, u);
                findCentroid(v, -1, si[v]);
            }
        }
    };

    CentroidDecomposition() = default;
    explicit CentroidDecomposition(const vector<vector<pair<int, int>>>& g) : 
        size(g.size()), used(size), si(size), g(g), ca(size) {
        calcSizes(0, -1, 0, 0);
        fill(ca.begin(), ca.end(), vector<pair<int, A>>());
        findCentroid(0, -1, si[0]);
    }
};

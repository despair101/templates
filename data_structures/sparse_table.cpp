class SparseTable {
    vector<vector<pair<int, int>>> t;

public:
    int get(int l, int r) {
        return min(t[__lg(r - l)][l], t[__lg(r - l)][r - (1 << __lg(r - l))]).second;
    }

    explicit SparseTable() {}
    explicit SparseTable(const vector<int>& a) {
        int n = a.size();
        t.assign(__lg(n) + 1, vector<pair<int, int>>(n));
        for (int i = 0; i < n; ++i) {
            t[0][i] = { a[i], i };
        }
        for (int j = 1; j <= __lg(n); ++j) {
            for (int i = 0; i + (1 << j) <= n; ++i) {
                t[j][i] = min(t[j - 1][i], t[j - 1][i + (1 << (j - 1))]);
            }
        }
    }
};

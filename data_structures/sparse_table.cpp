class SparseTable {
    vector<vector<pair<int, int>>> t;

public:
    pair<int, int> get(int l, int r) {
        int pw = __lg(r - l);
        return compose(t[pw][l], t[pw][r - (1 << pw)]);
    }
    
    pair<int, int> compose(const& pair<int, int> f, const& pair<int, int> s) {
        return min(f, s);
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
                t[j][i] = compose(t[j - 1][i], t[j - 1][i + (1 << (j - 1))]);
            }
        }
    }
};

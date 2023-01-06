class SparseTable {
    int size;
    vector<vector<pair<int, int>>> t;
    
    pair<int, int> compose(const& pair<int, int> f, const& pair<int, int> s) {
        return min(f, s);
    }

public:
    pair<int, int> get(int l, int r) {
        int pw = __lg(r - l);
        return compose(t[pw][l], t[pw][r - (1 << pw)]);
    }

    explicit SparseTable() {}
    explicit SparseTable(const vector<int>& a) : size(a.size()) {
        t.assign(__lg(size) + 1, vector<pair<int, int>>(size));
        for (int i = 0; i < size; ++i) {
            t[0][i] = { a[i], i };
        }
        for (int j = 1; j <= __lg(size); ++j) {
            for (int i = 0; i + (1 << j) <= size; ++i) {
                t[j][i] = compose(t[j - 1][i], t[j - 1][i + (1 << (j - 1))]);
            }
        }
    }
};

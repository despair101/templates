template <class A>
class SparseTable {
    int size;
    vector<vector<pair<A, int>>> t;
    
    pair<A, int> compose(const pair<A, int>& f, const pair<A, int>& s) {
        return min(f, s);
    }

public:
    pair<A, int> get(int l, int r) {
        int pw = __lg(r - l);
        return compose(t[pw][l], t[pw][r - (1 << pw)]);
    }

    SparseTable() = default;
    explicit SparseTable(const vector<A>& a) : size(a.size()), t(__lg(size) + 1), vector<pair<A, int>>(size) {
        for (int i = 0; i < size; ++i) {
            t[0][i] = pair(a[i], i);
        }
        for (int j = 1; j <= __lg(size); ++j) {
            for (int i = 0; i + (1 << j) <= size; ++i) {
                t[j][i] = compose(t[j - 1][i], t[j - 1][i + (1 << (j - 1))]);
            }
        }
    }
};

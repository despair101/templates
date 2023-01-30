template <class A>
class SparseTable {
    int size;
    std::vector<std::vector<std::pair<A, int>>> t;
    
    std::pair<A, int> compose(const std::pair<A, int>& f, const std::pair<A, int>& s) {
        return min(f, s);
    }

public:
    std::pair<A, int> get(int l, int r) {
        int pw = __lg(r - l);
        return compose(t[pw][l], t[pw][r - (1 << pw)]);
    }

    SparseTable() = default;
    explicit SparseTable(const std::vector<A>& a) :
        size(a.size()), t(__lg(size) + 1, std::vector<std::pair<A, int>>(size)) {
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

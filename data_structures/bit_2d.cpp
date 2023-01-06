template <class A>
class BIT_2D {
    int size;
    vector<vector<int>> t;

    int get(int ind, int mi, int ma) {
        int res = 0;
        for (int i = ind; i >= 0; i &= i + 1, --i) {
            res += upper_bound(t[i].begin(), t[i].end(), ma) - 
                lower_bound(t[i].begin(), t[i].end(), mi);
        }
        return res;
    }

public:
    int get(int l, int r, int mi, int ma) {
        return get(r, mi, ma) - get(l - 1, mi, ma);
    }

    explicit BIT_2D() {}
    explicit BIT_2D(const vector<int>& a) : size(a.size()), t(a.size()) {
        for (int i = 0; i < size; ++i) {
            for (int j = i; j < size; j |= j + 1) {
                t[j].push_back(a[i]);
            }
            sort(t[i].begin(), t[i].end());
        }
    }
};

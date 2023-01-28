template<class A>
class FenwickTree {
    int size;
    vector<A> t;

public:
    A get(int l, int r) {
        if (l > r) return 0;
        A res = 0;
        for (int i = r; i >= 0; i &= i + 1, --i) res += t[i];
        for (int i = l - 1; i >= 0; i &= i + 1, --i) res -= t[i];
        return res;
    }

    void add(int i, int v) {
        for (; i < size; i |= i + 1) t[i] += v;
    }

    int lb(A sum) {
        if (get(0, size - 1) < sum) return -1;
        int i = -1;
        for (int l = __lg(size); l >= 0; --l) {
            if (i + (1 << l) < size && sum > t[i + (1 << l)]) {
                i += (1 << l);
                sum -= t[i];
            }
        }
        return i + 1;
    }

    FenwickTree() = default;
    explicit FenwickTree(int n) : size(n), t(size) {}
};

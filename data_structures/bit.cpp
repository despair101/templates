template<class A> class BIT {
    int size;
    vector<A> t;

public:
    A get(int l, int r) {
        A res = 0;
        for (int i = r; i >= 0; i &= i + 1, --i) {
            res += t[i];
        for (int i = l - 1; i >= 0; i &= i + 1, --i) {
            res -= t[i];
        }
        return res;
    }
    
    void add(int i, int v) {
        for (; i < size; i |= i + 1) {
            t[i] += v;
        }
    }

    BIT(int n) {
        size = n;
        t.resize(size);
    }
};

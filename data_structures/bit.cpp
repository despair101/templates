template<class A> class BIT {
    int size;
    vector<A> t;

public:
    A get(int l, int r) {
        A res = 0;
        for (; r >= 0; r &= r + 1, --r) res += t[r];
        --l;
        for (; l >= 0; l &= l + 1, --l) res -= t[l];
        return res;
    }
    
    void add(int i, int v) {
        for (; i < size; i |= i + 1) t[i] += v;
    }

    BIT(int n) {
        size = n;
        t.resize(size);
    }
};

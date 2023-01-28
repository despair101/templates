class FenwickTreeRange {
    int size;
    vector<long long> t1;
    vector<long long> t2;

    long long get(int i, vector<long long>& t) {
        long long res = 0;
        for (; i >= 0; i &= i + 1, --i) res += t[i];
        return res;
    }

    void add(int i, long long val, vector<long long>& t) {
        for (; i < size; i |= i + 1) t[i] += val;
    }

public:
    long long get(int i) {
        return get(i, t1) * (i + 1) - get(i, t2);
    }

    long long get(int l, int r) {
        if (l > r) return 0;
        return get(r) - get(l - 1);
    }

    void add(int l, int r, long long val) {
        add(l, val, t1);
        add(r + 1, -val, t1);
        add(l, val * l, t2);
        add(r + 1, -val * (r + 1), t2);
    }

    void clear() {
        t1.assign(size, 0);
        t2.assign(size, 0);
    }

    FenwickTreeRange() = default;
    explicit FenwickTreeRange(int n) : size(n), t1(size), t2(size) {}
}; 

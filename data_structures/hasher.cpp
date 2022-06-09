//Mint: https://github.com/despair101/templates/blob/main/mint.cpp
template<int MOD, int P> struct Hasher {
    int size;
    vector<Mint<MOD>> h, p;

    Hasher(const string& s) : size(s.size() + 1) {
        h.assign(size, 0);
        p.assign(size, 1);
        for (int i = 0; i < size - 1; ++i) {
            h[i + 1] = h[i] * P + s[i];
            p[i + 1] = p[i] * P;
        }
    }

    int getHash(int l, int r) {
        return (h[r] - h[l] * p[r - l]).x;
    }
};

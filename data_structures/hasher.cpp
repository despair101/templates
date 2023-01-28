//Mint: https://github.com/despair101/templates/blob/main/mint.cpp

const int MOD = 1'000'000'007;

typedef ModularInt<MOD> Mint;

template <int MOD, int P>
struct Hasher {
    int size;
    vector<Mint> h, p;

    Mint getHash(int l, int r) {
        return h[r] - h[l] * p[r - l];
    }
    
    Hasher() = default;
    explicit Hasher(const string& s) : size(s.size() + 1), h(size), p(size, 1) {
        for (int i = 0; i < size - 1; ++i) {
            h[i + 1] = h[i] * P + s[i];
            p[i + 1] = p[i] * P;
        }
    }
};

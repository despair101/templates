// needs https://github.com/despair101/templates/blob/main/modular_int.cpp

template <int MOD, int P>
struct Hasher {
    int size;
    std::vector<ModularInt<MOD>> h, p;

    int getHash(int l, int r) {
        return (h[r] - h[l] * p[r - l]).x;
    }
    
    Hasher() = default;
    explicit Hasher(const std::string& s) : size(s.size() + 1), h(size), p(size, 1) {
        for (int i = 0; i < size - 1; ++i) {
            h[i + 1] = h[i] * P + s[i];
            p[i + 1] = p[i] * P;
        }
    }
};

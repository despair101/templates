template <int MOD>
struct ModularInt {
    int x;

    friend bool operator == (ModularInt a, ModularInt b) {
        return a.x == b.x;
    }
    friend bool operator != (ModularInt a, ModularInt b) {
        return a.x != b.x;
    }
    friend ModularInt operator + (ModularInt a, ModularInt b) {
        return (a.x + b.x >= MOD ? a.x + b.x - MOD : a.x + b.x);
    }
    friend ModularInt operator += (ModularInt& a, ModularInt b) {
        return a = a + b;
    }
    friend ModularInt operator - (ModularInt a, ModularInt b) {
        return (a.x - b.x < 0 ? a.x - b.x + MOD : a.x - b.x);
    }
    friend ModularInt operator -= (ModularInt& a, ModularInt b) {
        return a = a - b;
    }
    friend ModularInt operator * (ModularInt a, ModularInt b) {
        return (long long)(a.x) * b.x % MOD;
    }
    friend ModularInt operator *= (ModularInt& a, ModularInt b) {
        return a = a * b;
    }

    ModularInt inv() {
        return pow(MOD - 2);
    }

    ModularInt pow(long long n) {
        assert(n >= 0);
        ModularInt res = 1, a = x;
        while (n > 0) {
            if (n & 1) res *= a;
            a *= a;
            n >>= 1;
        }
        return res;
    }

    friend std::istream& operator >> (std::istream& in, ModularInt& a) {
        in >> a.x;
        return in;
    }
    friend std::ostream& operator << (std::ostream& out, ModularInt& a) {
        out << a.x;
        return out;
    }

    ModularInt() : x(0) {}
    ModularInt(long long x) : x(x) {
        if (abs(this->x) >= MOD) this->x %= MOD;
        if (this->x < 0) this->x += MOD;
    }
};

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

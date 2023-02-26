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

    friend istream& operator >> (istream& in, ModularInt& a) {
        in >> a.x;
        return in;
    }
    friend ostream& operator << (ostream& out, const ModularInt& a) {
        out << a.x;
        return out;
    }

    ModularInt() : x(0) {}
    ModularInt(long long x) {
        if (abs(x) >= MOD) x %= MOD;
        this->x = x;
        if (this->x < 0) this->x += MOD;
    }
};

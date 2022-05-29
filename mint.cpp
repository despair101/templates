template<int mod> struct Mint {
    int x;

    Mint(int x_) : x(x_ < 0 ? x_ % mod + mod : x_ % mod) {}

    friend bool operator == (Mint a, Mint b) {
        return a.x == b.x;
    }

    friend Mint operator + (Mint a, Mint b) {
        return (a.x + b.x >= mod ? a.x + b.x - mod : a.x + b.x);
    }
    friend Mint operator += (Mint& a, Mint b) {
        return a = (a + b);
    }

    friend Mint operator - (Mint a, Mint b) {
        return (a.x - b.x < 0 ? a.x - b.x + mod : a.x - b.x);
    }
    friend Mint operator -= (Mint& a, Mint b) {
        return a = (a - b);
    }

    friend Mint operator * (Mint a, Mint b) {
        return ll(a.x) * (b.x) % mod;
    }
    friend Mint operator *= (Mint& a, Mint b) {
        return a = (a * b);
    }

    Mint rev() {
        Mint a = this->x, res = 1;
        int n = mod - 2;
        while (n) {
            if (n & 1) res *= a;
            a *= a;
            n >>= 1;
        }
        return res;
    }

    friend istream& operator >> (istream& in, Mint<mod> a) {
        in >> a.x;
        return in;
    }
    friend ostream& operator << (ostream& out, Mint<mod> a) {
        out << a.x;
        return out;
    }
};

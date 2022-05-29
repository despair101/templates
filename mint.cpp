template<int MOD> struct Mint {
    int x;

    Mint(int x_) : x((x_ < 0 ? x_ % MOD + MOD : x_ % MOD)) {}
    Mint() {}

    friend bool operator == (Mint a, Mint b) { return a.x == b.x; }

    friend Mint operator + (Mint a, Mint b) { return (a.x + b.x >= MOD ? a.x + b.x - MOD : a.x + b.x); }
    friend Mint operator += (Mint& a, Mint b) { return a = (a + b); }

    friend Mint operator - (Mint a, Mint b) { return (a.x - b.x < 0 ? a.x - b.x + MOD : a.x - b.x); }
    friend Mint operator -= (Mint& a, Mint b) { return a = (a - b); }

    friend Mint operator * (Mint a, Mint b) { return ll(a.x) * (b.x) % MOD; }
    friend Mint operator *= (Mint& a, Mint b) { return a = (a * b); }

    Mint rev() {
        Mint a = this->x, res = 1;
        int n = MOD - 2;
        while (n) {
            if (n & 1) res *= a;
            a *= a;
            n >>= 1;
        }
        return res;
    }

    friend istream& operator >> (istream& in, Mint<MOD>& a) {
        in >> a.x;
        return in;
    }
    friend ostream& operator << (ostream& out, Mint<MOD> a) {
        out << a.x;
        return out;
    }
};

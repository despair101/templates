template<int MOD> struct Mint {
    int x = 0;

    friend bool operator == (Mint a, Mint b) { return a.x == b.x; }

    friend Mint operator + (Mint a, Mint b) { return (a.x + b.x >= MOD ? a.x + b.x - MOD : a.x + b.x); }
    friend Mint operator += (Mint& a, Mint b) { return a = (a + b); }

    friend Mint operator - (Mint a, Mint b) { return (a.x - b.x < 0 ? a.x - b.x + MOD : a.x - b.x); }
    friend Mint operator -= (Mint& a, Mint b) { return a = (a - b); }

    friend Mint operator * (Mint a, Mint b) { return (long long)(a.x) * b.x % MOD; }
    friend Mint operator *= (Mint& a, Mint b) { return a = (a * b); }

    
    
    Mint inv() {
        return binPow(MOD - 2);
    }

    Mint binPow(long long n) {
        Mint res = 1, a = x;
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
    
    Mint() {}
    Mint(long long x_) : x((x_ < 0 ? x_ % MOD + MOD : x_ % MOD)) {}
};

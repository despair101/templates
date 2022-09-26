inline ll div_ceil(ll a, ll b) {
    if (b < 0) {
        b = -b;
        a = -a;
    }

    if (a >= 0) {
        return (a + b - 1) / b;
    } else {
        return a / b;
    }
}

struct Line {
    ll k;
    ll b;

    ll intersect(Line y) {
        assert(k != y.k && "EQUAL LINE COEFFS");
        return div_ceil(y.b - b, k - y.k);
    }

    ll operator()(int x) {
        return k * x + b;
    }
};

struct ConvexHull {
    vector<Line> v;
    vector<ll> p;

    void insert(Line li) {
        while (!v.empty() && v.back().intersect(li) <= p.back()) {
            v.pop_back();
            p.pop_back();
        }
        if (v.empty()) {
            p.push_back(0); //min X
        } else {
            p.push_back(v.back().intersect(li));
        }
        v.push_back(li);
    }

    ll getMin(int x) {
        return v[upper_bound(p.begin(), p.end(), x) - p.begin() - 1](x);
    }
};

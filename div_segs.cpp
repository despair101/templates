int div_floor(int a, int b) {
    return a / b;
}

int div_ceil(int a, int b) {
    return (a + b - 1) / b;
}

// floor(n / l) = x   =>   rx <= n   =>   r = floor(n / x)
vector<array<int, 3>> get_floors(int n) {
    vector<array<int, 3>> res;
    int l = 1;
    while (l <= n) {
        int x = div_floor(n, l);
        int r = div_floor(n, x);
        res.push_back({l, r, x});
        l = r + 1;
    }
    return res;
}

// ceil(n / l) = x   =>   r(x - 1) < n   =>   r = ceil(n, x - 1) - 1
vector<array<int, 3>> get_ceils(int n) {
    vector<array<int, 3>> res;
    int l = 1;
    while (l <= n) {
        int x = div_ceil(n, l);
        int r = (x - 1 > 0 ? div_ceil(n, x - 1) - 1 : n);
        res.push_back({l, r, x});
        l = r + 1;
    }
    return res;
}

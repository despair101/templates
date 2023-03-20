int div_floor(int a, int b) {
    return a / b;
}

int div_ceil(int a, int b) {
    return (a + b - 1) / b;
}

vector<tuple<int, int, int>> get_floors(int n) {
    vector<tuple<int, int, int>> res;
    int l = 1;
    while (l <= n) {
        int x = div_floor(n, l);
        int r = div_floor(n, x);
        res.emplace_back(l, r, x);
        l = r + 1;
    }
    return res;
}

vector<tuple<int, int, int>> get_ceils(int n) {
    vector<tuple<int, int, int>> res;
    int l = 1;
    while (l <= n) {
        int x = div_ceil(n, l);
        int r = (x - 1 > 0 ? div_ceil(n, x - 1) - 1 : n);
        res.emplace_back(l, r, x);
        l = r + 1;
    }
    return res;
}

// works for 1 <= l <= r <= 2^63-1

ll range_xor(ll l, ll r) {
    if (l == 1) {
        if (r % 4 == 0) {
            return r;
        } else if (r % 4 == 1) {
            return 1;
        } else if (r % 4 == 2) {
            return r + 1;
        } else {
            return 0;
        }
    }

    return range_xor(1, r) ^ range_xor(1, l - 1);
}

ll range_and(ll l, ll r) {
    ll res = 0;
    for (int i = 0; i <= __lg(l); ++i) {
        if ((l >> i & 1) && r / (1 << i) == l / (1 << i)) {
            res += (1 << i);
        }
    }
    return res;
}

ll range_or(ll l, ll r) {
    ll res = 0;
    for (int i = 0; i <= __lg(r); ++i) {
        if ((l >> i & 1) || r / (1 << i) != l / (1 << i)) {
            res += (1 << i);
        }
    }
    return res;
}

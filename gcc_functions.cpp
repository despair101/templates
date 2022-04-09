#ifdef DESPAIR_101
int __builtin_popcount(int x) {
    int cnt = 0;
    while (x) {
        cnt += (x & 1);
        x >>= 1;
    }
    return cnt;
}
int __builtin_popcountll(ll x) {
    int cnt = 0;
    while (x) {
        cnt += (x & 1);
        x >>= 1;
    }
    return cnt;
}
int __builtin_ctz(int x) {
    int cnt = 0;
    for (int i = 0; i <= 31; ++i, ++cnt) {
        if (1 & (x >> i)) break;
    }
    return cnt;
}
int __builtin_ctzll(ll x) {
    int cnt = 0;
    for (int i = 0; i <= 63; ++i, ++cnt) {
        if (1 & (x >> i)) break;
    }
    return cnt;
}
int __builtin_clz(int x) {
    int cnt = 0;
    for (int i = 31; i >= 0; --i, ++cnt) {
        if (1 & (x >> i)) break;
    }
    return cnt;
}
int __builtin_clzll(ll x) {
    int cnt = 0;
    for (int i = 63; i >= 0; --i, ++cnt) {
        if (1 & (x >> i)) break;
    }
    return cnt;
}
int __lg(ll x) {
    int cnt = 0;
    for (int i = 1; i < 63; ++i, ++cnt) {
        if ((1ll << i) > x) break;
    }
    return cnt;
}
#endif

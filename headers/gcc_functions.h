#pragma once

#include <cassert>

inline int __builtin_popcount(int x) {
    assert(x >= 0);
    int cnt = 0;
    while (x) {
        cnt += (x & 1);
        x >>= 1;
    }
    return cnt;
}

inline int __builtin_popcountll(long long x) {
    assert(x >= 0);
    int cnt = 0;
    while (x) {
        cnt += (x & 1);
        x >>= 1;
    }
    return cnt;
}

inline int __builtin_ctz(int x) {
    assert(x >= 0);
    int cnt = 0;
    for (int i = 0; i < 31; ++i, ++cnt) {
        if (x >> i & 1) break;
    }
    return cnt;
}

inline int __builtin_ctzll(long long x) {
    assert(x >= 0);
    int cnt = 0;
    for (int i = 0; i < 63; ++i, ++cnt) {
        if (x >> i & 1) break;
    }
    return cnt;
}

inline int __builtin_clz(int x) {
    assert(x >= 0);
    int cnt = 0;
    for (int i = 31; i >= 0; --i, ++cnt) {
        if (x >> i & 1) break;
    }
    return cnt;
}

inline int __builtin_clzll(long long x) {
    assert(x >= 0);
    int cnt = 0;
    for (int i = 63; i >= 0; --i, ++cnt) {
        if (x >> i & 1) break;
    }
    return cnt;
}

inline int __lg(long long x) {
    assert(x >= 0);
    int cnt = 0;
    for (int i = 1; i < 63; ++i, ++cnt) {
        if ((1ll << i) > x) break;
    }
    return cnt;
}

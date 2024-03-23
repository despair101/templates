#include <bits/stdc++.h>

#ifdef DESPAIR_101
#include "../debug_output.h"
#define dbg(x)                              \
    cerr << "\033[2;31m\n" << #x << ":\n "; \
    debug::print(x);                        \
    cerr << "\033[0m\n"
#define showTest(x) cerr << "_____Test #" << x << "_____\n"
#else
#define dbg(x)
#define showTest(x)
#endif

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
// #define int ll

template <class A>
inline int sz(const A& x) {
    return int(x.size());
}
template <class A>
inline bool umin(A& x, const A& y) {
    return x > y ? (x = y, true) : false;
}
template <class A>
inline bool umax(A& x, const A& y) {
    return x < y ? (x = y, true) : false;
}

void solve() {}

signed main() {
#ifdef DESPAIR_101
    freopen("inputik.txt", "r", stdin);
#endif
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int testsCnt = 1;
    // cin >> testsCnt;
    for (int curTest = 1; curTest <= testsCnt; ++curTest) {
        showTest(curTest);
        solve();
    }
}

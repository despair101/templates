#include "bits/stdc++.h"

#ifdef DESPAIR_101
#include "../debug_output.h"
#define dbg(x) cerr << "\n" << #x << ":\n "; debug::print(x); cerr << "\n"
#define showTest(x) cerr << "_____Test #" << x << "_____\n"
#else
#define dbg(x)
#define showTest(x)
#endif

using namespace std;

template <class A> inline bool umax(A &x, A const &y) {
    return x < y ? (x = y, true) : false;
}
template <class A> inline bool umin(A &x, A const &y) {
    return x > y ? (x = y, true) : false;
}

using ll = long long;
using ld = long double;

// #define int int64_t
#define sz(x) int((x).size())

void solve() {}

signed main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int testsCnt = 1;
    cin >> testsCnt;
    for (int curTest = 1; curTest <= testsCnt; ++curTest) {
        showTest(curTest);
        solve();
    }
}

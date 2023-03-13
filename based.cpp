#include "bits/stdc++.h"

#ifdef DESPAIR_101
#include "debug_output.h"
#define dbg(x) std::cerr << "\n" << #x << ":\n "; debug::print(x); std::cerr << "\n"
#define showTest(x) std::cerr << "_____Test #" << x << "_____\n"
#else
#define dbg(x)
#define showTest(x)
#endif

using namespace std;

template <class A>
bool umax(A& x, A y) { if (x >= y) return false; x = y; return true; }
template <class A>
bool umin(A& x, A y) { if (x <= y) return false; x = y; return true; }

using ll = long long;
using ld = long double;

// #define int int64_t
#define sz(x) int((x).size())

void solve() {
}

signed main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);
    std::cout << std::fixed << std::setprecision(20);

    int testsCnt = 1;
    std::cin >> testsCnt;
    for (int curTest = 1; curTest <= testsCnt; ++curTest) {
        showTest(curTest);
        solve();
    }
}

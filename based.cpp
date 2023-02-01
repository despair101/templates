#ifndef DESPAIR_101
#pragma GCC optimize("O3")
#endif

#include "bits/stdc++.h"
using namespace std;

#ifdef DESPAIR_101
#include "debug_output.h"
#include "gcc_functions.h"
#define dbg(x) std::cerr << "\n" << #x << ":\n "; debug::print(x); std::cerr << "\n"
#define showTest(x) std::cerr << "_____Test #" << x << "_____\n"
#else
#define dbg(x)
#define showTest(x)
#endif

template<class A>
bool umax(A& x, A y) { if (y > x) { x = y; return true; } return false; }
template<class A>
bool umin(A& x, A y) { if (y < x) { x = y; return true; } return false; }

std::mt19937 rnd(101);

typedef long long ll;
typedef long double ld;

// #define int int64_t
#define sz(x) int(x.size())

void solve() {
}

signed main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);
    std::cout << std::fixed << std::setprecision(20);

    int testsCnt = 1;
    // std::cin >> testsCnt;
    for (int curTest = 1; curTest <= testsCnt; ++curTest) {
        showTest(curTest);
        solve();
    }
}

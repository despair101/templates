#include "bits/stdc++.h"

using namespace std;

#ifdef DESPAIR_101
#include "debug_output.h"
#include "gcc_functions.h" 
#define dbg(a) std::cerr << "\n" << #a << ":\n "; debug::print(a); std::cerr << "\n"
#define showTest(t) std::cerr << "_____Test #" << t << "_____\n"
#else
#define dbg(a)
#define showTest(t)
#endif

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef long double ld;

template<class A> inline bool umax(A& x, A y) { if (y > x) { x = y; return true; } return false; }
template<class A> inline bool umin(A& x, A y) { if (y < x) { x = y; return true; } return false; }

std::mt19937 rnd(101);

//#define int ll
#define sz(a) int(a.size())

void solve() {
    uint a;

}

signed main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);
    std::cout << std::fixed << std::setprecision(20);

    int testsCnt = 1;
    //std::cin >> testsCnt;
    for (int curTest = 1; curTest <= testsCnt; ++curTest) {
        showTest(curTest);
        solve();
    }
}

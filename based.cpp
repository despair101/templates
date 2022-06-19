#define _USE_MATH_DEFINES

#include "bits/stdc++.h"

using namespace std;

#ifdef DESPAIR_101
#include "debug_output.h"
#include "gcc_functions.h"
#define dbg(a) cerr << "\n" << #a << ":\n "; print(a); cerr << "\n"
#else
#define dbg(a)
#endif

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

template<typename A> inline bool umax(A& x, A y) { if (y > x) { x = y; return true; } return false; }
template<typename A> inline bool umin(A& x, A y) { if (y < x) { x = y; return true; } return false; }

//#define int ll
#define sz(a) int(a.size())

mt19937 rnd(101);

void solve() {
    int a, b;
    cin >> a >> b;
}

signed main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int testsLimit = 1;
    //cin >> testsLimit;
    for (int test = 1; test <= testsLimit; ++test) {
        cerr << "_____Test #" << test << "_____\n";
        solve();
    }
}

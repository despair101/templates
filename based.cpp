#include "bits/stdc++.h"

using namespace std;

#ifdef DESPAIR_101
#include "debug_output.h"
#include "gcc_functions.h" 
#define dbg(a) cerr << "\n" << #a << ":\n "; print(a); cerr << "\n"
#define showTest(t) cerr << "_____Test #" << t << "_____\n"
#else
#define dbg(a)
#define showTest(test)
#endif

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

template<typename A> inline bool umax(A& x, A y) { if (y > x) { x = y; return true; } return false; }
template<typename A> inline bool umin(A& x, A y) { if (y < x) { x = y; return true; } return false; }

//#define int ll
#define sz(a) int(a.size())

void solve() {
}   

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

#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES

#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <deque>
#include <random>
#include <iomanip>
#include <cassert>
#include <numeric>
#include <string>
#include <array>
#include <bitset>
#include <cstring>
#include <climits>

using namespace std;

#ifdef DESPAIR_101
#include "debug_output.h"
#include "gcc_functions.h"
#else
#define cerr if (false) cerr
#define print(a)
#endif

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

template<typename A> inline bool umax(A& x, A y) { if (y > x) { x = y; return true; } return false; }
template<typename A> inline bool umin(A& x, A y) { if (y < x) { x = y; return true; } return false; }

//#define int ll
#define sz(a) int(a.size())
#define dbg(a) cerr << "\n" << #a << ":\n "; print(a); cerr << "\n"

mt19937 rnd(101);

void solve() {
}

signed main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int testsLimit = 1;
    cin >> testsLimit;
    for (int test = 1; test <= testsLimit; ++test) {
        cerr << "_____Test #" << test << "_____\n";
        solve();
    }
}

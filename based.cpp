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

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

#ifndef DESPAIR_101
#define cerr if (false) cerr
#endif

//debug output
template<class A> void print(A a);
template<class A, class B> void print(pair<A, B> a);
template<class A> void print(set<A> a);
template<class A> void print(multiset<A> a);
template<class A, class B> void print(map<A, B> a);
template<class A> void print(unordered_set<A> a);
template<class A> void print(unordered_multiset<A> a);
template<class A, class B> void print(unordered_map<A, B> a);
template<class A> void print(vector<A> a);
template<class A> void print(deque<A> a);
template<class A> void print(A a) { cerr << a; }
template<class A, class B> void print(pair<A, B> a) { cerr << "("; print(a.first); cerr << " "; print(a.second); cerr << ")"; }
template<class A> void print(vector<A> a) { for (A b : a) { print(b); cerr << " "; }; cerr << "\n"; }
template<class A> void print(deque<A> a) { for (A b : a) { print(b); cerr << " "; }; cerr << "\n"; }
template<class A> void print(set<A> a) { for (A b : a) { print(b); cerr << " "; }; cerr << "\n"; }
template<class A> void print(multiset<A> a) { for (A b : a) { print(b); cerr << " "; }; cerr << "\n"; }
template<class A, class B> void print(map<A, B> a) { for (pair<A, B> b : a) { print(b); cerr << ' '; }; cerr << "\n"; }
template<class A> void print(unordered_set<A> a) { for (A b : a) { print(b); cerr << " "; }; cerr << "\n"; }
template<class A> void print(unordered_multiset<A> a) { for (A b : a) { print(b); cerr << " "; }; cerr << "\n"; }
template<class A, class B> void print(unordered_map<A, B> a) { for (pair<A, B> b : a) { print(b); cerr << " "; }; cerr << "\n"; }

//#define int ll
#define sz(a) int(a.size())
#define dbg(a) cerr << "\n" << #a << ":\n "; print(a); cerr << "\n"

mt19937 rnd(101);

const int INF = int(1e9) + 7;

void solve() {
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

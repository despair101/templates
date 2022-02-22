//blog: vk.com/power_of_symmetry

//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,tune=native")

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

using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

#ifndef DESPAIR_101
#define cerr if (false) cerr
#endif

//debug output
template<class A>
void print(A a) { cerr << a; }
template<class A, class B>
void print(pair<A, B> a) { cerr << '(' << a.first << ' ' << a.second << ')'; }
template<class A, class B, class C>
void print(tuple<A, B, C> a) { cerr << '(' << get<0>(a) << ' ' << get<1>(a) << ' ' << get<2>(a) << ')'; }
template<class A>
void print(set<A> a) { for (A b : a) { print(b); cerr << ' '; }; cerr << '\n'; }
template<class A>
void print(multiset<A> a) { for (A b : a) { print(b); cerr << ' '; }; cerr << '\n'; }
template<class A, class B>
void print(map<A, B> a) { for (pair<A, B> b : a) { print(b); cerr << ' '; }; cerr << '\n'; }
template<class A>
void print(unordered_set<A> a) { for (A b : a) { print(b); cerr << ' '; }; cerr << '\n'; }
template<class A, class B>
void print(unordered_map<A, B> a) { for (pair<A, B> b : a) { print(b); cerr << ' '; }; cerr << '\n'; }
template<class A>
void print(vector<A> a) { for (A b : a) { print(b); cerr << ' '; }; cerr << '\n'; }
template<class A>
void print(deque<A> a) { for (A b : a) { print(b); cerr << ' '; }; cerr << '\n'; }

//#define int ll
#define sz(a) int(a.size())
#define dbg(a) cerr << '\n' << #a << ":\n "; print(a); cerr << '\n'

mt19937 rnd(101);

const int INF = int(1e9) + 7;

#ifdef DESPAIR_101
int __builtin_popcount(int x) {
  int cnt = 0;
  while (x) {
    cnt += (x & 1);
    x >>= 1;
  }
  return cnt;
}
int __builtin_popcountll(ll x) {
  int cnt = 0;
  while (x) {
    cnt += (x & 1);
    x >>= 1;
  }
  return cnt;
}
int __builtin_ctz(int x) {
  int cnt = 0;
  for (int i = 0; i <= 31; ++i, ++cnt) {
    if (1 & (x >> i)) break;
  }
  return cnt;
}
int __builtin_ctzll(ll x) {
  int cnt = 0;
  for (int i = 0; i <= 63; ++i, ++cnt) {
    if (1 & (x >> i)) break;
  }
  return cnt;
}
int __builtin_clz(int x) {
  int cnt = 0;
  for (int i = 31; i >= 0; --i, ++cnt) {
    if (1 & (x >> i)) break;
  }
  return cnt;
}
int __builtin_clzll(ll x) {
  int cnt = 0;
  for (int i = 63; i >= 0; --i, ++cnt) {
    if (1 & (x >> i)) break;
  }
  return cnt;
}
int __lg(ll x) {
  int cnt = 0;
  for (int i = 1; i < 63; ++i, ++cnt) {
    if ((1ll << i) > x) break;
  }
  return cnt;
}
#endif

void solve() {
}

signed main() {
  cin.tie(nullptr)->ios::sync_with_stdio(false);
  cout << fixed << setprecision(20);

  int tests_lim = 1;
  //cin >> tests_lim;
  for (int test = 1; test <= tests_lim; ++test) {
    cerr << "_____Test #" << test << "_____\n";
    solve();
  }
}

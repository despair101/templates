#pragma once

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

template<class A> void print(A a);
template<class A, class B> void print(pair<A, B> a);
template<class A, class B> void print(set<A, B> a);
template<class A, class B> void print(multiset<A, B> a);
template<class A, class B, class C> void print(map<A, B, C> a);
template<class A> void print(unordered_set<A> a);
template<class A> void print(unordered_multiset<A> a);
template<class A, class B> void print(unordered_map<A, B> a);
template<class A> void print(vector<A> a);
template<class A> void print(deque<A> a);
template<class A> void print(A a) { cerr << a; }
template<class A, class B> void print(pair<A, B> a) { cerr << "("; print(a.first); cerr << " "; print(a.second); cerr << ")"; }
template<class A> void print(vector<A> a) { for (A b : a) { print(b); cerr << " "; }; cerr << "\n"; }
template<class A> void print(deque<A> a) { for (A b : a) { print(b); cerr << " "; }; cerr << "\n"; }
template<class A, class B> void print(set<A, B> a) { for (A b : a) { print(b); cerr << " "; }; cerr << "\n"; }
template<class A, class B> void print(multiset<A, B> a) { for (A b : a) { print(b); cerr << " "; }; cerr << "\n"; }
template<class A, class B, class C> void print(map<A, B, C> a) { for (pair<A, B> b : a) { print(b); cerr << ' '; }; cerr << "\n"; }
template<class A> void print(unordered_set<A> a) { for (A b : a) { print(b); cerr << " "; }; cerr << "\n"; }
template<class A> void print(unordered_multiset<A> a) { for (A b : a) { print(b); cerr << " "; }; cerr << "\n"; }
template<class A, class B> void print(unordered_map<A, B> a) { for (pair<A, B> b : a) { print(b); cerr << " "; }; cerr << "\n"; }

#pragma once

namespace debug {
    template<class A> void print(A a);
    template<class A, class B> void print(std::pair<A, B> a);
    template<class A, class B, class C> void print(std::tuple<A, B, C> a);
    template<class A, class B> void print(std::set<A, B> a);
    template<class A, class B> void print(std::multiset<A, B> a);
    template<class A, class B, class C> void print(std::map<A, B, C> a);
    template<class A> void print(std::unordered_set<A> a);
    template<class A> void print(std::unordered_multiset<A> a);
    template<class A, class B> void print(std::unordered_map<A, B> a);
    template<class A> void print(std::vector<A> a);
    template<class A> void print(std::deque<A> a);
    template<class A> void print(A a) { std::cerr << a; }

    template<class A, class B> void print(std::pair<A, B> a) {
        std::cerr << "("; print(a.first); std::cerr << " "; print(a.second); std::cerr << ")";
    }
    template<class A, class B, class C> void print(std::tuple<A, B, C> a) {
        std::cerr << '(' << get<0>(a) << ' ' << get<1>(a) << ' ' << get<2>(a) << ')';
    }
    template<class A> void print(std::vector<A> a) {
        for (A b : a) { print(b); std::cerr << " "; }; std::cerr << "\n";
    }
    template<class A> void print(std::deque<A> a) {
        for (A b : a) { print(b); std::cerr << " "; }; std::cerr << "\n";
    }
    template<class A, class B> void print(std::set<A, B> a) {
        for (A b : a) { print(b); std::cerr << " "; }; std::cerr << "\n";
    }
    template<class A, class B> void print(std::multiset<A, B> a) {
        for (A b : a) { print(b); std::cerr << " "; }; std::cerr << "\n";
    }
    template<class A, class B, class C> void print(std::map<A, B, C> a) {
        for (std::pair<A, B> b : a) { print(b); std::cerr << ' '; }; std::cerr << "\n";
    }
    template<class A> void print(std::unordered_set<A> a) {
        for (A b : a) { print(b); std::cerr << " "; }; std::cerr << "\n";
    }
    template<class A> void print(std::unordered_multiset<A> a) {
        for (A b : a) { print(b); std::cerr << " "; }; std::cerr << "\n";
    }
    template<class A, class B> void print(std::unordered_map<A, B> a) {
        for (std::pair<A, B> b : a) { print(b); std::cerr << " "; }; std::cerr << "\n";
    }
}

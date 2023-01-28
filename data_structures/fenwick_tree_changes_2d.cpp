template<class A>
struct Query {
    int type;
    int i;
    A v;
    int l;
    int r;
    A mi;
    A ma;
};

template<class A> 
class FenwickTree {
    int size;
    vector<A> t;

public:
    A get(int l, int r) {
        if (l > r) return 0;
        A res = 0;
        for (int i = r; i >= 0; i &= i + 1, --i) res += t[i];
        for (int i = l - 1; i >= 0; i &= i + 1, --i) res -= t[i];
        return res;
    }

    void add(int ind, A val) {
        for (int i = ind; i < size; i |= i + 1) t[i] += val;
    }

    FenwickTree() = default;
    explicit FenwickTree(int n) : size(n), t(size) {}
};

template<class A>
class FenwickTreeChanges2D {
    int size;
    vector<A> x;
    vector<vector<A>> crd;
    vector<FenwickTree<int>> t;

public:
    int get(int l, int r, A mi, A ma) {
        if (l > r) return 0;
        int res = 0;
        for (int i = r; i >= 0; i &= i + 1, --i) {
            int lo = lower_bound(crd[i].begin(), crd[i].end(), mi) - crd[i].begin();
            int hi = lower_bound(crd[i].begin(), crd[i].end(), ma) - crd[i].begin();
            res += t[i].get(lo, hi);
        }
        for (int i = l - 1; i >= 0; i &= i + 1, --i) {
            int lo = lower_bound(crd[i].begin(), crd[i].end(), mi) - crd[i].begin();
            int hi = lower_bound(crd[i].begin(), crd[i].end(), ma) - crd[i].begin();
            res -= t[i].get(lo, hi);            
        }
        return res;
    }

    void change(int ind, A val) {
        for (int i = ind; i < size; i |= i + 1) {
            t[i].add(lower_bound(crd[i].begin(),
                crd[i].end(), x[ind]) - crd[i].begin(), -1);
        }
        x[ind] = val;
        for (int i = ind; i < size; i |= i + 1) {
            t[i].add(lower_bound(crd[i].begin(),
                crd[i].end(), x[ind]) - crd[i].begin(), 1);
        } 
    }

    FenwickTreeChanges2D() = default;
    explicit FenwickTreeChanges2D(const vector<A>& a,
        const vector<Query<A>>& q) : size(a.size()), x(a), crd(size), t(size) {
        vector<pair<int, int>> changes;
        vector<tuple<int, int, A, A>> queries;

        for (auto [type, i, v, l, r, mi, ma] : q) {
            if (type) {
                changes.emplace_back(i, v);
            } else {
                queries.emplace_back(l, r, mi, ma);
            }
        }

        for (auto [ind, val] : changes) {
            for (int i = ind; i < size; i |= i + 1) {
                crd[i].push_back(val);
            }
        }
        for (auto [l, r, mi, ma] : queries) {
            for (int i = r; i >= 0; i &= i + 1, --i) {
                crd[i].push_back(mi);
                crd[i].push_back(ma);
            }
            for (int i = l - 1; i >= 0; i &= i + 1, --i) {
                crd[i].push_back(mi);
                crd[i].push_back(ma);
            }
        }
        for (int i = 0; i < size; ++i) {
            for (int j = i; j < size; j |= j + 1) {
                crd[j].push_back(x[i]);
            }
        }

        for (int i = 0; i < size; ++i) {
            sort(crd[i].begin(), crd[i].end());
            crd[i].erase(unique(crd[i].begin(), crd[i].end()), crd[i].end());
            t[i] = FenwickTree<int>(crd[i].size());
        }

        for (int i = 0; i < size; ++i) {
            for (int j = i; j < size; j |= j + 1) {
                t[j].add(lower_bound(crd[j].begin(),
                    crd[j].end(), x[i]) - crd[j].begin(), 1);
            }
        }
    }
};

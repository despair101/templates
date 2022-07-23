struct Node {
    int min;
    int max;
    int l;
    int r;
};
 
struct PersistentSegmentTree {
    int size;
 
    vector<Node> t;
    vector<int> roots;
 
    Node newNode(int x) {
        return t[x];
    }
 
    pair<int, int> compose(pair<int, int> fi, pair<int, int> se) {
        return { std::min(fi.first, se.first), std::max(fi.second, se.second) };
    }
 
    int change(int i, int v, int x, int lx, int rx) {
        t.push_back(newNode(x));
        int res = sz(t) - 1;
        if (rx - lx == 1) {
            t[res].min = v;
            t[res].max = v;
            return res;
        }
        int mx = (lx + rx) / 2;
        if (i < mx) {
            t[res].l = change(i, v, t[x].l, lx, mx);
        } else {
            t[res].r = change(i, v, t[x].r, mx, rx);
        }
        t[res].min = min(t[t[res].l].min, t[t[res].r].min);
        t[res].max = max(t[t[res].l].max, t[t[res].r].max);
        return res;
    }
 
    pair<int, int> get(int l, int r, int x, int lx, int rx) {
        if (lx >= l && rx <= r) return { t[x].min, t[x].max };
        if (lx >= r || rx <= l) return { INT_MAX, INT_MIN };
        int mx = (lx + rx) / 2;
        return compose(get(l, r, t[x].l, lx, mx), get(l, r, t[x].r, mx, rx));
    }
 
public:
    void change(int i, int v) {
        int ind = change(i, v, roots.back(), 0, size);
        roots.push_back(ind);
    }
 
    pair<int, int> get(int l, int r, int op) {
        return get(l, r, roots[op], 0, size);
    }
    
    explicit PersistentSegmentTree() {}
    explicit PersistentSegmentTree(int n_) : size(n) {
        t.push_back(Node{ INT_MAX, INT_MIN, 0, 0 });
        roots.push_back(0);
    }
};

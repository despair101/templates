struct Node {
    int sum;
    int l;
    int r;
};

class PersistentSegmentTree {
    const int N = (1 << 24);
    vector<Node> t;
    vector<int> roots;

    Node newNode(int x) {
        return t[x];
    }

    int add(int i, int v, int x, int lx, int rx) {
        t.push_back(newNode(x));
        t.back().sum += v;
        int res = sz(t) - 1;
        if (rx - lx == 1) return res;
        int mx = (lx + rx) / 2;
        if (i < mx) {
            t[res].l = add(i, v, t[x].l, lx, mx);
        } else {
            t[res].r = add(i, v, t[x].r, mx, rx);
        }
        return res;
    }

    int get(int l, int r, int x, int lx, int rx) {
        if (lx >= l && rx <= r) return t[x].sum;
        if (lx >= r || rx <= l) return 0;
        int mx = (lx + rx) / 2;
        return get(l, r, t[x].l, lx, mx) + get(l, r, t[x].r, mx, rx);
    }


    int getk(int k, int x1, int x2, int lx, int rx) {
        if (rx - lx == 1) return lx;
        int mx = (lx + rx) / 2;
        if (t[t[x2].l].sum - t[t[x1].l].sum >= k) {
            return getk(k, t[x1].l, t[x2].l, lx, mx);
        } else {
            return getk(k - (t[t[x2].l].sum - t[t[x1].l].sum), t[x1].r, t[x2].r, mx, rx);
        }
    }

public:
    PersistentSegmentTree() {
        t.reserve(N);
        roots.reserve(450000);
        t.push_back(Node{ 0, 0, 0 });
        roots.push_back(0);
    }

    void add(int i, int v) {
        int ind = add(i, v, roots.back(), 0, N);
        roots.push_back(ind);
    }

    int get(int l, int r, int op) {
        return get(l, r, roots[op], 0, N);
    }

    int getk(int k, int x1, int x2) {
        return getk(k, roots[x1], roots[x2], 0, N);
    }
};

struct Node {
    int mx;
    int mxp;
    int mn;
    int mnp;
};

class SegmentTree {
    const int INF = 1e9; //TODO
    
    int size;
    vector<Node> t;
    vector<int> add;
 
    Node compose(Node fi, Node se, int pl) {
        Node res = {
            max(fi.mx, se.mx) + pl,
            (fi.mx >= se.mx ? fi.mxp : se.mxp),
            min(fi.mn, se.mn) + pl,
            (fi.mn <= se.mn ? fi.mnp : se.mnp),
        };
        return res;
    }
 
    void build(int x, int lx, int rx) {
        if (rx - lx == 1) {
            t[x] = { 0, lx, 0, lx, lx };
        } else {
            int mx = (lx + rx) / 2;
            build(2 * x + 1, lx, mx);
            build(2 * x + 2, mx, rx);
            t[x] = compose(t[2 * x + 1], t[2 * x + 2], add[x]);
        }
    }
 
    void modify(int l, int r, int v, int x, int lx, int rx) {
        if (lx >= r || rx <= l) return;
        if (lx >= l && rx <= r) {
            t[x].mx += v;
            t[x].mn += v;
            add[x] += v;
        } else {
            int mx = (lx + rx) / 2;
            modify(l, r, v, 2 * x + 1, lx, mx);
            modify(l, r, v, 2 * x + 2, mx, rx);
            t[x] = compose(t[2 * x + 1], t[2 * x + 2], add[x]);
        }
    }
    
    Node get(int l, int r, int x, int lx, int rx) {
        if (lx >= r || rx <= l) return { -INF, N, INF, N, -1 };
        if (lx >= l && rx <= r) return t[x];
        int mx = (lx + rx) / 2;
        return compose(get(l, r, 2 * x + 1, lx, mx), get(l, r, 2 * x + 2, mx, rx), add[x]);
    }
    
public:
    void modify(int l, int r, int v) {
        modify(l, r, v, 0, 0, size);
    }
    
    Node get(int l, int r) {
        return get(l, r, 0, 0, size);
    }
    
    explicit SegmentTree() {}
    explicit SegmentTree(int n) : size(n) {
        t.resize(4 * size);
        add.assign(4 * size, 0);
        build(0, 0, size);
    }
};

class SegmentTree {
    struct Node {
        long long sum;
        long long add;
        
        Node() : sum(0), add(0) {}
    };
    
    int size;
    std::vector<Node> t;
 
    void modify(int l, int r, int v, int x, int lx, int rx) {
        if (lx >= r || rx <= l) return;
        if (lx >= l && rx <= r) {
            t[x].sum += v * (rx - lx);
            t[x].add += v;
        } else {
            int mx = (lx + rx) / 2;
            modify(l, r, v, 2 * x + 1, lx, mx);
            modify(l, r, v, 2 * x + 2, mx, rx);
            t[x].sum = t[2 * x + 1].sum + t[2 * x + 2].sum + t[x].add * (rx - lx);
        }
    }
 
    long long get(int l, int r, int x, int lx, int rx, int dop) {
        if (lx >= r || rx <= l) return 0;
        if (lx >= l && rx <= r) return t[x].sum + dop * (rx - lx);
        int mx = (lx + rx) / 2;
        return get(l, r, 2 * x + 1, lx, mx, dop + t[x].add) + get(l, r, 2 * x + 2, mx, rx, dop + t[x].add);
    }
 
public:
    void modify(int l, int r, int v) {
        modify(l, r, v, 0, 0, size);
    }
 
    long long get(int l, int r) {
        return get(l, r, 0, 0, size, 0);
    }
    
    SegmentTree() = default;
    explicit SegmentTree(int n) : size(n), t(4 * size) {}
};

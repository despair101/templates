int div_ceil(int a, int b) {
    if (b < 0) {
        a = -a;
        b = -b;
    }

    if (a >= 0) {
        return (a + b - 1) / b;
    } else {
        return a / b;
    }
}

struct Line {
    int k;
    int b;

    ld intersect(Line l) {
        return ld(l.b - b) / (k - l.k);
    }

    int operator()(int x) {
        return k * x + b;
    }

    bool operator < (Line l) const {
        return make_pair(k, b) < make_pair(l.k, l.b);
    }
};

const int LX = -1e5, RX = 1e5;

struct LiChaoTree {
    struct Node {
        Line li;
        Node* l = nullptr;
        Node* r = nullptr;

        Node(Line li_) : li(li_) {}
    };

    Node* root = nullptr;

    int getMin(Node* t, int i, int lx, int rx) {
        if (!t) return LLONG_MAX;
        int mx = div_ceil(lx + rx, 2);
        if (i < mx) {
            return min(t->li(i), getMin(t->l, i, lx, mx - 1));
        } else {
            return min(t->li(i), getMin(t->r, i, mx, rx));
        }
    }
    int getMin(int i) {
        return getMin(root, i, LX, RX);
    }

    Node* insert(Node* t, Line a, int lx, int rx) {
        if (!t) {
            t = new Node(a);
        } else {
            int mx = div_ceil(lx + rx, 2);
            if (t->li(mx) > a(mx)) {
                swap(t->li, a);
            }
            if (lx < rx) {
                if (a.k > t->li.k) {
                    t->l = insert(t->l, a, lx, mx - 1);
                } else if (a.k < t->li.k) {
                    t->r = insert(t->r, a, mx, rx);
                }
            }
        }
        return t;
    }
    void insert(Line a) {
        root = insert(root, a, LX, RX);
    }
};

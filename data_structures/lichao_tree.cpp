struct Line {
    int k;
    int b;

    int operator()(int x) {
        return k * x + b;
    }
};

const int LX = -1e5, RX = 1e5;

struct LiChaoTree {
    struct Node {
        Line line;
        Node* l;
        Node* r;

        Node() = default;
        Node(Line l) : line(l), l(nullptr), r(nullptr) {}
    };

    Node* root = nullptr;

    int getMin(Node* t, int i, int lx, int rx) {
        if (!t) return INT_MAX;
        int mx = (lx + rx) / 2;
        if (i < mx) {
            return std::min(t->line(i), getMin(t->l, i, lx, mx - 1));
        } else {
            return std::min(t->line(i), getMin(t->r, i, mx, rx));
        }
    }
    int getMin(int i) {
        return getMin(root, i, LX, RX);
    }

    Node* insert(Node* t, Line a, int lx, int rx) {
        if (!t) {
            t = new Node(a);
        } else {
            int mx = (lx + rx) / 2;
            if (t->line(mx) > a(mx)) {
                std::swap(t->line, a);
            }
            if (lx < rx) {
                if (a.k > t->line.k) {
                    t->l = insert(t->l, a, lx, mx - 1);
                } else if (a.k < t->line.k) {
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

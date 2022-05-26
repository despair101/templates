//be careful with data types!

struct Node {
    int x;
    int cnt;
    int dp;
    int y;
    Node* l;
    Node* r;

    Node(int x_, int cnt_ = 1) : x(x_), cnt(1), dp(1), y(rnd()), l(nullptr), r(nullptr) {}
};

struct kok {
    int bebra;
    int sus;
};

void relax(Node* a) {
    if (!a) return;
    a->dp = a->cnt;
    if (a->l) a->dp += a->l->dp;
    if (a->r) a->dp += a->r->dp;
}

Node* merge(Node* a, Node* b) {
    if (!a) return b;
    if (!b) return a;

    if (a->y > b->y) {
        a->r = merge(a->r, b);
        relax(a);
        return a;
    } else {
        b->l = merge(a, b->l);
        relax(b);
        return b;
    }
}

// < >=
pair<Node*, Node*> split(Node* a, int v) {
    if (!a) return { nullptr, nullptr };

    if (a->x < v) {
        auto [t1, t2] = split(a->r, v);
        a->r = t1;
        relax(a);
        return { a, t2 };
    } else {
        auto [t1, t2] = split(a->l, v);
        a->l = t2;
        relax(a);
        return { t1, a };
    }
}

Node* insert(Node* a, int v, int c = 1) {
    auto [t1, t2] = split(a, v);
    auto [t21, t22] = split(t2, v + 1);
    if (t21) {
        t21->cnt += c;
        relax(t21);
    } else {
        t21 = new Node(v, c);
    }
    return merge(t1, merge(t21, t22));
}

Node* erase(Node* a, int v, int c = 1) {
    auto [t1, t2] = split(a, v);
    auto [t21, t22] = split(t2, v + 1);
    if (t21 && t21->cnt > c) {
        t21->cnt -= c;
        relax(t21);
        return merge(t1, merge(t21, t22));
    } else {
        delete t21;
        return merge(t1, t22);
    }
}

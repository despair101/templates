struct Line {
    ll k, b;
 
    Line(ll k_, ll b_) : k(k_), b(b_) {}
 
    friend ld operator&(Line A, Line B) {
        return ld(B.b - A.b) / (A.k - B.k);
    }
    ll operator()(ll x) {
        return k * x + b;
    }
    //k1x + b1 = k2x + b2
    //x(k1 - x2) = b2-b1
};
 
struct Node {
    Line line;
    Node* l;
    Node* r;
 
    Node(Line line_) : line(line_), l(nullptr), r(nullptr) {};
};
 
void insert(Node* t, Line line, int lx = 0, int rx = 1e5) {
    int mx = (lx + rx) / 2;
    if (line(mx) < t->line(mx)) swap(t->line, line);
    if (lx == rx || line.k == t->line.k) return;
    ll i = (line & t->line);
    if (i < mx) {
        if (!t->l) t->l = new Node(line);
        insert(t->l, line, lx, mx);
    } else if (i > mx) {
        if (!t->r) t->r = new Node(line);
        insert(t->r, line, mx + 1, rx);
    }
}
 
ll get(Node* t, int x, int lx = 0, int rx = 1e5) {
    ll res = t->line(x);
    int mx = (lx + rx) / 2;
    if (lx == rx) return res;
    if (x <= mx && t->l) res = min(res, get(t->l, x, lx, mx));
    if (x > mx && t->r) res = min(res, get(t->r, x, mx + 1, rx));
    return res;
}

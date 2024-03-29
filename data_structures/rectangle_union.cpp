//coordinates should be nonnegative

const long long LX = 0, RX = (1ll << 31);

struct Node {
    int min_v;
    int add;
    long long cnt;
    Node* l;
    Node* r;

    Node() = default;
    explicit Node(long long lx, long long rx) : min_v(0), add(0), cnt(rx - lx), l(nullptr), r(nullptr) {}
    ~Node() {
        if (l) delete l;
        if (r) delete r;
    }
};

void relax(Node* nd) {
    nd->min_v = std::min(nd->l->min_v, nd->r->min_v);
    nd->cnt = 0;
    if (nd->l->min_v == nd->min_v) nd->cnt += nd->l->cnt;
    if (nd->r->min_v == nd->min_v) nd->cnt += nd->r->cnt;
    nd->min_v += nd->add;
}

void add(long long l, long long r, int v, Node* nd, long long lx, long long rx) {
    if (lx >= r || rx <= l) return;
    if (lx >= l && rx <= r) {
        nd->min_v += v;
        nd->add += v;
    } else {
        long long mx = (lx + rx) / 2;
        if (!nd->l) nd->l = new Node(lx, mx);
        if (!nd->r) nd->r = new Node(mx, rx);
        add(l, r, v, nd->l, lx, mx);
        add(l, r, v, nd->r, mx, rx);
        relax(nd);
    }
}

struct Rectangle {
    long long x1;
    long long y1;
    long long x2;
    long long y2;
};

long long get_rectangles_union(std::vector<Rectangle>& v) {
    struct Event {
        long long x;
        long long y1;
        long long y2;
        int type;
    };

    std::vector<Event> vec(2 * v.size());
    for (int i = 0; i < v.size(); ++i) {
        vec[2 * i] = { v[i].x1, v[i].y1, v[i].y2, 1 };
        vec[2 * i + 1] = { v[i].x2, v[i].y1, v[i].y2, -1 };
    }

    //v.clear();
    //v.shrink_to_fit();

    sort(vec.begin(), vec.end(), [&](const Event& a, const Event& b) {
        return a.x < b.x;
    });

    Node* tree = new Node(LX, RX);
    long long area = 0;

    for (int i = 0; i + 1 < vec.size(); ++i) {
        add(vec[i].y1, vec[i].y2, vec[i].type, tree, LX, RX);
        area += (vec[i + 1].x - vec[i].x) * (RX - LX - tree->cnt);
    }

    delete tree;
    
    return area;
}

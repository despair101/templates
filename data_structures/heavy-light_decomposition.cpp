//TODO
class SegmentTree {
    int size;
    vector<int> t;

    void change(int i, int v, int x, int lx, int rx) {
        if (rx - lx == 1) {
            t[x] = v;
        } else {
            int mx = (lx + rx) / 2;
            if (i < mx) {
                change(i, v, 2 * x + 1, lx, mx);
            } else {
                change(i, v, 2 * x + 2, mx, rx);
            }
            t[x] = max(t[2 * x + 1], t[2 * x + 2]);
        }
    }

    int get(int l, int r, int x, int lx, int rx) {
        if (lx >= l && rx <= r) return t[x];
        if (lx >= r || rx <= l) return INT_MIN;
        int mx = (lx + rx) / 2;
        return max(get(l, r, 2 * x + 1, lx, mx), get(l, r, 2 * x + 2, mx, rx));
    }

public:
    void change(int i, int v) {
        change(i, v, 0, 0, size);
    }

    int get(int l, int r) {
        return get(l, r, 0, 0, size);
    }

    SegmentTree() {}
    SegmentTree(int n) : size(n) {
        t.resize(4 * size);
    }
};

const int N = int(1e5) + 1; //TODO
int de[N], si[N], tin[N], up[N], pa[N], t;
vector<int> g[N], euler;

class HLD {
    SegmentTree st;

    void preDfs(int u, int p) {
        si[u] = 1;
        for (int v : g[u]) {
            if (v != p) {
                de[v] = de[u] + 1;
                pa[v] = u;
                preDfs(v, u);
                si[u] += si[v];
            }
        }
        for (int& v : g[u]) {
            if (v == p) {
                swap(v, g[u].back());
            } else if (si[v] > si[g[u].front()]) {
                swap(v, g[u].front());
            }
        }
    }

    void buildDfs(int u, int p) {
        tin[u] = t++;
        euler.push_back(u);
        for (int v : g[u]) {
            if (v == p) continue;
            if (v == g[u].front()) {
                up[v] = up[u];
            } else {
                up[v] = v;
            }
            buildDfs(v, u);
        }
    }

public:
    void change(int u, int val) {
        st.change(tin[u], val);
    }

    int get(int u, int v) {
        int ans = INT_MIN;
        while (up[u] != up[v]) {
            if (de[up[u]] < de[up[v]]) swap(u, v);
            umax(ans, st.get(tin[up[u]], tin[u] + 1));
            u = pa[up[u]];
        }
        if (de[u] < de[v]) swap(u, v);
        umax(ans, st.get(tin[v], tin[u] + 1));
        return ans;
    }
    
    HLD() {
        preDfs(0, -1);
        buildDfs(0, -1);
        st = SegmentTree(sz(euler));
    }
};

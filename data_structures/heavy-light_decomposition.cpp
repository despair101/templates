class SegmentTree {
    int size;
    vector<int> t;
 
    void add(int i, int v, int x, int lx, int rx) {
        if (rx - lx == 1) {
            t[x] += v;
        } else {
            int mx = (lx + rx) / 2;
            if (i < mx) {
                add(i, v, 2 * x + 1, lx, mx);
            } else {
                add(i, v, 2 * x + 2, mx, rx);
            }
            t[x] = t[2 * x + 1] + t[2 * x + 2];
        }
    }
 
    int get(int l, int r, int x, int lx, int rx) {
        if (lx >= l && rx <= r) return t[x];
        if (lx >= r || rx <= l) return 0;
        int mx = (lx + rx) / 2;
        return get(l, r, 2 * x + 1, lx, mx) + get(l, r, 2 * x + 2, mx, rx);
    }
 
public:
    void add(int i, int v) {
        add(i, v, 0, 0, size);
    }
 
    int get(int l, int r) {
        return get(l, r, 0, 0, size);
    }
 
    SegmentTree() {}
    SegmentTree(int n) : size(n) {
        t.assign(4 * size, 0);
    }
};
 
const int N = int(2e5) + 1; //TODO
int de[N], si[N], tin[N], up[N], pa[N], ti[N], to[N], t;
vector<int> g[N], euler;
 
void calcTimes(int u, int p) {
    ti[u] = t++;
    for (int v : g[u]) {
        if (v != p) {
            calc(v, u);
        }
    }
    to[u] = t++;
}
 
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
            }
            if (v != p && si[v] > si[g[u].front()]) {
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
    void add(int u, int val) {
        st.add(tin[u], val);
    }
 
    int get(int u, int v) {
        int ans = 0;
        while (up[u] != up[v]) {
            if (de[up[u]] < de[up[v]]) swap(u, v);
            ans += st.get(tin[up[u]], tin[u] + 1);
            u = pa[up[u]];
        }
        if (de[u] < de[v]) swap(u, v);
        ans += st.get(tin[v], tin[u] + 1);
        return ans;
    }
 
    int lca(int u, int v) {
        while (up[u] != up[v]) {
            if (de[up[u]] < de[up[v]]) swap(u, v);
            u = pa[up[u]];
        }
        if (de[u] < de[v]) swap(u, v);
        return v;
    }
 
    HLD() {
        calcTimes(0, -1);
        preDfs(0, -1);
        buildDfs(0, -1);
        st = SegmentTree(sz(euler));
    }
};
 
 
bool anc(int u, int v) {
    return ti[u] <= ti[v] && to[v] <= to[u];
}

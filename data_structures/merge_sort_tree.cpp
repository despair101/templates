struct MergeSortTree {
    int size;
    vector<vector<int>> t;

    inline int lt(int x) { return 2 * x + 1; }
    inline int rt(int x) { return 2 * x + 2; }
    inline int md(int lx, int rx) { return (lx + rx) / 2; }

    void build(int x, int lx, int rx, const vector<int>& a) {
        if (rx - lx == 1) {
            t[x] = { a[lx] };
        } else {
            build(lt(x), lx, md(lx, rx), a);
            build(rt(x), md(lx, rx), rx, a);
            t[x].resize(t[lt(x)].size() + t[rt(x)].size());
            merge(t[lt(x)].begin(), t[lt(x)].end(), t[rt(x)].begin(), t[rt(x)].end(), t[x].begin());
        }
    }

    int get(int x, int lx, int rx, int l, int r, int mi, int ma) {
        if (lx >= r || rx <= l) return 0;
        if (lx >= l && rx <= r) return upper_bound(t[x].begin(), t[x].end(), ma) - lower_bound(t[x].begin(), t[x].end(), mi);
        return get(lt(x), lx, md(lx, rx), l, r, mi, ma) + get(rt(x), md(lx, rx), rx, l, r, mi, ma);
    }
    int get(int l, int r, int mi, int ma) {
        return get(0, 0, size, l, r, mi, ma);
    }

    MergeSortTree(const vector<int>& a) : size(a.size()) {
        int tsize = 1;
        while (tsize < size) tsize *= 2;
        a.resize(tsize * 2 - 1);
        build(0, 0, size, a);
    }
};

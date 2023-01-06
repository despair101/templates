template <int LG> 
struct BitTrie {
    struct Node {
        int dp = 0;
        int nx[2];

        Node() {
            nx[0] = nx[1] = -1;
        }
    };

    vector<Node> t{ Node() };

    void insert(int x) {
        int u = 0;
        ++t[u].dp;
        for (int b = LG; b >= 0; --b) {
            int i = (x >> b & 1);
            if (t[u].nx[i] == -1) {
                t[u].nx[i] = sz(t);
                t.push_back(Node());
            }
            u = t[u].nx[i];
            ++t[u].dp;
        }
    }

    void erase(int x) {
        int u = 0;
        --t[0].dp;
        for (int b = LG; b >= 0; --b) {
            int i = (x >> b & 1);
            u = t[u].nx[i];
            --t[u].dp;
        }
    }

    int getMaxXor(int x) {
        int u = 0;
        int res = 0;
        for (int b = LG; b >= 0; --b) {
            int i = (x >> b & 1);
            if (t[u].nx[i ^ 1] != -1 && t[t[u].nx[i ^ 1]].dp) {
                res += (1 << b);
                u = t[u].nx[i ^ 1];
            } else {
                u = t[u].nx[i];
            }
        }
        return res;
    }
};

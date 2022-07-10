struct SparseTable {
    vector<vector<pair<int, int>>> dp;
 
    SparseTable(int n) {
        dp.assign(__lg(n) + 1, vector<pair<int, int>>(n));
        for (int i = 0; i < n; ++i) {
            dp[0][i] = { d[i], i };
        }
        for (int j = 1; j <= __lg(n); ++j) {
            for (int i = 0; i + (1 << j) <= n; ++i) {
                dp[j][i] = min(dp[j - 1][i], dp[j - 1][i + (1 << (j - 1))]);
            }
        }
    }
 
    int get(int l, int r) {
        return min(dp[le][l], dp[le][r - (1 << __lg(r - l)]).second;
    }
};

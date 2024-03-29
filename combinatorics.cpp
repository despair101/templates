//https://github.com/despair101/templates/blob/main/modular_int.cpp

const int MOD = 1'000'000'007;

typedef ModularInt<MOD> Mint;

vector<Mint> F, IF;
void precalcCombinatorics(int N) {
    F.resize(N + 1);
    F[0] = 1;
    for (int i = 1; i <= N; ++i) {
        F[i] = F[i - 1] * i;
    }
    IF.resize(N + 1);
    IF[N] = F[N].inv();
    for (int i = N - 1; i >= 0; --i) {
        IF[i] = IF[i + 1] * (i + 1);
    }
}

Mint A(int n, int k) { return F[n] * IF[n - k]; }
Mint C(int n, int k) { return F[n] * IF[n - k] * IF[k]; }

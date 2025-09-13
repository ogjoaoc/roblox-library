const int MAXN_FATORIAL = 200005; 
const int MOD = 1e9 + 7;
// DEFINE INT LONG LONG PLMDS
int fat[MAXN_FATORIAL], fati[MAXN_FATORIAL];

// (a^b) % m em O(log b)
// coloque o fexp

int inv(int n) { return fexp(n, MOD - 2); }

void precalc() {
    fat[0] = 1;
    fati[0] = 1;
    for (int i = 1; i < MAXN_FATORIAL; i++) fat[i] = (fat[i - 1] * i) % MOD;
    fati[MAXN_FATORIAL - 1] = inv(fat[MAXN_FATORIAL - 1]);
    for (int i = MAXN_FATORIAL - 2; i >= 0; i--) fati[i] = (fati[i + 1] * (i + 1)) % MOD;
}

int choose(int n, int k) {
    if (k < 0 || k > n) return 0;
    return (((fat[n] * fati[k]) % MOD) * fati[n - k]) % MOD;
}

// n! / (n-k)!
int perm(int n, int k) {
    if (k < 0 || k > n) return 0;
    return (fat[n] * fati[n - k]) % MOD;
}

// C_n = (1 / (n+1)) * C(2n, n)
int catalan(int n) {
    if (n < 0 || 2 * n >= MAXN_FATORIAL) return 0;
    int c2n_n = choose(2 * n, n);
    return (c2n_n * inv(n + 1)) % MOD;
}
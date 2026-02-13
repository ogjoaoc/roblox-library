const int N = 200005; 
const int MOD = 1e9 + 7;
// DEFINE INT LONG LONG PLMDS
int fat[N], fati[N];

// (a^b) % m em O(log b)
// coloque o fexp

int inv(int n) { return fexp(n, MOD - 2); }

void precalc() {
    fat[0] = 1;
    fati[0] = 1;
    for (int i = 1; i < N; i++) fat[i] = (fat[i - 1] * i) % MOD;
    fati[N - 1] = inv(fat[N - 1]);
    for (int i = N - 2; i >= 0; i--) fati[i] = (fati[i + 1] * (i + 1)) % MOD;
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
    if (n < 0 || 2 * n >= N) return 0;
    int c2n_n = choose(2 * n, n);
    return (c2n_n * inv(n + 1)) % MOD;

}

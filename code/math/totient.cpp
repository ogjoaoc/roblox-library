// phi(n) = n * (1 - 1/p1) * (1 - 1/p2) * ...
int phi(int n) {
    int result = n;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            while (n % i == 0)
                n /= i;
            result -= result / i;
        }
    }
    if (n > 1) // SE n sobrou, ele é um fator primo
        result -= result / n;
    return result;
}

// crivo phi
const int MAXN_PHI = 1000001;
int phiv[MAXN_PHI];
void phi_sieve() {
    for (int i = 0; i < MAXN_PHI; i++) phiv[i] = i;
    for (int i = 2; i < MAXN_PHI; i++) {
        if (phiv[i] == i) {
            for (int j = i; j < MAXN_PHI; j += i) phiv[j] -= phiv[j] / i;
        }
    }
}

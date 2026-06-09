const int MAXN = 2e6 + 2; 
int spf[MAXN];
vector<int> primes;

void sieve() {
    for (int i = 0; i < MAXN; i++) spf[i] = i;
    for (int i = 2; i * i < MAXN; i++) {
        if (spf[i] == i) {
            for (int j = i * i; j < MAXN; j += i) {
                if (spf[j] == j) {
                    spf[j] = i;
                }
            }
        }
    }
    for (int i = 2; i < MAXN; i++) {
        if (spf[i] == i) {
            primes.push_back(i);
        }
    }
}

map<int, int> factorize(int n) {
    map<int, int> factors;
    while (n > 1) {
        factors[spf[n]]++;
        n /= spf[n];
    }
    return factors;
}

int numero_de_divisores(int n) {
    if (n == 1) return 1;    
    map<int, int> fatores = fatorar(n);
    int nod = 1;
    for (auto &[primo, expoente] : fatores) nod *= (expoente + 1);
    return nod;
}

// DEFINE INT LONG LONG
int soma_dos_divisores(int n) {
    if (n == 1) return 1;
    map<int, int> fatores = fatorar(n);
    int sod = 1;
    for (auto &[primo, expoente] : fatores) {
        int termo_soma = 1;
        int potencia_primo = 1;
        for (int i = 0; i < expoente; i++) {
            potencia_primo *= primo;
            termo_soma += potencia_primo;
        }
        sod *= termo_soma;
    }
    return sod;

}

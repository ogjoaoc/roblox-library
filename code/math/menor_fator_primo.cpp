const int MAXN = 1000001; // Limite para o Crivo.
int spf[MAXN];
vector<int> primos;

void crivo() {
    for (int i = 0; i < MAXN; i++) spf[i] = [i];
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
            primos.push_back(i);
        }
    }
}

map<int, int> fatora(int n) {
    map<int, int> fatores;
    while (n > 1) {
        fatores[spf[n]]++;
        n /= spf[n];
    }
    return fatores;
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

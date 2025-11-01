const int MAXN = 200005; 
int N; 
int LOG;

vector<vector<int>> adj;
vector<int> profundidade;
vector<vector<int>> cima; // cima[v][j] eh o 2^j-esimo ancestral de v

void dfs(int v, int p, int d) {
    profundidade[v] = d;
    cima[v][0] = p; // o pai direto eh o 2^0-ésimo ancestral
    for (int j = 1; j < LOG; j++) {
        // se o ancestral 2^(j-1) existir, calculamos o 2^j
        if (cima[v][j - 1] != -1) {
            cima[v][j] = cima[cima[v][j - 1]][j - 1];
        } else {
            cima[v][j] = -1; // nao tem ancestral superior
        }
    }
    for (int nei : adj[v]) {
        if (nei != p) {
            dfs(nei, v, d + 1);
        }
    }
}

void build(int root) {
    LOG = ceil(log2(N));
    profundidade.assign(N + 1, 0);
    cima.assign(N + 1, vector<int>(LOG, -1));
    dfs(root, -1, 0); 
}

int get_lca(int a, int b) {
    if (profundidade[a] < profundidade[b]) {
        swap(a, b);
    }
    // sobe 'a' ate a mesma profundidade de 'b'
    for (int j = LOG - 1; j >= 0; j--) {
        if (profundidade[a] - (1 << j) >= profundidade[b]) {
            a = cima[a][j];
        }
    }
    // se 'b' era um ancestral de 'a', então 'a' agora é igual a 'b'
    if (a == b) {
        return a;
    }
    // sobe os dois juntos ate encontrar os filhos do LCA
    for (int j = LOG - 1; j >= 0; j--) {
        if (cima[a][j] != -1 && cima[a][j] != cima[b][j]) {
            a = cima[a][j];
            b = cima[b][j];
        }
    }
    return cima[a][0];
}
vector<int> d, low, pai;      // d[v] Tempo de descoberta (discovery time)
vector<bool> vis;
vector<int> pontos_articulacao;
vector<pair<int, int>> pontes;
int tempo;

vector<vector<int>> adj;

void dfs(int u) {
    vis[u] = true;
    tempo++;
    d[u] = low[u] = tempo;
    int filhos_dfs = 0; 
    for (int v : adj[u]) {
        if (v == pai[u]) continue; 
        if (vis[v]) { // back edge
            low[u] = min(low[u], d[v]);
        } else {
            pai[v] = u;
            filhos_dfs++;
            dfs(v);
            low[u] = min(low[u], low[v]);
            if (pai[u] == -1 && filhos_dfs > 1) {
                pontos_articulacao.push_back(u);
            }
            if (pai[u] != -1 && low[v] >= d[u]) {
                pontos_articulacao.push_back(u);
            }
            if (low[v] > d[u]) {
                pontes.push_back({min(u, v), max(u, v)});
            }
        }
    }
}
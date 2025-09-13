vector<int> adj[MAXN];
vector<int> estado(MAXN); // 0: nao visitado 1: processamento 2: processado
vector<int> ordem;
bool temCiclo = false;
 
void dfs(int v) {
    if(estado[v] == 1) {
        temCiclo = true; 
        return;
    }
    if(estado[v] == 2) return;
    estado[v] = 1;
    for(auto &nei : adj[v]) {
        if(estado[v] != 2) dfs(nei);
    }
    estado[v] = 2;
    ordem.push_back(v);
    return;
}
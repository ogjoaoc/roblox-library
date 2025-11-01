// encontra um ciclo em g 
// g[u] = vector<pair<id_aresta, vizinho>>
// rec_arestas: true -> retorna ids das arestas do ciclo; false -> retorna vertices do ciclo
// directed: grafo direcionado?

const int MAXN = 5 * 1e5 + 2;
vector<pair<int, int>> g[MAXN];
int N;
bool DIRECTED = false;
vector<int> color(MAXN), parent(MAXN, -1), edgein(MAXN, -1); // color: 0,1,2 ; edgein[v] = id da aresta que entra em v
int ini_ciclo = -1, fim_ciclo = -1, back_edge_id = -1;


bool dfs(int u, int pai_edge){
    color[u] = 1; // cinza
    for (auto [id, v] : g[u]) {
        if (!DIRECTED && id == pai_edge) continue; // ignorar aresta de volta ao pai em n-dir
        if (color[v] == 0) {
            parent[v] = u;
            edgein[v] = id;
            if (dfs(v, id)) return true;
        } else if (color[v] == 1) {
            // back-edge u -> v detectado
            ini_ciclo = u;
            fim_ciclo = v;
            back_edge_id = id;
            return true;
        }
        // se color[v] == 2, ignora
    }
    color[u] = 2; // preto
    return false;
}

// retorna ids das arestas do ciclo 
vector<int> pega_ciclo(bool rec_arestas) {
    for (int u = 1; u <= N; u++) {
        if (color[u] != 0) continue;
        if (dfs(u, -1)) {
            // caminho u -> ... -> v via parent
            vector<int> path;
            int cur = ini_ciclo;
            path.push_back(cur);
            while (cur != fim_ciclo) {
                cur = parent[cur];
                path.push_back(cur);
            }
            // path = [u, ..., v] -> inverter para [v, ..., u]
            reverse(path.begin(), path.end());
            if (!rec_arestas) return path;
            // converte para ids das arestas: edgein[node] eh a aresta que entra em node
            vector<int> edges;
            for (int i = 1; i < path.size(); i++) edges.push_back(edgein[path[i]]);
            // adiciona a aresta de retorno u -> v
            edges.push_back(back_edge_id);
            return edges;
        }
    }
    return {};
}
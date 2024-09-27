// Printa os nos na ordem em que são visitados
// Explora em largura (camadas)
// Complexidade: O(V+A) V = vertices e A = arestas
// Espaco: O(V)
// Uso: busca pelo caminho mais curto

void bfs(vector<vector<int>>&grafo, int inicio){
    set<int> visited;
    queue<int> fila;

    fila.push(inicio);
    visited.insert(inicio);

    while(!fila.empty()){
        int cur = fila.front();
        fila.pop();

        cout << cur << " "; // printa o nó atual

        for(int vizinho: grafo[cur]){
            if(visited.find(vizinho) == visited.end()){
                fila.push(vizinho);
                visited.insert(vizinho)
            }
        }
    }
}
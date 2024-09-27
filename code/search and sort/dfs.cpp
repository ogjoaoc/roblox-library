// Printa os nos na ordem em que são visitados
// Explora em profundidade
// Complexidade: O(V+A) V = vertices e A = arestas
// Espaco: O(V)
// Uso: explorar caminhos e backtracking

void dfs(vector<vector<int>>& grafo, int inicio){
    set<int> visited;
    stack<int> pilha;

    pilha.push(inicio);
    
    while(!pilha.empty()){
        int cur = pilha.top();
        pilha.pop();

        if(visited.find(cur) == visited.end()){
            cout << cur << " ";
            visited.insert(cur);

            for(int vizinho: grafo[cur]){
                if(visited.find(vizinho) == visited.end()){
                    pilha.push(vizinho);
                }
            }
        }
    }
}
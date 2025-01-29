int LOG;
 
int get_lca(int a, int b) {
    if(profundidade[b] > profundidade[a]) {
        swap(a, b);
    }
    int k = profundidade[a] - profundidade[b]; // tanto que tenho que subir
    for(int j = LOG-1; j >= 0; j--) {
        if((1 << j) & k) {
            a = cima[a][j];
        }
    }
    if(a == b) return a; // ja to no lca
 
    for(int j = LOG-1; j >= 0; j--) { // subo com os dois até chegar no lca fazendo binary lifting
        if(cima[a][j] != cima[b][j]) {
            a = cima[a][j];
            b = cima[b][j];
        }
    }
    return cima[a][0];
}
 
void dfs(int v, int p) {
    if(v != 1) profundidade[v] = profundidade[p] + 1;
    cima[v][0] = p;
    for(int j = 1; j < LOG; j++) {
        if (cima[v][j-1] != -1) {  
            cima[v][j] = cima[cima[v][j-1]][j-1];
        } else {
            cima[v][j] = -1;  
        }
    }
    for(auto &nei : adj[v]) {
        if(nei != p) {
            dfs(nei, v);
        }
    }
}
 
while((1 << LOG) <= n) LOG++;

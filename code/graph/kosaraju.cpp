bool vis[MAXN];
vector<int> order;
int component[MAXN];
int N, m;
vector<int> adj[MAXN], adj_rev[MAXN];

// dfs no grafo original para obter a ordem (pos-order)
void dfs1(int u) {
    vis[u] = true;
    for (int v : adj[u]) {
        if (!vis[v]) {
            dfs1(v);
        }
    }
    order.push_back(u);
}

// dfs o grafo reverso para encontrar os SCCs
void dfs2(int u, int c) {
    component[u] = c;
    for (int v : adj_rev[u]) {
        if (component[v] == -1) {
            dfs2(v, c);
        }
    }
}

int kosaraju() {
    order.clear();
    fill(vis + 1, vis + N + 1, false);
    for (int i = 1; i <= N; i++) {
        if (!vis[i]) {
            dfs1(i);
        }
    }
    fill(component + 1, component + N + 1, -1);
    int c = 0;
    reverse(order.begin(), order.end());
    for (int u : order) {
        if (component[u] == -1) {
            dfs2(u, c++);
        }
    }
    return c; 
}

// SSP e acha ciclos.
// Bom com constraints menores.
// O(n^3)

int dist[501][501];
 
void floydWarshall() {
	for(int k = 0; k < n; k++) {
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) {
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	} 
}
void solve() {
	int m, q;
	cin >> n >> m >> q;
	for(int i = 0; i < n; i++) {
		for(int j = i; j < n; j++) {
			if(i == j) {
				dist[i][j] = dist[j][i] = 0;
			} else {
				dist[i][j] = dist[j][i] = linf;
			}
		}
	}
	for(int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w; u--; v--;
		dist[u][v] = min(dist[u][v], w);
		dist[v][u] = min(dist[v][u], w);
	}
	floydWarshall();
	while(q--) {
		int u, v;
		cin >> u >> v; u--; v--;
		if(dist[u][v] == linf) cout << -1 << '\n';
		else cout << dist[u][v] << '\n';
	}
}

// topo-sort DAG
// lexicograficamente menor.
// N: número de vértices (1-indexado)
// adj: lista de adjacência do grafo

const int MAXN = 5 * 1e5 + 2;
vector<int> adj[MAXN];
int N;

vector<int> kahn() {
    vector<int> indegree(N + 1, 0);
    for (int u = 1; u <= N; u++) {
        for (int v : adj[u]) {
            indegree[v]++;
        }
    }
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 1; i <= N; i++) {
        if (indegree[i] == 0) {
            pq.push(i);
        }
    }
    vector<int> result; 
    while (!pq.empty()) {
        int u = pq.top();
        pq.pop();
        result.push_back(u);
        for (int v : adj[u]) {
            indegree[v]--;
            if (indegree[v] == 0) {
                pq.push(v);
            }
        }
    }
    if (result.size() != N) {
        return {}; 
    }
    return result;
}
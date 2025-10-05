// Encontra o menor custo para passar K de fluxo em um grafo com N vertices
// Funciona com multiplas arestas para o mesmo par de vertices
// Para encontrar o min cost max flow é só fazer K = infinito

struct Edge {
    int from, to, capacity, cost, id;
};

vector<vector<array<int, 2>>> adj;
vector<Edge> edges; // arestas pares são as normais e suas reversas são as impares

const int INF = LLONG_MAX;

void shortest_paths(int n, int v0, vector<int>& dist, vector<int>& edge_to) {
    dist.assign(n, INF);
    dist[v0] = 0;
    vector<bool> in_queue(n, false);
    queue<int> q;
    q.push(v0);
    edge_to.assign(n, -1);

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        in_queue[u] = false;
        for (auto [v, id] : adj[u]) {
            if (edges[id].capacity > 0 && dist[v] > dist[u] + edges[id].cost) {
                dist[v] = dist[u] + edges[id].cost;
                edge_to[v] = id;
                if (!in_queue[v]) {
                    in_queue[v] = true;
                    q.push(v);
                }
            }
        }
    }
}

int min_cost_flow(int N, int K, int s, int t) {
    adj.assign(N, vector<array<int, 2>>());

    for (Edge e : edges) {
        adj[e.from].push_back({e.to, e.id});
    }

    int flow = 0;
    int cost = 0;
    vector<int> dist, edge_to;
    while (flow < K) {
        shortest_paths(N, s, dist, edge_to);
        if (dist[t] == INF)
            break;

        // find max flow on that path
        int f = K - flow;
        int cur = t;
        while (cur != s) {
            f = min(f, edges[edge_to[cur]].capacity);
            cur = edges[edge_to[cur]].from;
        }

        // apply flow
        flow += f;
        cost += f * dist[t];
        cur = t;
        while (cur != s) {
            int edge = edge_to[cur];
            int rev_edge = edge^1;

            edges[edge].capacity -= f;
            edges[rev_edge].capacity += f;
            cur = edges[edge].from;
        }
    }

    if (flow < K)
        return -1;
    else
        return cost;
}

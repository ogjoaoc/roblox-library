// Edmonds-Karp com scalling O(E²log(F))

int n, m;
const int MAXN = 510;
vector<vector<int>> capacity(MAXN, vector<int>(MAXN, 0));
vector<vector<int>> adj(MAXN);

int bfs(int s, int t, int scale, vector<int>& parent) {
    fill(parent.begin(), parent.end(), -1);
    parent[s] = -2;
    queue<pair<int, int>> q;
    q.push({s, LLONG_MAX});

    while (!q.empty()) {
        int cur = q.front().first;
        int flow = q.front().second;
        q.pop();

        for (int next : adj[cur]) {
            if (parent[next] == -1 && capacity[cur][next] >= scale) {
                parent[next] = cur;
                int new_flow = min(flow, capacity[cur][next]);
                if (next == t)
                    return new_flow;
                q.push({next, new_flow});
            }
        }
    }

    return 0;
}

int maxflow(int s, int t) {
    int flow = 0;
    vector<int> parent(MAXN);
    int new_flow;
    int scalling = 1ll << 62;

    while (scalling > 0) {
        while (new_flow = bfs(s, t, scalling, parent)){
            if (new_flow == 0) continue;
            flow += new_flow;
            int cur = t;
            while (cur != s) {
                int prev = parent[cur];
                capacity[prev][cur] -= new_flow;
                capacity[cur][prev] += new_flow;
                cur = prev;
            }
        }
        scalling /= 2;
    }

    return flow;
}

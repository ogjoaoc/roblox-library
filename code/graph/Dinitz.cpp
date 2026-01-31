// Complexidade: O(V^2E)

struct FlowEdge {
    int from, to;
    long long cap, flow = 0;
    FlowEdge(int from, int to, long long cap) : from(from), to(to), cap(cap) {}
};

struct Dinic {
    const long long flow_inf = 1e18;
    vector<FlowEdge> edges;
    vector<vector<int>> adj;
    int qntV, qntE = 0;
    int source, sink;
    vector<int> level, ptr;
    queue<int> q;

    Dinic(int qntV, int source, int sink) : qntV(qntV), source(source), sink(sink) {
        adj.resize(qntV);
        level.resize(qntV);
        ptr.resize(qntV);
    }

    void add_edge(int from, int to, long long cap) {
        edges.emplace_back(from, to, cap);
        edges.emplace_back(to, from, 0);
        adj[from].push_back(qntE);
        adj[to].push_back(qntE + 1);
        qntE += 2;
    }

    bool bfs() {
        while (!q.empty()) {
            int from = q.front();
            q.pop();
            for (int id : adj[from]) {
                if (edges[id].cap == edges[id].flow)
                    continue;
                if (level[edges[id].to] != -1)
                    continue;
                level[edges[id].to] = level[from] + 1;
                q.push(edges[id].to);
            }
        }
        return level[sink] != -1;
    }

    long long dfs(int from, long long pushed) {
        if (pushed == 0)
            return 0;
        if (from == sink)
            return pushed;
        for (int& cid = ptr[from]; cid < (int)adj[from].size(); cid++) {
            int id = adj[from][cid];
            int to = edges[id].to;
            if (level[from] + 1 != level[to])
                continue;
            long long tr = dfs(to, min(pushed, edges[id].cap - edges[id].flow));
            if (tr == 0)
                continue;
            edges[id].flow += tr;
            edges[id ^ 1].flow -= tr;
            return tr;
        }
        return 0;
    }

    long long max_flow() {
        long long f = 0;
        while (true) {
            fill(level.begin(), level.end(), -1);
            level[source] = 0;
            q.push(source);
            if (!bfs())
                break;
            fill(ptr.begin(), ptr.end(), 0);
            while (long long pushed = dfs(source, flow_inf)) {
                f += pushed;
            }
        }
        return f;
    }
};

/**
 * Versão que assume: #define int long long
 *
 * Retorna um caminho/ciclo euleriano em um grafo (se existir).
 * - g: lista de adjacência (vector<vector<int>>).
 * - directed: true se o grafo for dirigido.
 * - s: vértice inicial.
 * - e: vértice final (opcional). Se informado, tenta caminho de s até e.
 * - O(Nlog(N))
 * Retorna vetor com a sequência de vértices, ou vazio se impossível.
 */
vector<int> eulerian_path(const vector<vector<int>>& g, bool directed, int s, int e = -1) {
    int n = (int)g.size();
    // cópia das adjacências em multiset para permitir remoção específica
    vector<multiset<int>> h(n);
    vector<int> in_degree(n, 0);
    vector<int> result;
    stack<int> st;
    // preencher h e indegrees
    for (int u = 0; u < n; ++u) {
        for (auto v : g[u]) {
            ++in_degree[v];
            h[u].emplace(v);
        }
    }
    st.emplace(s);
    if (e != -1) {
        int out_s = (int)h[s].size();
        int out_e = (int)h[e].size();
        int diff_s = in_degree[s] - out_s;
        int diff_e = in_degree[e] - out_e;
        if (diff_s * diff_e != -1) return {}; // impossível
    }
    for (int u = 0; u < n; ++u) {
        if (e != -1 && (u == s || u == e)) continue;
        int out_u = (int)h[u].size();
        if (in_degree[u] != out_u || (!directed && (in_degree[u] & 1))) {
            return {};
        }
    }
    while (!st.empty()) {
        int u = st.top();
        if (h[u].empty()) {
            result.emplace_back(u);
            st.pop();
        } else {
            int v = *h[u].begin();
            auto it = h[u].find(v);
            if (it != h[u].end()) h[u].erase(it);
            --in_degree[v];
            if (!directed) {
                auto it2 = h[v].find(u);
                if (it2 != h[v].end()) h[v].erase(it2);
                --in_degree[u];
            }
            st.emplace(v);
        }
    }
    for (int u = 0; u < n; ++u) {
        if (in_degree[u] != 0) return {};
    }
    reverse(result.begin(), result.end());
    return result;
}
int lis_nlogn(vector<int> &v) {
    vector<int> lis;
    lis.push_back(v[0]);
    for (int i = 1; i < v.size(); i++) {
        if (v[i] > lis.back()) {
            // estende a lis
            lis.push_back(v[i]);
        } else {
            // encontra o primeiro elemento em lis que >= v[i].
            auto it = lower_bound(lis.begin(), lis.end(), v[i]);
            *it = v[i];
        }
    }
    return lis.size();
}

// lis na tree do problema da sub
const int MAXN_TREE = 100001;
vector<int> adj[MAXN_TREE];
int values[MAXN_TREE];
int ans = 0;

void dfs(int u, int p, vector<int>& tails) {
    auto it = lower_bound(tails.begin(), tails.end(), values[u]);
    int prev = -1;
    bool coloquei = false;
    if (it == tails.end()) {
        tails.push_back(values[u]);
        coloquei = true;
    } else {
        prev = *it;
        *it = values[u];
    }
    ans = max(ans, (int)tails.size());
    for (int v : adj[u]) {
        if (v != p) {
            dfs(v, u, tails);
        }
    }
    if (coloquei) {
        tails.pop_back();
    } else {
        *it = prev;
    }
}
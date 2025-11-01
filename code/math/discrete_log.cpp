// returns minimum x for which a^x = b (mod m), a and m are coprime.
// if the answer dont need to be greater than some value, the vector<int> can be removed
int discrete_log(int a, int b, int m) {
    a %= m, b %= m;
    int n = sqrt(m) + 1;

    int an = 1;
    for (int i = 0; i < n; ++i)
        an = (an * 1ll * a) % m;

    unordered_map<int, vector<int>> vals;
    for (int q = 0, cur = b; q <= n; ++q) {
        vals[cur].push_back(q);
        cur = (cur * 1ll * a) % m;
    }

    int res = LLONG_MAX;

    for (int p = 1, cur = 1; p <= n; ++p) {
        cur = (cur * 1ll * an) % m;
        if (vals.count(cur)) {
            for (int q: vals[cur]){
                int ans = n * p - q;
                res = min(res, ans);
            }
        }
    } 
    return res;
}

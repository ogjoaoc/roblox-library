// dp de intervalos com bitmask 
int prox(int idx) {
    return lower_bound(S.begin(), S.end(), array<int, 4>{S[idx][1], 0ll, 0ll, 0ll}) - S.begin();
}
 
int dp[1002][(int)(1ll << 10)];
 
int rec(int i, int vis) {
    if (i == (int)S.size()) {
        if (__builtin_popcountll(vis) == N) return 0;
        return LLONG_MIN;
    }
    if (dp[i][vis] != -1) return dp[i][vis];
    int ans = rec(i + 1, vis);
    ans = max(ans, rec(prox(i), vis | (1ll << S[i][3])) + S[i][2]);
    return dp[i][vis] = ans;
}
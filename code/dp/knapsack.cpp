// dp[i][j] => i-esimo item com j-carga sobrando na mochila
// O(N * W)
vector<vector<int>> dp(N + 1, vector<int>(W + 1, 0));
for (int i = 1; i <= N; i++) dp[i][0] = 0;
for (int j = 0; j <= W; j++) dp[0][j] = 0; 
for (int i = 1; i <= N; i++) {
    for (int j = 0; j <= W; j++) {
        dp[i][j] = dp[i - 1][j];
        if (j >= items[i-1].first) {
            dp[i][j] = max(dp[i][j], dp[i - 1][j - items[i-1].first] + items[i-1].second); 
        } 
    }
}
cout << dp[N][W] << '\n';
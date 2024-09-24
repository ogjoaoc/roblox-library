// dp[i][j] => i-esimo item com j-carga sobrando na mochila
// O(N * W)

for(int j = 0; j < MAXN; j++) {
        dp[0][j] = 0;
    }
    for(int i = 1; i <= N; i++) {
        for(int j = 0; j <= W; j++) {
            if(items[i].first > j) {
                dp[i][j] = dp[i-1][j];
            } 
            else {
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-items[i].first] + items[i].second);
            }
        }
    }
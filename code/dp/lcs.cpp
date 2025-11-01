string s1, s2;
int dp[1001][1001];
int lcs(int i, int j) {
    if (i < 0 || j < 0) return 0;
    if (dp[i][j] != -1) return dp[i][j];
    if (s1[i] == s2[j]) return dp[i][j] = 1 + lcs(i - 1, j - 1);
    else return dp[i][j] = max(lcs(i - 1, j), lcs(i, j - 1));
}
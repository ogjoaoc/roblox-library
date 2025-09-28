// Número máximo de subarrays disjuntos com soma x usando apenas 
// prefixo até i (ou seja, considerando prefixo a[1..i]).
int disjointSumX(vector<int> &a, int x) {
    int n = a.size();
    map<int, int> best; // best[pref] = melhor dp visto para esse pref
    best[0] = 0; 
    int pref = 0;
    vector<int> dp(n + 1, 0); // dp[0] = 0
    for (int i = 1; i <= n; i++) {
        pref += a[i - 1];
        // não pegar subarray terminando em i
        dp[i] = dp[i-1];
        // pega se existir prefixo anterior e atualiza best
        auto it = best.find(pref - x);
        if (it != best.end()) {
            dp[i] = max(dp[i], it->second + 1);
        }
        best[pref] = max(best[pref], dp[i]);
    }
    return dp[n];
}

// Returns the number of distinct permutations 
// that are lexicographically less than the string t 
// using the provided frequency (freq) of the characters
int countPermLess(vector<int> freq, const string &t) {
    int n = t.size();
    int ans = 0;

    vector<int> fact(n + 1, 1), invfact(n + 1, 1);
    for (int i = 1; i <= n; i++)
        fact[i] = (fact[i - 1] * i) % MOD;
    invfact[n] = fexp(fact[n], MOD - 2, MOD);
    for (int i = n - 1; i >= 0; i--)
        invfact[i] = (invfact[i + 1] * (i + 1)) % MOD;

    // For each position in t, try placing a letter smaller than t[i] that is in freq
    for (int i = 0; i < n; i++) {
        for (char c = 'a'; c < t[i]; c++) {
            if (freq[c - 'a'] > 0) {
                freq[c - 'a']--;
                int ways = fact[n - i - 1];
                for (int f : freq)
                    ways = (ways * invfact[f]) % MOD;
                ans = (ans + ways) % MOD;
                freq[c - 'a']++;
            }
        }
        if (freq[t[i] - 'a'] == 0) break;
        freq[t[i] - 'a']--;
    }
    return ans;
}

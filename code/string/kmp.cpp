vector<int> kmp(string &s) {
    int m = s.size();
    vector<int> lsp(m, 0);
    for (int i = 1, j = 0; i < m; i++) { 
        while (j > 0 && s[j] != s[i]) j = lsp[j - 1];
        if (s[i] == s[j]) j++;
        lsp[i] = j;
    }
    return lsp;
}

vector<int> kmp(string s) {
    int n = (int)s.length();
    vector<int> p(n+1);
    p[0] = -1;
    for (int i = 1; i < n; i++) {
        int j = p[i-1];
        while (j >= 0 && s[j] != s[i-1])
            j = p[j-1];
        p[i] = j+1;
    }
    return p;
}

vector<int> digits;
 
int dp[20][10][2][2];
 
int rec(int i, int last, int flag, int started) {
    if (i == (int)digits.size()) return 1;
    if (dp[i][last][flag][started] != -1) return dp[i][last][flag][started];
    int lim;
    if (flag) lim = 9;
    else lim = digits[i]; 
    int ans = 0;
    for (int d = 0; d <= lim; d++) {
        if (started && d == last) continue;
        int new_flag = flag;
        int new_started = started;
        if (d > 0) new_started = 1;
        if (!flag && d < lim) new_flag = 1;
        ans += rec(i + 1, d, new_flag, new_started);
    }
    return dp[i][last][flag][started] = ans;
}
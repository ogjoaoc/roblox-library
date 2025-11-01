// comprime coordenadas pra quando ai <= 1e9
vector<int> vals(a.begin(), a.end());
sort(vals.begin(), vals.end());
vals.erase(unique(vals.begin(), vals.end()), vals.end());
auto id = [&](int x) -> int {
    return lower_bound(vals.begin(), vals.end(), x) - vals.begin();
};
for (int i = 0; i < n; i++) a[i] = id(a[i]);
// fim da parte de compr
SegTree seg(n);
// dp[i]: lis que termina em i
vector<int> dp(n, 1); // dp[i] = 1 base case
for (int i = 0; i < n; i++) {
    if (a[i] > 0) dp[i] = seg.query(0, max(0ll, a[i] - 1)) + 1;
    seg.update(a[i], dp[i]);
}
cout << *max_element(dp.begin(), dp.end()) << '\n';

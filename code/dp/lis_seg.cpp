    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<int> sorted_a = a;
    sort(sorted_a.begin(), sorted_a.end());
    for (int i = 0; i < n; i++) {
        a[i] = lower_bound(sorted_a.begin(), sorted_a.end(), a[i]) - sorted_a.begin();
    }
    SegTreeMx segmx;
    segmx.build(n);
    vector<int> dp(n, 1);
    for (int k = 0; k < n; k++) {
        if (a[k] > 0) {
            dp[k] = segmx.query(0, a[k] - 1) + 1;
        }
        segmx.update(a[k], dp[k]);
    }
    cout << *max_element(dp.begin(), dp.end()) << '\n';

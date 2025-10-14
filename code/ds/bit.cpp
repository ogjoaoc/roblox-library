struct BIT {
    int n;
    vector<int> bit;
    BIT(int n = 0): n(n), bit(n + 1, 0) {}
    void add(int i, int delta) {
        for(; i <= n; i += i & -i) bit[i] += delta;
    }
    int sum(int i) {
        int r = 0;
        for(; i > 0; i -= i & -i) r += bit[i];
        return r;
    }
    int range_sum(int l, int r){
        if (r < l) return 0;
        return sum(r) - sum(l - 1);
    }
};

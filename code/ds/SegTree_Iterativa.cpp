struct SegTree {
    int n;
    vector<int> t;
    int neutral_value = 0;
 
    int combine(int a, int b) {
        return a+b;
    }
 
    SegTree(const vector<int>& data) {
        n = data.size();
        t.resize(2 * n, neutral_value);
 
        for (int i = 0; i < n; i++)
            t[n + i] = data[i];
 
        for (int i = n - 1; i > 0; --i)
            t[i] = combine(t[i * 2], t[i * 2 + 1]);
    }
 
    int range_query(int l, int r) {
        int result = neutral_value;
        for (l += n, r += n + 1; l < r; l >>= 1, r >>= 1) {
            if (l & 1) result = combine(result, t[l++]);
            if (r & 1) result = combine(result, t[--r]);
        }
        return result;
    }
 
    void update(int pos, int new_val) {
        t[pos += n] = new_val;
        for (pos >>= 1; pos > 0; pos >>= 1)
            t[pos] = combine(t[2 * pos], t[2 * pos + 1]);
    }
};

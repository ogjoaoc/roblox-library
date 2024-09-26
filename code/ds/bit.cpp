class BIT {
    vector<int> bit;  
    int n;
    int sum(int idx) {
        int result = 0;
        while (idx > 0) {
            result += bit[idx];
            idx -= idx & -idx;  
        }
        return result;
    }

public:
    BIT(int size) {
        n = size;
        bit.assign(n + 1, 0);  // BIT indexada em 1
    }
    void update(int idx, int delta) {
        while (idx <= n) {
            bit[idx] += delta;
            idx += idx & -idx;  
        }
    }
    int query(int idx) {
        return sum(idx);
    }
    int range_query(int l, int r) {
        return sum(r) - sum(l - 1);
    }
};

BIT fenwick(n);
for(int i = 1; i <= n; i++) {
    fenwick.update(i, arr[i]);
}
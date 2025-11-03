struct SegTree {
    vector<int> tree;
    vector<int> lazy;
    int n;
    SegTree(int N) {
        n = N;
        tree.resize(4 * n);
        lazy.resize(4 * n, 0); 
        // build(a);
    }
    void push(int lx, int rx, int x) {
        if (lazy[x] == 0) {
            return; 
        }
        // tree[x] += lazy[x];
        tree[x] += (rx - lx + 1) * lazy[x];
        if (lx != rx) {
            lazy[2 * x] += lazy[x];
            lazy[2 * x + 1] += lazy[x];
        }
        lazy[x] = 0;
    }
    void build(vector<int> &a) {
        build(0, n - 1, 1, a);
    }
    void build(int lx, int rx, int x, vector<int> &a) {
        if (lx == rx) {
            tree[x] = a[lx];
            return;
        }
        int mid = lx + (rx - lx) / 2;
        build(lx, mid, 2 * x, a);
        build(mid + 1, rx, 2 * x + 1, a);
        tree[x] = tree[2 * x] + tree[2 * x + 1];
    }
    void update(int l, int r, int val) {
        update(0, n - 1, 1, l, r, val);
    }
    void update(int lx, int rx, int x, int l, int r, int val) {
        push(lx, rx, x);
        if (rx < l || lx > r) {
            return;
        }
        if (lx >= l && rx <= r) {
            lazy[x] += val;
            push(lx, rx, x);
            return;
        }
        int mid = lx + (rx - lx) / 2;
        update(lx, mid, 2 * x, l, r, val);
        update(mid + 1, rx, 2 * x + 1, l, r, val);
        tree[x] = tree[2 * x] + tree[2 * x + 1];
    }
    int query(int l, int r) {
        return query(0, n - 1, 1, l, r);
    }
    int query(int lx, int rx, int x, int l, int r) {
        push(lx, rx, x);
        if (rx < l || lx > r) {
            return 0; 
        }
        if (lx >= l && rx <= r) {
            return tree[x];
        }
        int mid = lx + (rx - lx) / 2;
        int s1 = query(lx, mid, 2 * x, l, r);
        int s2 = query(mid + 1, rx, 2 * x + 1, l, r);
        return s1 + s2;
    }
};

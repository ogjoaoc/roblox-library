struct SegTree {
    int n;
    vector<vector<int>> tree;
 
    SegTree(vector<int> &a) {
        n = a.size();
        tree.resize(4 * n);
        build(1, 0, n - 1, a);
    }
    
    void build(int x, int lx, int rx, vector<int> &a) {
        if (lx == rx) {
            tree[x] = { a[lx] };
            return;
        }
        int mid = lx + (rx - lx)/2;
        build(2 * x, lx, mid, a);
        build(2 * x + 1, mid + 1, rx, a);
        auto &L = tree[2 * x], &R = tree[2 * x + 1];
        tree[x].resize(L.size() + R.size());
        merge(L.begin(), L.end(), R.begin(), R.end(), tree[x].begin());
    }
 
    int query(int x, int lx, int rx, int l, int r) {
        if (lx >= l && rx <= r) {
            auto &v = tree[x];
            return v.end() - upper_bound(v.begin(), v.end(), r);
        }
        if (rx < l || lx > r) {
            return 0;
        }
        int mid = lx + (rx - lx)/2;
        return query(2 * x, lx, mid, l, r) + query(2 * x + 1, mid + 1, rx, l, r);
    }
 
    int query(int l, int r) {
       return query(1, 0, n - 1, l, r); 
    }
}

// Checar se o range é todo distinto
// Cada cara e sua próxima aparição a direita, conta quantos caras que a próxima aparição a direita ta dentro do range ainda
vector<int> nr(n);
map<int, int> mp;
for (int i = n - 1; i >= 0; i--) {
    auto it = mp.find(a[i]);
    nr[i] = it != mp.end() ? it->second : n;
    mp[a[i]] = i;
}
SegTree seg(nr);

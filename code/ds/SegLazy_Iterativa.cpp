template <typename T, typename L>
struct SegLazy {
    int n, h;
    vector<T> tree;
    vector<L> lazy;
    vector<bool> has_lazy;
    vector<int> sz; // se len = pow2, remove e sz[p] = 1 << h[p]

    // --- Mudar aqui ---
    const T T_neutral = LLONG_MAX; 

    inline T combine(T a, T b) {
        return min(a, b);
    }
    
    inline T apply_lazy_to_node(T node, L delta, int len) { 
        return node + (T)delta; 
    }
    
    inline L combine_lazy(L old_delta, L new_delta) { 
        return old_delta + new_delta; 
    }
    // -------------------------------------------

    SegLazy(const vector<T>& data) {
        n = data.size();
        h = 32 - __builtin_clz(n);
        tree.assign(2 * n, T_neutral);
        lazy.assign(n, L());
        has_lazy.assign(n, false);
        sz.assign(2 * n, 1);

        for (int i = 0; i < n; i++) tree[n + i] = data[i];
        for (int i = n - 1; i > 0; --i) {
            tree[i] = combine(tree[i << 1], tree[i << 1 | 1]);
            sz[i] = sz[i << 1] + sz[i << 1 | 1];
        }
    }

    inline void apply(int p, L v) {
        tree[p] = apply_lazy_to_node(tree[p], v, sz[p]);
        if (p < n) {
            if (has_lazy[p]) lazy[p] = combine_lazy(lazy[p], v);
            else lazy[p] = v;
            has_lazy[p] = true;
        }
    }

    inline void build(int p) {
        p += n;
        while (p > 1) {
            p >>= 1;
            T res = combine(tree[p << 1], tree[p << 1 | 1]);
            if (has_lazy[p]) tree[p] = apply_lazy_to_node(res, lazy[p], sz[p]);
            else tree[p] = res;
        }
    }

    inline void push(int p) {
        p += n;
        for (int s = h; s > 0; --s) {
            int i = p >> s;
            if (has_lazy[i]) {
                apply(i << 1, lazy[i]);
                apply(i << 1 | 1, lazy[i]);
                has_lazy[i] = false; 
            }
        }
    }

    void update(int l, int r, L v) {
        int l0 = l, r0 = r;
        for (l += n, r += n + 1; l < r; l >>= 1, r >>= 1) {
            if (l & 1) apply(l++, v);
            if (r & 1) apply(--r, v);
        }
        build(l0); build(r0);
    }

    T query(int l, int r) {
        push(l); push(r);
        T res_l = T_neutral, res_r = T_neutral;
        for (l += n, r += n + 1; l < r; l >>= 1, r >>= 1) {
            if (l & 1) res_l = combine(res_l, tree[l++]);
            if (r & 1) res_r = combine(tree[--r], res_r);
        }
        return combine(res_l, res_r);
    }
};

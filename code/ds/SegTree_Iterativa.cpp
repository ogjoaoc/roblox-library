// Exemplo de uso: 
// SegTree<int> st(vetor);
// range query e point update

template <typename T>
struct SegTree {
    int n;
    vector<T> tree;
    T neutral_value = 0;

    T combine(T a, T b) {
        return a + b;
    }

    SegTree(const vector<T>& data) {
        n = data.size();
        tree.resize(2 * n, neutral_value);

        for (int i = 0; i < n; i++)
            tree[n + i] = data[i];

        for (int i = n - 1; i > 0; --i)
            tree[i] = combine(tree[i * 2], tree[i * 2 + 1]);
    }

    T range_query(int l, int r) {
        T result = neutral_value;
        for (l += n, r += n + 1; l < r; l >>= 1, r >>= 1) {
            if (l & 1) result = combine(result, tree[l++]);
            if (r & 1) result = combine(result, tree[--r]);
        }
        return result;
    }

    void update(int pos, T new_val) {
        tree[pos += n] = new_val;
        for (pos >>= 1; pos > 0; pos >>= 1)
            tree[pos] = combine(tree[2 * pos], tree[2 * pos + 1]);
    }
};

// Exemplo de uso: 
// auto cmp = [](int a, int b) {return a+b;};
// SegTree<int> st(vetor, 0, cmp);

template <typename T>
struct SegTree {
    int n;
    vector<T> t;
    T neutral_value;
    function<T(T, T)> combine;

    SegTree(const vector<T>& data, T neutral, function<T(T, T)> comb)
        : neutral_value(neutral), combine(comb) {
        n = data.size();
        t.resize(2 * n, neutral_value);

        for (int i = 0; i < n; i++)
            t[n + i] = data[i];

        for (int i = n - 1; i > 0; --i)
            t[i] = combine(t[i * 2], t[i * 2 + 1]);
    }

    T range_query(int l, int r) {
        T result = neutral_value;
        for (l += n, r += n + 1; l < r; l >>= 1, r >>= 1) {
            if (l & 1) result = combine(result, t[l++]);
            if (r & 1) result = combine(result, t[--r]);
        }
        return result;
    }

    void update(int pos, T new_val) {
        t[pos += n] = new_val;
        for (pos >>= 1; pos > 0; pos >>= 1)
            t[pos] = combine(t[2 * pos], t[2 * pos + 1]);
    }
};

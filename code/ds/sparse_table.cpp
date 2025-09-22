// 1-index, O(1)
struct SparseTable {
    vector<vector<int>> st;
    int max_log;
    SparseTable(vector<int>& arr) {
        int n = arr.size();
        max_log = floor(log2(n)) + 1;
        st.resize(n, vector<int>(max_log));
        for (int i = 0; i < n; i++) {
            st[i][0] = arr[i];
        }
        for (int j = 1; j < max_log; j++) {
            for (int i = 0; i + (1 << j) <= n; i++) {
                st[i][j] = max(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
            }
        }
    }
    int query(int L, int R) {
        int tamanho = R - L + 1;
        int k = floor(log2(tamanho));
        return max(st[L][k], st[R - (1 << k) + 1][k]);
    }
};

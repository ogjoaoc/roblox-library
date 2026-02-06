// 1-index 
struct BIT2d {
  int n, m;
  vector<vector<int>> tree;
  BIT2d(int n, int m) : n(n), m(m) {
    tree.assign(n + 1, vector<int>(m + 1, 0));
  }
  void add(int y, int x, int delta) {
    for (int i = y; i <= n; i += i & -i) {
      for (int j = x; j <= m; j += j & -j) {
        tree[i][j] += delta;
      }
    }
  }
  int pref(int y, int x) {
    int res = 0;
    for (int i = y; i > 0; i -= i & -i) {
      for (int j = x; j > 0; j -= j & -j) {
        res += tree[i][j];
      }
    }
    return res;
  }
  int query(int y1, int x1, int y2, int x2) {
    return pref(y2, x2) - pref(y1 - 1, x2) - pref(y2, x1 - 1) + pref(y1 - 1, x1 - 1);
  }
};

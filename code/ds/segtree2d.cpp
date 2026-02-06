// 0 index
struct SegTree2d {
  int n;
  vector<vector<int>> tree;
  SegTree2d(int n) : n(n) {
    tree.assign(4 * n, vector<int>(4 * n, 0));
  }
  void update_x(int no_y, int no_x, int lx, int rx, int x, int val, bool folha_y) {
    if (lx == rx) {
      if (folha_y) tree[no_y][no_x] = val;
      else tree[no_y][no_x] = tree[2 * no_y][no_x] + tree[2 * no_y + 1][no_x];
      return;
    }
    int mid = (lx + rx) / 2;
    if (x <= mid) update_x(no_y, 2 * no_x, lx, mid, x, val, folha_y);
    else update_x(no_y, 2 * no_x + 1, mid + 1, rx, x, val, folha_y);
    tree[no_y][no_x] = tree[no_y][2 * no_x] + tree[no_y][2 * no_x + 1];
  }
  void update_y(int no_y, int ly, int ry, int y, int x, int val) {
    if (ly == ry) {
      update_x(no_y, 1, 0, n - 1, x, val, true);
      return;
    }
    int mid = (ly + ry) / 2;
    if (y <= mid) update_y(2 * no_y, ly, mid, y, x, val);
    else update_y(2 * no_y + 1, mid + 1, ry, y, x, val);
    update_x(no_y, 1, 0, n - 1, x, val, false);
  }
  int query_x(int no_y, int no_x, int lx, int rx, int x1, int x2) {
    if (rx < x1 || lx > x2) return 0;
    if (lx >= x1 && rx <= x2) return tree[no_y][no_x];
    int mid = (lx + rx) / 2;
    return query_x(no_y, 2 * no_x, lx, mid, x1, x2) + query_x(no_y, 2 * no_x + 1, mid + 1, rx, x1, x2);
  }
  int query_y(int no_y, int ly, int ry, int y1, int y2, int x1, int x2) {
    if (ry < y1 || ly > y2) return 0;
    if (ly >= y1 && ry <= y2) return query_x(no_y, 1, 0, n - 1, x1, x2);
    int mid = (ly + ry) / 2;
    return query_y(2 * no_y, ly, mid, y1, y2, x1, x2) + query_y(2 * no_y + 1, mid + 1, ry, y1, y2, x1, x2);
  }
  void update(int y, int x, int val) {
    update_y(1, 0, n - 1, y, x, val);
  }
  int query(int y1, int x1, int y2, int x2) {
    return query_y(1, 0, n - 1, y1, y2, x1, x2);
  }
};

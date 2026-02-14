struct SegTree {
  int n;
  vector<array<int, 4>> tree;
  vector<int> v;
  SegTree(vector<int> &a) : v(a), n(a.size()) {
    tree.resize(4 * n);
    build(1, 0, n - 1);
  }
  void build(int x, int lx, int rx) {
    if (lx == rx) { 
      tree[x] = { v[lx], v[lx], v[lx], v[lx]};
      return; 
    }
    int mid = lx + (rx - lx) / 2;
    build(2 * x, lx, mid);
    build(2 * x + 1, mid + 1, rx);
    tree[x] = combine(tree[2 * x], tree[2 * x + 1]);
  }
  array<int, 4> query(int x, int lx, int rx, int l, int r) {
    if (lx >= l && rx <= r) 
      return tree[x];
    if (lx > r || rx < l) 
      return { 0, LINF, LINF, LINF };
    int mid = lx + (rx - lx) / 2;
    return combine(query(2 * x, lx, mid, l, r), query(2 * x + 1, mid + 1, rx, l, r));
  };
  int query(int l, int r) {
    return max(0ll, query(1, 0, n - 1, l, r)[3]);
  }
  void update(int x, int lx, int rx, int pos, int val) {
    if (lx == rx) {
      tree[x] = { val, val, val, val };
      return;
    }
    int mid = lx + (rx - lx) / 2;
    if (pos <= mid) 
      update(2 * x, lx, mid, pos, val);
    else 
      update(2 * x + 1, mid + 1, rx, pos, val);
    tree[x] = combine(tree[2 * x], tree[2 * x + 1]);
  }
  void update(int pos, int val) {
    update(1, 0, n - 1, pos, val);
  }
  array<int, 4> combine(array<int, 4> x, array<int, 4> y) {
    return { 
      x[0] + y[0], 
      max(x[1], x[0] + y[1]),
      max(y[2], y[0] + x[2]), 
      max({x[3], y[3], x[2] + y[1]})
    };
  }

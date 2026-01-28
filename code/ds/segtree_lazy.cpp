/*
Seg com double Lazy de soma e de set
tipo 1 - soma em range
tipo 2 - set em range
*/
struct SegTree {
  int n;
  vector<int> v, tree;
  vector<int> lazy_soma, lazy_set;
  SegTree(vector<int> &a) : v(a), n(a.size()) {
    tree.resize(4 * n);
    lazy_soma.resize(4 * n, 0);
    lazy_set.resize(4 * n, -1);
    build(1, 0, n - 1);
  };
  void build(int x, int lx, int rx) {
    if (lx == rx) {
      tree[x] = v[lx];
      return;
    }
    int mid = (lx + rx) / 2;
    build(2 * x, lx, mid);
    build(2 * x + 1, mid + 1, rx);
    tree[x] = tree[2 * x] + tree[2 * x + 1];
  }
  void seta(int x, int lx, int rx, int val) {
    tree[x] = val * (rx - lx + 1);
    lazy_set[x] = val;
    lazy_soma[x] = 0;
  }
  void soma(int x, int lx, int rx, int val) {
    tree[x] += val * (rx - lx + 1);
    if (lazy_set[x] != -1) {
      lazy_set[x] += val;
    } else {
      lazy_soma[x] += val;
    }
  }
  void push(int x, int lx, int rx) {
    int mid = (lx + rx) / 2;
    if (lazy_set[x] != -1) {
      if (lx != rx) {
        seta(2 * x, lx, mid, lazy_set[x]);
        seta(2 * x + 1, mid + 1, rx, lazy_set[x]);
      }
      lazy_set[x] = -1;
    } 
    if (lazy_soma[x] != 0) {
      if (lx != rx) {
        soma(2 * x, lx, mid, lazy_soma[x]);
        soma(2 * x + 1, mid + 1, rx, lazy_soma[x]);
      }
      lazy_soma[x] = 0;
    } 
  }
  void update(int x, int lx, int rx, int l, int r, int val, int type) {
    push(x, lx, rx);
    if (lx >= l && rx <= r) {
      if (type == 1) soma(x, lx, rx, val);
      else seta(x, lx, rx, val);
      push(x, lx, rx);
      return;
    }
    if (lx > r || rx < l) return;
    int mid = (lx + rx) / 2;
    update(2 * x, lx, mid, l, r, val, type);
    update(2 * x + 1, mid + 1, rx, l, r, val, type);
    tree[x] = tree[2 * x] + tree[2 * x + 1];
  }
  void update(int l, int r, int val, int type) {
    update(1, 0, n - 1, l, r, val, type);
  }
  int query(int x, int lx, int rx, int l, int r) {
    push(x, lx, rx);
    if (lx >= l && rx <= r) return tree[x];
    if (lx > r || rx < l) return 0;
    int mid = (lx + rx) / 2;
    return query(2 * x, lx, mid, l, r) + query(2 * x + 1, mid + 1, rx, l, r);
  }
  int query(int l, int r) {
    return query(1, 0, n - 1, l, r);
  }
};



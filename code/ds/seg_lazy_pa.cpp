/* Notas  
  PA eh da forma a0 (a) e razão (d)
  na hora de propagar o lazy
  aplica no no S = (a0 + (a0 + (n - 1) * d)) * n / 2  (variante da soma total do no)
  pros filhos, o da esquerda eh normal
  lazy_a[esq] += lazy_a[x]
  lazy_d[esq] += lazy_d[x]
  pro da direita tem que mudar o a (que eh o elemento inicial naquele no da direita)
  lazy_a[dir] += a + len_esq * (d)
  lazy_d[dir] += lazy_d[x]
*/

int gauss(int n, int a, int d) {
  // (a0 + an) * n / 2
  if (n <= 0) 
    return 0;
  return (a + (a + (n - 1) * d)) * n / 2;
}
 
struct SegTree {
  int n;
  vector<int> v, lazy_a, lazy_d, tree;
  SegTree(vector<int> &a) : v(a), n(a.size()) {
    tree.resize(4 * n);
    lazy_a.resize(4 * n, 0ll);
    lazy_d.resize(4 * n, 0ll);    
    build(1, 0, n - 1);
  }
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
  int query(int x, int lx, int rx, int l, int r) {
    push(x, lx, rx);
    if (lx >= l && rx <= r) 
      return tree[x];
    if (lx > r || rx < l) 
      return 0;
    int mid = (lx + rx) / 2;
    return query(2 * x, lx, mid, l, r) + query(2 * x + 1, mid + 1, rx, l, r);
  }
  int query(int l, int r) {
    return query(1, 0, n - 1, l, r);
  }
  void push(int x, int lx, int rx) {
    if (lazy_a[x] && lazy_d[x]) {
      int tam = rx - lx + 1;
      tree[x] += gauss(tam, lazy_a[x], lazy_d[x]);
      if (lx != rx) {
        int mid = (lx + rx) / 2;
        int tam_esq = mid - lx + 1;
        lazy_a[2 * x] += lazy_a[x];
        lazy_d[2 * x] += lazy_d[x];
        lazy_a[2 * x + 1] += (lazy_a[x] + tam_esq * lazy_d[x]);
        lazy_d[2 * x + 1] += lazy_d[x];
      }
      lazy_a[x] = lazy_d[x] = 0;
    }
  }
  void update(int x, int lx, int rx, int l, int r, int a, int d) {
    push(x, lx, rx);
    if (lx >= l && rx <= r) {
      lazy_a[x] += a + (lx - l) * d;
      lazy_d[x] += d;
      push(x, lx, rx);
      return;
    }
    if (lx > r || rx < l) 
      return;
    int mid = (lx + rx) / 2;
    update(2 * x, lx, mid, l, r, a, d);
    update(2 * x + 1, mid + 1, rx, l, r, a, d);
    tree[x] = tree[2 * x] + tree[2 * x + 1];
  }
  void update(int l, int r, int a, int d) {
    update(1, 0, n - 1, l, r, a, d);
  }
};

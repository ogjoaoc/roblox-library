#define all(x) x.begin(), x.end()

struct MST {
  int n;
  vector<vector<int>> tree;
  MST(vector<int> &a) {
    n = a.size();
    tree.resize(4 * n);
    build(1, 0, n - 1, a);
  }
  void build(int x, int lx, int rx, vector<int> &a) {
    if (lx == rx) {
      tree[x] = { a[lx] };
      return;
    }
    int mid = lx + (rx - lx) / 2;
    build(2 * x, lx, mid, a);
    build(2 * x + 1, mid + 1, rx, a);
    auto &L = tree[2 * x], &R = tree[2 * x + 1];
    tree[x].resize(L.size() + R.size());
    merge(all(L), all(R), tree[x].begin());
  }
  int query(int x, int lx, int rx, int l, int r, int val) {
    if (lx > r || rx < l) return 0;
    if (lx >= l && rx <= r) {
      auto &v = tree[x];
      return lower_bound(all(v), val) - v.begin();
    }
    int mid = lx + (rx - lx) / 2;
    return query(2 * x, lx, mid, l, r, val) + query(2 * x + 1, mid + 1, rx, l, r, val);
  }
  int query(int l, int r, int val) {
    if (l > r) return 0;
    return query(1, 0, n - 1, l, r, val);
  }
};

/* mst.query(l, r, l) retorna quantos caras distintos no range
  map<int, int> last;
  for (int i = 0; i < n; i++) {
    if (last.count(a[i])) {
      esq[i] = last[a[i]];
    } else {
      esq[i] = -1;
    }
    last[a[i]] = i;
  }
  MST mst(esq);
  jogar vetor de ultima aparicao na seg
*/

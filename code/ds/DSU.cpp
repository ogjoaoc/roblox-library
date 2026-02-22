struct DSU {
    vector<int> parent, size;
    int C;
    DSU(int n) : parent(n + 1), size(n + 1), C(n) {
        for (int i = 1; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }
    int find(int a) {
        if (parent[a] == a) return a;
        return parent[a] = find(parent[a]);
    }
    int same(int a, int b) {
        return find(a) == find(b);
    }
    int get_size(int a) {
        return size[find(a)];
    }
    int count() {
        return C;
    }
    void join(int a, int b) {
        int pA = find(a);
        int pB = find(b);
        if (pA != pB) {
            C--;
            if (size[pA] > size[pB]) {
                swap(pA, pB);
            }
            parent[pA] = pB;
            size[pB] += size[pA];
        }
    }
};

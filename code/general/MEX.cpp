struct MEX {
    map<int, int> f;
    set<int> falta;
    int tam;
    MEX(int n) : tam(n) {
        for (int i = 0; i <= n; i++) falta.insert(i);
    }
    void add(int x) {
        f[x]++;
        if (f[x] == 1 && x >= 0 && x <= tam) {
            falta.erase(x);
        }
    }
    void rem(int x) {
        if (f.count(x) && f[x] > 0) {
            f[x]--;
            if (f[x] == 0 && x >= 0 && x <= tam) {
                falta.insert(x);
            }
        }
    }
    int get() {
        if (falta.empty()) return tam + 1;
        return *falta.begin();
    }
};

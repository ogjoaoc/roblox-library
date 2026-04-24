int trie[MAXN][2];
int cnt[MAXN][2];
int cur_node = 0;
 
void insere(int x) {
    int node = 0;
    for (int i = 29; ~i; i--) {
        int bit = (1ll << i) & x ? 1 : 0;
        if (trie[node][bit] == 0) trie[node][bit] = ++cur_node;
        cnt[node][bit]++;
        node = trie[node][bit];
    }
}
 
int query(int x) { 
    int r = 0;
    int node = 0;
    for (int i = 29; ~i; i--) {
        int bit = (x >> i) & 1;
        if (trie[node][bit ^ 1] != 0 && cnt[node][bit ^ 1] > 0) {
            r |= (1ll << i);
            node = trie[node][bit ^ 1];
        } else {
            node = trie[node][bit];
        }
    }
    return r;
}

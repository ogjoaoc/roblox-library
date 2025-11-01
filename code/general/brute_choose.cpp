vector<int> elements;
int N, K;
vector<int> comb;

void brute_choose(int i) {
    if (comb.size() == K) {
        for (int j = 0; j < comb.size(); j++) {
            cout << comb[j] << ' '; 
        }
        cout << '\n';
        return;
    }
    if (i == N) return;
    int r = N - i;
    int preciso = K - comb.size();
    if (r < preciso) return;
    comb.push_back(elements[i]);
    brute_choose(i + 1);
    comb.pop_back(); 
    brute_choose(i + 1);
}
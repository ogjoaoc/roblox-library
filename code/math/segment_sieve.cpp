// Retorna quantos primos tem entre [l, r] (inclusivo)
// precisa de um vetor com os primos até sqrt(r)
int seg_sieve(int l, int r){
    if (l > r) return 0;
    vector<bool> is_prime(r - l + 1, true);
    if (l == 1) is_prime[0] = false;

    for (int p : primos){
        if (p * p > r) break;
        int start = max(p * p, (l + p - 1) / p * p);
        for (int j = start; j <= r; j += p){
            if (j >= l) {
                is_prime[j - l] = false;
            }
        }
    }
  
    return accumulate(all(is_prime), 0ll);;
}

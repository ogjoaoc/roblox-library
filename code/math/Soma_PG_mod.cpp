// 1 + r + r² + r³ ... r^n (mod m)
// O(log(N)) funciona com qualquer m
// retorna {soma, r^n mod m}
array<int, 2> soma_pg(int r, int n, int m) {
    if (n == 0) return {0, 1};
    
    auto [mid, p] = soma_pg(r, n / 2, m);
  
    int sum = (mid*p % m + mid) % m;
    int np = p*p % m; // r^n
    
    if (n&1) {
        sum = (sum*r + 1) % m;
        np = np*r % m;
    }
    
    return {sum, np};
}

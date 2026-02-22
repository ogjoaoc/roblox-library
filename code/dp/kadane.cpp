// O(n) - retorna maximum subarray sum
array<int, 3> kadane(vector<int> &a) {
    int L = -1, R = -1, n = a.size();
    int soma = 0, ans = -INF;
    int fim = n - 1;
    for (int i = n - 1; i >= 0; i--)  {
        if (a[i] > a[i] + soma) {
            fim = i;
            soma = a[i];
        } else {
            soma += a[i];
        }
        if (soma > ans) {
            R = fim;	
            L = i;
            ans = soma;
        }
    }
    return { ans, L, R };
}

// Retorna um vetor com os divisores de x
// eh preciso ter o crivo implementado
// O(divisores)

vector<int> divs(int x){
    vector<int> ans = {1};
    vector<array<int, 2>> primos; // {primo, expoente}
    
    while (x > 1) {
        int p = crivo[x], cnt = 0;
        while (x % p == 0) cnt++, x /= p;
        primos.push_back({p, cnt});
    }
 
    for (int i=0; i<primos.size(); i++){
        int cur = 1, len = ans.size();

        for (int j=0; j<primos[i][1]; j++){
            cur *= primos[i][0];
            for (int k=0; k<len; k++)
                ans.push_back(cur*ans[k]);
        }
    }

    return ans;
}

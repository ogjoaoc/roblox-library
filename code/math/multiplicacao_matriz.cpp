// multiplica matrizes de tamanhos variados, resultando em uma matrix N*M
vector<vector<int>> mm(vector<vector<int>> A, vector<vector<int>> B) {
    int N = A.size(), M = B[0].size(), K = B.size();
    vector<vector<int>> C(N, vector<int>(M));

    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            for (int k = 0; k < K; ++k)
                C[i][j] = (C[i][j]+A[i][k] * B[k][j] % mod)%mod;
    
    return C;
}

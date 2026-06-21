const int MOD = 1e9 + 7;
 
struct Matrix {
    int N, M;
    vector<vector<int>> mat;
    Matrix(int n, int m, bool I = false) : N(n), M(m) {
        mat.assign(N, vector<int>(M, 0ll));
        if (I) {
            for (int i = 0; i < min(N, M); i++) {
                mat[i][i] = 1;
            }
        }
    };
    Matrix operator*(const Matrix &other) {
        assert(M == other.N);
        Matrix res(N, other.M);
        for (int i = 0; i < N; i++) {
            for (int k = 0; k < M; k++) {
                for (int j = 0; j < other.M; j++) {
                    res.mat[i][j] = (res.mat[i][j] + mat[i][k] * other.mat[k][j]) % MOD;
                }
            }
        }
        return res;
    }
    Matrix exp(Matrix A, int B) {
        assert(A.N == A.M);
        Matrix res(A.N, A.M, true);
        while (B) {
            if (B & 1) res = res * A;
            A = A * A;
            B >>= 1;
        }
        return res;
    }
};

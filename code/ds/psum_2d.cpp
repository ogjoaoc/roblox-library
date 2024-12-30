// retangulo retorna a psum2d do intervalo inclusivo
vector<vector<int>> psum(n+1, vector<int>(m+1, 0));
 
for (int i=1; i<n+1; i++){
    for (int j=1; j<m+1; j++){
        cin >> psum[i][j];
        psum[i][j] += psum[i-1][j]+psum[i][j-1]-psum[i-1][j-1];
    }
}

// y1 eh variavel reservada
int retangulo(int x1, int yy1, int x2, int yy2){
    x2 = min(x2, n), yy2 = min(yy2, m);
    x1 = max(0LL, x1-1), yy1 = max(0LL, yy1-1);

    return psum[x2][yy2]-psum[x1][yy2]-psum[x2][yy1]+psum[x1][yy1];
}

vector<vector<int>> psum(h+1, vector<int>(w+1, 0));
for (int i=1; i<=h; i++){
    for (int j=1; j<=w; j++){
        cin >> psum[i][j];
        psum[i][j] += psum[i-1][j]+psum[i][j-1]-psum[i-1][j-1];
    }
}
// retorna a psum2d do intervalo inclusivo [(a, b), (c, d)]
int retangulo(int a, int b, int c, int d){
    c = min(c, h), d = min(d, w);
    a = max(0LL, a-1), b = max(0LL, b-1);
    return v[c][d]-v[a][d]-v[c][b]+v[a][b];
}

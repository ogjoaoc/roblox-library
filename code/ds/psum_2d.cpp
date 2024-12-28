vector<vector<int>> psum(n+1, vector<int>(m+1, 0));
 
for (int i=1; i<n+1; i++){
    for (int j=1; j<m+1; j++){
        cin >> psum[i][j];
        psum[i][j] += psum[i-1][j]+psum[i][j-1]-psum[i-1][j-1];
    }
}

int retangulo(int x1, int y1, int x2, int y2){
    x2 = min(x2, n), y2 = min(y2, m);
    x1 = max(0LL, x1-1), y1 = max(0LL, y1-1);

    return psum[x2][y2]-psum[x1][y2]-psum[x2][y1]+psum[x1][y1];
}

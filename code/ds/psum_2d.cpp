// entrada: matrix com ponto e X
// saber em O(1) quantidade de X em um retangulo

vector<vector<int>> v(n+1, vector<int>(n+1, 0));
 
for (int i=1; i<n+1; i++){
    for (int j=1; j<n+1; j++){
        char x; cin >> x;
        if (x == 'X') v[i][j] += 1 + v[i][j-1] + v[i-1][j] - v[i-1][j-1];
        else v[i][j] = v[i][j-1] + v[i-1][j] - v[i-1][j-1];
    }
}

// Pegar retângulo (x, y) - (z, w)
// ponto superior esquerdo e inferior direito

cin >> x >> y >> z >> w;
cout << v[z][w] - v[x-1][w] - v[z][y-1] + v[x-1][y-1] << endl;

/*
O(N + M), retorna cara mais distante, len 
do caminho em arestas e os caras do caminho em um vetor
Para pegar o diametro da arvore, chamar duas vezes
auto [a, DA, PA] = calc(1);
auto [b, len_diametro, caminho_diametro] = calc(a);
*/
auto calc = [&](int S) -> tuple<int, int, vector<int>> {
    queue<pair<int, int>> q;
    q.push({S, 0});
    vector<int> dp(n + 1, -1), pai(n + 1, 0);
    dp[S] = 0;
    pai[S] = -1;
    int longe = S;
    int dist = 0;
    while (!q.empty()){
      auto [u, d] = q.front();
      q.pop();
      if (d > dist){
        dist = d;
        longe = u;
      }
      for (int v : adj[u]){
        if (dp[v] == -1){ 
          dp[v] = d + 1;
          pai[v] = u;
          q.push({v, d + 1});
        }
      }
    }
    int cur = longe;
    vector<int> caminho;
    while (cur != -1){
      caminho.push_back(cur);
      cur = pai[cur];
    }
    return { longe, dist, caminho };
};

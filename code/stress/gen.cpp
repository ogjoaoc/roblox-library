// pre-compilar os headers: 
// compilar template com g++ -H e procurar onde esta stdc++.h
// criar a pasta bits e incluir com "" ou inves de <>
// compilar stress com: g++ -pipe -O3 -flto -march=native -mtune=native gen.ccp
// faz bastante diferença no runtime

#include <bits/stdc++.h>
#include <cstdlib> 
#include <ctime> 
using namespace std;

int randi(int L, int R) { return L + rand() % (R - L + 1); }
char randc(char L, char R) { return char(L + rand() % (R - L + 1)); }

int main(int argc, char** argv) {
    if (argc > 1) srand(atoi(argv[1]));
    else srand(time(0)); 
    
    int n = randi(1, 100);     
    cout << n << '\n';
    for (int i = 0; i < n; i++) {
        cout << randi(-10, 20) << ' '; 
    }
    cout << '\n';
}

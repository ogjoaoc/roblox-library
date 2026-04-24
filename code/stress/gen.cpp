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

/*
script.sh

g++ -std=c++17 -O2 -o sol sol.cpp
g++ -std=c++17 -O2 -o brute brute.cpp
g++ -std=c++17 -O2 -o gen gen.cpp

for ((i = 1; ; i++)); do
    ./gen $i > in.txt
    ./sol < in.txt > out1.txt
    ./brute < in.txt > out2.txt

    if ! diff -q out1.txt out2.txt > /dev/null; then
        echo "Mismatch found on test $i"
        cat in.txt
        echo "Your output:"
        cat out1.txt
        echo "Brute output:"
        cat out2.txt
        break
    fi
    echo "Test $i passed"
done

*/

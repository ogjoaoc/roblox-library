// a^e mod m
// O(log n)

int fexp(int a, int e, int m) {
    a %= m;
    int ans = 1;
    while (e > 0){
        if (e & 1) ans = ans*a % m;
        a = a*a % m;
        e /= 2;
    }
    return ans%m;
}

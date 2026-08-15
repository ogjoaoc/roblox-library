#define int long long

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

int mul(int a, int b, int m) {
    return (int)((__int128)a * b % m);
}

int fexp(int a, int b, int m) {
    int r = 1;
    while (b) {
        if (b & 1) r = mul(r, a, m);
        a = mul(a, a, m);
        b >>= 1;
    }
    return r;
}

bool isPrime(int n) {
    if (n < 2) return false;
    int d = n - 1, s = 0;
    while (d % 2 == 0) d /= 2, s++;
    for (int a : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}) {
        if (n == a) return true;
        if (n % a == 0) return false;
        int x = fexp(a, d, n);
        if (x == 1 || x == n - 1) continue;
        bool comp = true;
        for (int r = 1; r < s; r++) {
            x = mul(x, x, n);
            if (x == n - 1) { 
                comp = false; 
                break; 
            }
        }
        if (comp) return false;
    }
    return true;
}

int rho(int n) {
    if (n % 2 == 0) return 2;
    if (isPrime(n)) return n;
    while (true) {
        int c = rng() % n, x = 2, y = 2, d = 1;
        auto f = [&](int x) { return (mul(x, x, n) + c) % n; };
        while (d == 1) {
            x = f(x);
            y = f(f(y));
            d = gcd(abs(x - y), n);
        }
        if (d != n) return d;
    }
}

void fat(int n, vector<int>& f) {
    if (n == 1) return;
    if (isPrime(n)) { f.push_back(n); return; }
    int d = rho(n);
    fat(d, f);
    fat(n / d, f);
}

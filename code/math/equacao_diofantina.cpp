int extended_gcd(int a, int b, int& x, int& y) {
    if (a == 0) {
        x = 0;
        y = 1;
        return b;
    }
    int x1, y1;
    int gcd = extended_gcd(b % a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return gcd;
}

bool solve(int a, int b, int c, int& x0, int& y0) {
    int x, y;
    int g = extended_gcd(abs(a), abs(b), x, y);
    if (c % g != 0) {
        return false; 
    }
    x0 = x * (c / g);
    y0 = y * (c / g);
    if (a < 0) x0 = -x0;
    if (b < 0) y0 = -y0;
    return true;
}


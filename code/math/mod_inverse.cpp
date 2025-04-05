int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

array<int, 2> extended_gcd(int a, int b) {
    if (b == 0) return {1, 0};
    auto [x, y] = extended_gcd(b, a % b);
    return {y, x - (a / b) * y};
}

int mod_inverse(int a, int m) {
    auto [x, y] = extended_gcd(a, m);
    return (x % m + m) % m;
}

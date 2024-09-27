ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a % b);
}
ll area_triangulo(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3) {
    return abs(x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2));
}
ll pontos_borda(ll x1, ll y1, ll x2, ll y2) {
    return gcd(abs(x2 - x1), abs(y2 - y1));
}
 
int32_t main() {
    ll x1, y1, x2, y2, x3, y3;
    cin >> x1 >> y1;
    cin >> x2 >> y2;
    cin >> x3 >> y3;
    ll area = area_triangulo(x1, y1, x2, y2, x3, y3);
    ll tot_borda = pontos_borda(x1, y1, x2, y2) + pontos_borda(x2, y2, x3, y3) + pontos_borda(x3, y3, x1, y1);
 
    ll ans = (area - tot_borda) / 2 + 1;
    cout << ans << endl;
 
    return 0;
}
template<typename T, typename U>
ostream& operator<<(ostream& os, const pair<T, U>& p) {
    return os << "(" << p.first << ", " << p.second << ")";
}

template<typename T, typename = decltype(begin(declval<T>())), typename = enable_if_t<!is_same_v<T, string>>>
ostream& operator<<(ostream& os, const T& v) {
    os << "{";
    string sep;
    for (const auto& x : v) os << sep << x, sep = ", ";
    return os << "}";
}

#define db(x...) cout << "[" << #x << "]: ", [](auto... $){ ((cout << $ << "; "), ...); }(x), cout << '\n'

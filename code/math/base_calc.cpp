int char_to_val(char c) {
    if (c >= '0' && c <= '9') return c - '0';
    else return c - 'A' + 10;
}

char val_to_char(int val) {
    if (val >= 0 && val <= 9) return val + '0';
    else return val - 10 + 'A';
}

int to_base_10(string &num, int bfrom) {
    int result = 0;
    int pot = 1;
    for (int i = num.size() - 1; i >= 0; i--) {
        if (char_to_val(num[i]) >= bfrom) return -1;
        result += char_to_val(num[i]) * pot;
        pot *= bfrom;
    }
    return result;
}

string from_base_10(int n, int bto) {
    if (n == 0) return "0";
    string result = "";
    while (n > 0) {
        result += val_to_char(n % bto);
        n /= bto;
    }
    reverse(result.begin(), result.end());
    return result;
}

string convert_base(string &num, int bfrom, int bto) {
    int n_base_10 = to_base_10(num, bfrom);
    return from_base_10(n_base_10, bto);
}
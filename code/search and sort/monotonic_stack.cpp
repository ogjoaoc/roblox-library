vector<int> find_esq(vector<int> &v, bool maior) {
    int n = v.size();
    vector<int> result(n);
    stack<int> s; 

    for (int i = 0; i < n; i++) {
        while (!s.empty() && (maior ? v[s.top()] <= v[i] : v[s.top()] >= v[i])) {
            s.pop();
        }
        if (s.empty()) {
            result[i] = -1; 
        } else {
            result[i] = v[s.top()];
        }
        s.push(i);
    }
    return result;
}

vector<int> find_dir(vector<int> &v, bool maior) {
    int n = v.size();
    vector<int> result(n);
    stack<int> s; 
    for (int i = n - 1; i >= 0; i--) {
        while (!s.empty() && (maior ? v[s.top()] <= v[i] : v[s.top()] >= v[i])) {
            s.pop();
        }
        if (s.empty()) {
            result[i] = -1;
        } else {
            result[i] = v[s.top()];
        }
        s.push(i);
    }
    return result;
}
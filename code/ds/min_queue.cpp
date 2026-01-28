struct MinQueue {
    deque<pair<int, int>> dq;
    void push(int val, int idx) {
        while (!dq.empty() && dq.back().first >= val) dq.pop_back();
        dq.emplace_back(val, idx);
    }
    void pop(int idx) {
        if (!dq.empty() && dq.front().second == idx) {
            dq.pop_front();
        }
    }
    int get() {
        return dq.front().first;
    }
    bool empty() {
        return dq.empty();
    }
};
/*
considerando janela de tamanho K
mq.push(v[i], i);
if (i >= k) {
  mq.pop(i - k); 
}
if (i >= k - 1) {
  result.push_back(mq.get());
}
*/

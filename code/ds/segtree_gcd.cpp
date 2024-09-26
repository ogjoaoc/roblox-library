int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

class SegmentTreeGCD {
private:
    vector<int> tree;
    int n;

    void build(const vector<int>& arr, int node, int start, int end) {
        if (start == end) {
            tree[node] = arr[start];
        } else {
            int mid = (start + end) / 2;
            build(arr, 2 * node + 1, start, mid);
            build(arr, 2 * node + 2, mid + 1, end);
            tree[node] = gcd(tree[2 * node + 1], tree[2 * node + 2]);
        }
    }

    void update(int node, int start, int end, int idx, int value) {
        if (start == end) {
            tree[node] = value;
        } else {
            int mid = (start + end) / 2;
            if (idx <= mid) {
                update(2 * node + 1, start, mid, idx, value);
            } else {
                update(2 * node + 2, mid + 1, end, idx, value);
            }
            tree[node] = gcd(tree[2 * node + 1], tree[2 * node + 2]);
        }
    }

    int query(int node, int start, int end, int l, int r) {
        if (r < start || l > end) {
            return 0;
        }
        if (l <= start && end <= r) {
            return tree[node];
        }
        int mid = (start + end) / 2;
        int left_gcd = query(2 * node + 1, start, mid, l, r);
        int right_gcd = query(2 * node + 2, mid + 1, end, l, r);
        return gcd(left_gcd, right_gcd);
    }

public:
    SegmentTreeGCD(const vector<int>& arr) {
        n = arr.size();
        tree.resize(4 * n);
        build(arr, 0, 0, n - 1); 
    }
    void update(int idx, int value) {
        update(0, 0, n - 1, idx, value);
    }
    int query(int l, int r) {
        return query(0, 0, n - 1, l, r);
    }
};
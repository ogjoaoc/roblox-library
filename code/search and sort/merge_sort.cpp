int mergeAndCount(vector<int>& v, int l, int m, int r) {
    int x = m - l + 1; 
    int y = r - m;  
    vector<int> left(x), right(y);
    for (int i = 0; i < x; i++) left[i] = v[l + i];
    for (int j = 0; j < y; j++) right[j] = v[m + 1 + j];
    int i = 0, j = 0, k = l;  
    int swaps = 0;  
    while (i < x && j < y) {
        if (left[i] <= right[j]) {
            v[k++] = left[i++];
        } else {
            v[k++] = right[j++];
            swaps += (x - i);  
        }
    }
    while (i < x) v[k++] = left[i++];
    while (j < y) v[k++] = right[j++];
    return swaps;  
}

int mergeSort(vector<int>& v, int l, int r) {
    int swaps = 0; 
    if (l < r) {
        int m = l + (r - l) / 2;.
        swaps += mergeSort(v, l, m);
        swaps += mergeSort(v, m + 1, r);
        swaps += mergeAndCount(v, l, m, r);
    }
    return swaps;  
}
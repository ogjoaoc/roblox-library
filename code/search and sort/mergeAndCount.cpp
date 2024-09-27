
// Realiza a mesclagem de dois subarrays e conta o número de trocas necessárias.
int mergeAndCount(vector<int>& v, int l, int m, int r) {
    int x = m - l + 1;  // Tamanho do subarray esquerdo.
    int y = r - m;  // Tamanho do subarray direito.

    // Vetores temporarios para os subarray esquerdo e direito.
    vector<int> left(x), right(y);

    for (int i = 0; i < x; i++) left[i] = v[l + i];
    for (int j = 0; j < y; j++) right[j] = v[m + 1 + j];

    int i = 0, j = 0, k = l;  
    int swaps = 0;  

    while (i < x && j < y) {
        if (left[i] <= right[j]) {
            // Se o elemento da esquerda for menor ou igual, coloca no vetor original.
            v[k++] = left[i++];
        } else {
            // Caso contrario, coloca o elemento da direita e conta as trocas.
            v[k++] = right[j++];
            swaps += (x - i);  
        }
    }

    // Adiciona os elementos restantes do subarray esquerdo (se houver).
    while (i < x) v[k++] = left[i++];

    // Adiciona os elementos restantes do subarray direito (se houver).
    while (j < y) v[k++] = right[j++];

    return swaps;  // Retorna o numero total de trocas realizadas.
}

int mergeSort(vector<int>& v, int l, int r) {
    int swaps = 0; 

    if (l < r) {
        // Encontra o ponto medio para dividir o vetor.
        int m = l + (r - l) / 2;

        // Chama merge sort para a metade esquerda.
        swaps += mergeSort(v, l, m);
        // Chama merge sort para a metade direita.
        swaps += mergeSort(v, m + 1, r);

        // Mescla as duas metades e conta as trocas.
        swaps += mergeAndCount(v, l, m, r);
    }

    return swaps;  // Retorna o numero total de trocas no vetor.
}
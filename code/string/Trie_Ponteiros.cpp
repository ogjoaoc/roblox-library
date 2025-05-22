// Trie por ponteiros
// Inserção, busca e consulta de prefixo em O(N)

struct Node {
    Node *filhos[26] = {};
    bool acaba = false;
    int contador = 0;
};

void insere(string s, Node *raiz) {
    Node *cur = raiz;
    for(auto &c : s) {
        cur->contador++;
        if(cur->filhos[c - 'a'] != NULL) {
            cur = cur->filhos[c - 'a']; 
            continue;
        } 
        cur->filhos[c - 'a'] = new Node();
        cur = cur->filhos[c - 'a']; 
    }
    cur->contador++;
    cur->acaba = true;
}

bool busca(string s, Node *raiz) {
    Node *cur = raiz;
    for(auto &c : s) {
        if (cur->filhos[c - 'a'] != NULL) {
            cur = cur->filhos[c - 'a']; 
            continue;
        }
        return false;
    }
    return cur->acaba;
}

// Retorna se é prefixo e quantas strings tem s como prefixo
int isPref(string s, Node *raiz) { 
    Node *cur = raiz;
    for(auto &c : s) {
        if (cur->filhos[c - 'a'] != NULL) {
            cur = cur->filhos[c - 'a']; 
            continue;
        }
        return -1;
    }
    return cur->contador;
}

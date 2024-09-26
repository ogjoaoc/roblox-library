struct Pessoa{
    // Atributos
    string nome;
    int idade;

    // Comparador
    bool operator<(const Pessoa& other) const{
        if(idade != other.idade) return idade > other.idade;
        else return nome > other.nome;
    }
}
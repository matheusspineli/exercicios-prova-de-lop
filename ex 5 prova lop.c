

#include <stdio.h>

struct Pessoa {
    char nome[50];
    int idade;
};

int main() {
    struct Pessoa p;
    
    printf("Digite o nome:\n");
    scanf("%s", p.nome);
    
    printf("Digite a idade:\n");
    scanf("%d", &p.idade);
    
    printf("Nome: %s\n", p.nome);
    printf("Idade: %d\n", p.idade);
    
    return 0;
}


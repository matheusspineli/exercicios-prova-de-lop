#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char nome[50];
    float preco;
    int quantidade;
} Produto;

Produto produto;

void cadastrarproduto();
void visualizarinformacao();
void realizarcompra();

int main() {
    int op;

    do {
        printf("---------- Seja bem-vindo ao supermercado SuperMais ----------\n");
        printf("1 - Cadastrar um Produto\n");
        printf("2 - Visualizar as informações do produto\n");
        printf("3 - Realizar uma compra\n");
        printf("0 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &op);

        switch (op) {
            case 1:
                cadastrarproduto();
                break;
            case 2:
                visualizarinformacao();
                break;
            case 3:
                realizarcompra();
                break;
            case 0:
                printf("feito\n");
                break;
            default:
                printf("Opção inválida.\n");
        }

        if (op != 0) {
            printf("Pressione enter se quiser continuar...\n");
            getchar(); 
            getchar();
            system("clear");
        }

    } while (op != 0);

    return 0;
}

void cadastrarproduto() {
    printf("---------- Cadastro de Produto ----------");
    printf(" Digite o nome do produto: ");
    getchar(); 
    scanf(" %[^\n]", produto.nome);

    printf("Digite o preço do produto: ");
    scanf("%f", &produto.preco);

    printf(" Digite a quantidade em estoque: ");
    scanf("%d", &produto.quantidade);

    printf("Produto cadastrado com sucesso!\n");
}

void visualizarinformacao() {
    printf("---------- Informações do Produto ----------");
    printf("Nome: %s\n", produto.nome);
    printf("Preço: R$ %.2f\n", produto.preco);
    printf("Quantidade em estoque: %d\n", produto.quantidade);
}

void realizarcompra() {
    int quantidade;

    printf("\n---------- Compra de Produto ----------\n");
    printf("Quantos você deseja comprar? ");
    scanf("%d", &quantidade);

    if (quantidade <= 0) {
        printf("Erro, quantidade inválida.\n");
        return;
    }

    if (quantidade > produto.quantidade) {
        printf("Não temos essa quantidade em estoque, temos apenas %d unidades.\n", produto.quantidade);
    } else {
        //não esquecer que o  robson falou que  o  sinal -= da certo
        produto.quantidade -= quantidade;
        float total = quantidade * produto.preco;
        printf("Sua compra foi realizada com sucesso!\n");
        printf("Total da sua conta é: R$ %.2f\n", total);
        printf("Quantidade em estoque restante: %d\n", produto.quantidade);
    }
}



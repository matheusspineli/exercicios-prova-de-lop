#include <stdio.h>

struct CD {
    int ano;
    int genero;
    int quantidade;
    float preco;
};

struct CD cd[100];
int total = 0;
int op;

void cadastrarCD() {
    printf("---------- seja bem vindo a loja  Som & Arte ----------\n");
    printf("Cadastre o CD:\n");

    printf("Digite o Ano do lançamento do CD:\n");
    scanf("%d", &cd[total].ano);

    printf("escolha o Genero do seu CD: ");
    printf("1 - MPB\n");
    printf("2 - Sertanejo\n");
    printf("3 - Rock\n");
    scanf("%d", &cd[total].genero);

    printf("Quantidade em estoque: ");
    scanf("%d", &cd[total].quantidade);

    printf("Preço: ");
    scanf("%f", &cd[total].preco);

    total = total + 1;
}

void venderCD() {
    int anoBusca;
    int i;
    int quantidadeVenda;

    printf("Digite o ano do CD que deseja comprar: ");
    scanf("%d", &anoBusca);

    for (i = 0; i < total; i++) {
        if (cd[i].ano == anoBusca) {
            if (cd[i].quantidade > 0) {
                printf("Quantidade disponivel: %d\n", cd[i].quantidade);
                printf("Digite a quantidade que quer comprar: ");
                scanf("%d", &quantidadeVenda);

                if (quantidadeVenda <= cd[i].quantidade) {
                    cd[i].quantidade = cd[i].quantidade - quantidadeVenda;
                    float valorFinal = quantidadeVenda * cd[i].preco;
                    printf("O valor total é: R$ %.2f\n", valorFinal);
                } else {
                    printf("Nao temos esta quantidade no estoque!\n");
                }
            } else {
                printf("Este produto ja foi esgotado\n");
            }
            return;
        }
    }

    printf("CD nao encontrado!\n");
}

void pesquisarPorGenero() {
    char bpg;//nao esquecer bpg é busca por genero
    int i;
    int encontrado = 0;
    int op;

    printf("Digite o genero que deseja pesquisar:\n ");
    printf("1 - MPB\n");
    printf("2 - Sertanejo\n");
    printf("3 - Rock\n");
    scanf("%d", &op);

    for (i = 0; i < total; i++) {
        if (cd[i].genero == op) {
            printf("CD Ano: %d\n", cd[i].ano);
            printf("Genero: %d\n", cd[i].genero);
            printf("Quantidade: %d\n", cd[i].quantidade);
            printf("Preco: %.2f\n", cd[i].preco);
            encontrado = 1;
        }
    }

    if (encontrado == 0) {
        printf("Nenhum CD encontrado nesse genero.\n");
    }
}

void consultarCD() {
    int anoBusca;
    int i;

    printf("Digite o ano do CD que deseja achar: ");
    scanf("%d", &anoBusca);

    for (i = 0; i < total; i++) {
        if (cd[i].ano == anoBusca) {
            printf("CD encontrado!\n");
            printf("Ano: %d\n", cd[i].ano);
            printf("Genero: %c\n", cd[i].genero);
            printf("Quantidade: %d\n", cd[i].quantidade);
            printf("Preco: %.2f\n", cd[i].preco);

            if (cd[i].quantidade > 0) {
                printf("Unidades disponiveis em estoque.\n");
            } else {
                printf("Produto esgotado.\n");
            }
            return;
        }
    }

    printf("CD nao encontrado.\n");
}

int main() {
    int op;

    do {
        printf("---------- Sistema de Controle de Estoque - Som & Arte ----------\n");
        printf("1 - Cadastrar CD\n");
        printf("2 - Vender CD\n");
        printf("3 - Pesquisar CDs por Genero\n");
        printf("4 - Consultar os CDs disponiveis\n");
        printf("5 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &op);

        if (op == 1) {
            cadastrarCD();
            
        } else if (op == 2) {
            venderCD();
            
        } else if (op == 3) {
            pesquisarPorGenero();
            
        } else if (op == 4) {
            consultarCD();
            
        } else if (op == 5) {
            printf("Encerrando...\n");
            
        } else {
            printf("Opção invalida.\n");
        }

    } while (op != 5);

    return 0;
}





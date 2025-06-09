#include <stdio.h>
#include<stdlib.h>

typedef struct {
	char nome[30];
	float preco;
}Pizza;

typedef struct{
	char nome[50], telefone[11];
;}Cliente;

Cliente bonito[100];
Pizza pizza[30];

void cadastrarCliente();
void cadastrarProduto();
void listarCliente();
void listarPizza();
void venderPizzas();

int robson=0;
int reenye=0;

int main() {
	
	int op;
	
	do{
		
		printf("---------- Seja bem vindo a Nostra Pizza----------\n");
		printf("1 - Cadastrar Cliente\n");
		printf("2 - Cadastrar Produto\n");
		printf("3 - Listar Clientes\n");
		printf("4 - Listar Produtos\n");
		printf("5 - Vender Pizzas\n");
		printf("0 - Sair\n");
		scanf("%d", &op);
		
		switch(op) {
			case 1:
				cadastrarCliente();
			break;
			
			case 2:
				cadastrarProduto();
			break;
			
			case 3:
				if(robson==0) {
					printf("Cadastre um Cliente Primeiro");
					printf("Cliente Cadastrado\n");
				    printf("Aperte ENTER para Voltar...\n");
				    getchar();
				    getchar();
				}
				
				else{
					listarCliente();
				}
				
			break;
			
			case 4:
				if(reenye==0) {
					printf("Cadastre um Produto antes\n");
					printf("Cliente Cadastrado!\n");
				    printf("clique ENTER para Voltar...\n");
				    getchar();
				    getchar();
				}
				
				else{
					listarPizza();
				}
			break;
			
			case 5:
				if(robson==0) {
					printf("Cadastre um Cliente antes.\n");
					printf("Cliente Cadastrado!\n");
				    printf("Aperte ENTER para Voltar...\n");
				    getchar();
				    getchar();
				}
				
				else if(reenye==0) {
					printf("Cadastre um Produto antes.\n");
					printf("Cliente Cadastrado!\n");
				    printf("Aperte ENTER para Voltar...\n");
				    getchar();
				    getchar();
				}
				
				else {
					venderPizzas();
				}
			break;
			
			
			case 0:
			break;
						
			default:
			break;
		}	
	}while(op!=6);

return 0;

}

void cadastrarCliente() {
				
				printf(" Cliente %d\n", robson + 1);
				
				printf("Digite o seu nome: ");
				scanf("%s", bonito[robson].nome);
				
				printf("Cliente Cadastrado!\n");
				printf("\nAperte ENTER para Voltar...\n");
				getchar();
				getchar();
				robson++;
}

void cadastrarProduto() {
	printf(" %d",  reenye + 1);
				
				printf("Informe o nome: ");
				scanf("%s", pizza[reenye].nome);
				
				printf("Informe o preco: ");
				scanf("%f", &pizza[reenye].preco);
				
				printf("Produto Cadastrado!\n");
				printf("clique ENTER para Voltar...\n");
				getchar();
				getchar();
				reenye++;
}

void listarCliente() {
	for(int i=0; i<robson; i++) {
		printf("\n-- Cliente %d --\n", i+1);
		printf("Nome: %s\n", bonito[i].nome);
	}
	
	printf("clique ENTER para Voltar...\n");		
	getchar();
	getchar();
}

void listarPizza() {
	for(int i=0; i<reenye; i++) {
		printf("Pizza %d\n", i+1);
		printf("Nome: %s\n", pizza[i].nome);
		printf("Preço: %.2f\n", pizza[i].preco);
	}
	
	printf("clique ENTER para Voltar...\n");		
	getchar();
	getchar();
}

void venderPizzas() {
	int op, i, q;

    do {
        printf("---------- NostraPizza ----------\n");

        for(i = 0; i < reenye; i++) {
            printf("%d. %s - R$%.2f\n", i + 1, pizza[i].nome, pizza[i].preco);
        }
        printf("%d. Voltar\n", reenye + 1);
        scanf("%d", &op);

        if(op == reenye + 1) {
            break;
        } 
		
		else if(op >= 1 && op <= reenye) {
            int v = op - 1;

            printf("Digite a quantidade desejada: ");
            scanf("%d", &q);

            if(q <= 0) {
                printf("Quantidade indisponivel.\n");
            } 
			
			
			else {
                float total = pizza[v].preco * q;
                printf("%d %s\n", q, pizza[v].nome);
                printf(" Preço Total: R$%.2f\n", total);
            }

            printf("Aperte ENTER para continuar...\n");
            getchar(); 
			getchar();

        } 
		
		else {
            printf("Opção inválida!\n");
            printf("Aperte ENTER para continuar...\n");
            getchar(); 
			getchar();
        }

    } while(1);
}





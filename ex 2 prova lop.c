
#include <stdio.h>

struct Aluno {
    char nome[50];
    int idade;
    float nota;
};

 struct Aluno alunos[3];

void listarAlunos() {
    for (int i = 0; i < 3; i++) {
        printf("\nAluno %d:\n", i + 1);
        printf("Nome : %s\n", alunos[i].nome);
        printf("Idade : %d\n", alunos[i].idade);
        printf("Nota : %.2f\n", alunos[i].nota);
    }
}

int main() {
    for (int i = 0; i < 3; i++) {
        printf("Digite os dados do aluno %d:\n", i + 1);

        printf("Digite o nome do aluno:\n");
        scanf("%s", alunos[i].nome);

        printf("Digite a idade do aluno:\n");
        scanf("%d", &alunos[i].idade);

        printf("Digite a nota do aluno:\n");
        scanf("%f", &alunos[i].nota);
    }

    listarAlunos();

    return 0;
}


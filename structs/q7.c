#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[100];
    int matricula;
    float media;
} Aluno;

int main() {
    int n;
    Aluno *alunos;

    printf("Quantos alunos deseja cadastrar? ");
    scanf("%d", &n);
    getchar(); 
    
    alunos = (Aluno *) malloc(n * sizeof(Aluno));
    if (alunos == NULL) {
        printf("Erro de alocação de memória!\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        printf("\n--- Aluno %d ---\n", i + 1);

        printf("Nome: ");
        fgets(alunos[i].nome, sizeof(alunos[i].nome), stdin);
        alunos[i].nome[strcspn(alunos[i].nome, "\n")] = '\0';

        printf("Matrícula: ");
        scanf("%d", &alunos[i].matricula);

        printf("Média: ");
        scanf("%f", &alunos[i].media);
        getchar();
    }

    printf("\n--- Alunos Aprovados ---\n");
    for (int i = 0; i < n; i++) {
        if (alunos[i].media >= 7.0) {
            printf("Nome: %s | Matrícula: %d | Média: %.2f\n",
                   alunos[i].nome, alunos[i].matricula, alunos[i].media);
        }
    }


    free(alunos);

    return 0;
}

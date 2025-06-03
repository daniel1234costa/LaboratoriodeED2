#include <stdio.h>
#include <stdbool.h>

bool ja_existe(int vetor[], int tamanho, int valor) {
    for (int i = 0; i < tamanho; i++) {
        if (vetor[i] == valor) {
            return true;
        }
    }
    return false;
}

int main() {
    int n1, n2;
    printf("Digite o tamanho do primeiro vetor: ");
    scanf("%d", &n1);

    int vetor1[n1];
    printf("Digite os %d elementos do primeiro vetor:\n", n1);
    for (int i = 0; i < n1; i++) {
        scanf("%d", &vetor1[i]);
    }

    printf("Digite o tamanho do segundo vetor: ");
    scanf("%d", &n2);

    int vetor2[n2];
    printf("Digite os %d elementos do segundo vetor:\n", n2);
    for (int i = 0; i < n2; i++) {
        scanf("%d", &vetor2[i]);
    }

    int intersecao[n1 < n2 ? n1 : n2];
    int tamanho_intersecao = 0;
    
    for (int i = 0; i < n1; i++) {
        for (int j = 0; j < n2; j++) {
            if (vetor1[i] == vetor2[j]) {
                if (!ja_existe(intersecao, tamanho_intersecao, vetor1[i])) {
                    intersecao[tamanho_intersecao++] = vetor1[i];
                }
            }
        }
    }

    if (tamanho_intersecao == 0) {
        printf("Nenhum elemento em comum.\n");
    } else {
        printf("Elementos comuns:\n");
        for (int i = 0; i < tamanho_intersecao; i++) {
            printf("%d ", intersecao[i]);
        }
        printf("\n");
    }

    return 0;
}


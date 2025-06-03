#include <stdio.h>

int buscaBinaria(int arr[], int tamanho, int alvo) {
    int inicio = 0;
    int fim = tamanho - 1;

    while (inicio <= fim) {
        int meio = inicio + (fim - inicio) / 2;

        if (arr[meio] == alvo) {
            return meio; 
        }

        if (arr[meio] < alvo) {
            inicio = meio + 1;
        } else {
            fim = meio - 1; 
        }
    }
    return -1; 
}

int main() {
    int vetor[] = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
    int tamanho = sizeof(vetor) / sizeof(vetor[0]);
    int alvo = 23; 
    int indice = buscaBinaria(vetor, tamanho, alvo);

    if (indice != -1) {
        printf("Elemento %d encontrado no índice %d\n", alvo, indice);
    } else {
        printf("Elemento %d não encontrado no vetor\n", alvo);
    }
    return 0;
}
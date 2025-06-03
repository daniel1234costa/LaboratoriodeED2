#include <stdio.h>

int somaDiagonalPrincipal(int matriz[4][4]) {
    int soma = 0;
    for (int i = 0; i < 4; i++) {
        soma += matriz[i][i];
    }
    return soma;
}

int main() {
    int matriz[4][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };

    printf("A soma da diagonal principal da matriz é: %d\n", somaDiagonalPrincipal(matriz));
    return 0;
}
#include <stdio.h>

int main() {
    int numeros[10];
    int i, j;
    int contado[10] = {0}; 
    printf("Digite 10 números inteiros:\n");
    for (i = 0; i < 10; i++) {
        scanf("%d", &numeros[i]);
    }

    printf("\nFrequência de cada número distinto:\n");

    for (i = 0; i < 10; i++) {
        if (contado[i] == 1)
            continue;

        int contador = 1;
        for (j = i + 1; j < 10; j++) {
            if (numeros[i] == numeros[j]) {
                contador++;
                contado[j] = 1;
            }
        }

        printf("%d aparece %d vez(es)\n", numeros[i], contador);
    }

    return 0;
}

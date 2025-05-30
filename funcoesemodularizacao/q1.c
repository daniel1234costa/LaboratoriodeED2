#include <stdio.h>
#include <stdbool.h>

bool ehPrimo(int n) {
    if (n <= 1) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

int main() {
    int inicio, fim;

    printf("Digite o valor inicial do intervalo: ");
    scanf("%d", &inicio);

    printf("Digite o valor final do intervalo: ");
    scanf("%d", &fim);

    printf("Números primos entre %d e %d:\n", inicio, fim);
    for (int i = inicio; i <= fim; i++) {
        if (ehPrimo(i)) {
            printf("%d ", i);
        }
    }
    printf("\n");

    return 0;
}

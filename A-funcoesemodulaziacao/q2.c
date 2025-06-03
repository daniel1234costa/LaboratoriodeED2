#include <stdio.h>

int potencia(int base, int expoente) {
    int resultado = 1;

    for (int i = 0; i < expoente; i++) {
        resultado *= base;
    }

    return resultado;
}

int main() {
    int base, expoente;

    printf("Digite a base: ");
    scanf("%d", &base);

    printf("Digite o expoente : (>=0)\n");
    scanf("%d", &expoente);

    if (expoente < 0) {
        printf("Erro!! expoente negativo.\n");
    } else {
        int resultado = potencia(base, expoente);
        printf("%d elevado a %d = %d\n", base, expoente, resultado);
    }

    return 0;
}

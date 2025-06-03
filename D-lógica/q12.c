#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool ehPalindromo(const char *str) {
    int esquerda = 0;
    int direita = strlen(str) - 1;

    while (esquerda < direita) {
        if (str[esquerda] != str[direita]) {
            return false; 
        esquerda++;
        direita--;
    }
    return true; }}

int main() {
    const char *palavra1 = "arara";
    const char *palavra2 = "programacao"; 

    printf("\"%s\" é um palíndromo? %s\n", palavra1, ehPalindromo(palavra1) ? "Sim" : "Não");
    printf("\"%s\" é um palíndromo? %s\n", palavra2, ehPalindromo(palavra2) ? "Sim" : "Não");
    return 0;
}
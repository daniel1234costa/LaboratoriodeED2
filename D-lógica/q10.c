#include <stdio.h>

long long fibonacciRecursivo(int n) {
    if (n <= 1) {
        return n;
    }
    return fibonacciRecursivo(n - 1) + fibonacciRecursivo(n - 2);
}

int main() {
    int n = 10;
    printf("O %d-ésimo número de Fibonacci é: %lld\n", n, fibonacciRecursivo(n));
    return 0;
}
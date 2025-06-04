#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h> 
#include <time.h>   


void exibirForca(int erros) {
    printf("\n");
    printf("  +---+\n");
    printf("  |   |\n");
    printf("  %c   |\n", (erros >= 1) ? 'O' : ' ');
    printf(" %c%c%c  |\n", (erros >= 3) ? '/' : ' ', (erros >= 2) ? '|' : ' ', (erros >= 4) ? '\\' : ' ');
    printf(" %c %c  |\n", (erros >= 5) ? '/' : ' ', (erros >= 6) ? '\\' : ' ');
    printf("      |\n");
    printf("=========\n");
}

int main() {
    
    char *palavras[] = {
        "COMPUTADOR",
        "PROGRAMACAO",
        "ALGORITMO",
        "DESENVOLVIMENTO",
        "TECLADO",
        "MONITOR",
        "MOUSE",
        "SOFTWARE",
        "HARDWARE",
        "INTERNET"
    };
    int numPalavras = sizeof(palavras) / sizeof(palavras[0]);


    srand(time(NULL));


    int indiceAleatorio = rand() % numPalavras;
    char palavraSecreta[20];
    strcpy(palavraSecreta, palavras[indiceAleatorio]);

    int tamanhoPalavra = strlen(palavraSecreta);
    char palavraAdivinhada[20]; 
    char letrasTentadas[27];    
    int numErros = 0;
    int letrasCorretas = 0;
    int tentativasLetras = 0; 

    
    for (int i = 0; i < tamanhoPalavra; i++) {
        palavraAdivinhada[i] = '_';
    }
    palavraAdivinhada[tamanhoPalavra] = '\0'; 

    
    for (int i = 0; i < 27; i++) {
        letrasTentadas[i] = '\0';
    }

    printf("Bem-vindo ao Jogo da Forca!\n");
    printf("Tente adivinhar a palavra.\n");

    while (numErros < 6 && letrasCorretas < tamanhoPalavra) {
        exibirForca(numErros);
        printf("\nPalavra: %s\n", palavraAdivinhada);
        
        printf("Letras já tentadas: ");
        for (int i = 0; i < tentativasLetras; i++) {
            printf("%c ", letrasTentadas[i]);
        }
        printf("\n");

        char palpite;
        printf("Digite uma letra: ");
        scanf(" %c", &palpite); 

    
        palpite = toupper(palpite);

        
        bool letraJaTentada = false;
        for (int i = 0; i < tentativasLetras; i++) {
            if (letrasTentadas[i] == palpite) {
                letraJaTentada = true;
                break;
            }
        }

        if (letraJaTentada) {
            printf("Você já tentou esta letra. Tente outra.\n");
            continue;
        }

    
        letrasTentadas[tentativasLetras++] = palpite;

        bool acertou = false;
        for (int i = 0; i < tamanhoPalavra; i++) {
            if (palavraSecreta[i] == palpite) {
                if (palavraAdivinhada[i] == '_') { 
                    palavraAdivinhada[i] = palpite;
                    letrasCorretas++;
                }
                acertou = true;
            }
        }

        if (acertou) {
            printf("Boa! A letra '%c' está na palavra.\n", palpite);
        } else {
            printf("Que pena! A letra '%c' não está na palavra.\n", palpite);
            numErros++;
        }
    }

    exibirForca(numErros);
    printf("\nPalavra: %s\n", palavraAdivinhada);

    if (letrasCorretas == tamanhoPalavra) {
        printf("\nPARABÉNS! Você adivinhou a palavra: %s\n", palavraSecreta);
    } else {
        printf("\nVOCÊ PERDEU! A palavra secreta era: %s\n", palavraSecreta);
    }

    return 0;
}
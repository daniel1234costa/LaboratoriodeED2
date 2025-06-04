#include <stdio.h>
#include <string.h>
#include <ctype.h> 

void cifraCesar(char *str, int deslocamento) {
    int i = 0;
    while (str[i] != '\0') {
        char caractereAtual = str[i];

    
        if (isalpha(caractereAtual)) {
        
            if (isupper(caractereAtual)) {
                str[i] = (char)(((caractereAtual - 'A' + deslocamento) % 26) + 'A');
            }
        
            else if (islower(caractereAtual)) {
                str[i] = (char)(((caractereAtual - 'a' + deslocamento) % 26) + 'a');
            }
        }
       
        i++;
    }
}

int main() {
    char mensagem[] = "Hello, World! 123";
    int chave = 3; 

    printf("Mensagem original: %s\n", mensagem);
    cifraCesar(mensagem, chave);
    printf("Mensagem criptografada (chave %d): %s\n", chave, mensagem);

    char outraMensagem[] = "Cifra de Cesar";
    int outraChave = 5;

    printf("\nOutra mensagem original: %s\n", outraMensagem);
    cifraCesar(outraMensagem, outraChave);
    printf("Outra mensagem criptografada (chave %d): %s\n", outraChave, outraMensagem);
    
    return 0;
}
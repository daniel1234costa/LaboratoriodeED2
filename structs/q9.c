#include <stdio.h>
#include <string.h>

#define MAX 100

typedef struct {
    char nome[100];
    char telefone[20];
    char email[100];
} Contato;

void adicionarContato(Contato contatos[], int *n) {
    if (*n >= MAX) {
        printf("Agenda cheia. Não é possível adicionar mais contatos.\n");
        return;
    }

    printf("\n--- Adicionar Contato ---\n");
    getchar();

    printf("Nome: ");
    fgets(contatos[*n].nome, sizeof(contatos[*n].nome), stdin);
    contatos[*n].nome[strcspn(contatos[*n].nome, "\n")] = '\0';

    printf("Telefone: ");
    fgets(contatos[*n].telefone, sizeof(contatos[*n].telefone), stdin);
    contatos[*n].telefone[strcspn(contatos[*n].telefone, "\n")] = '\0';

    printf("Email: ");
    fgets(contatos[*n].email, sizeof(contatos[*n].email), stdin);
    contatos[*n].email[strcspn(contatos[*n].email, "\n")] = '\0';

    (*n)++;
    printf("Contato adicionado com sucesso!\n");
}

void buscarContato(Contato contatos[], int n) {
    char nomeBusca[100];
    int encontrado = 0;

    printf("\nDigite o nome do contato a buscar: ");
    getchar();
    fgets(nomeBusca, sizeof(nomeBusca), stdin);
    nomeBusca[strcspn(nomeBusca, "\n")] = '\0';

    for (int i = 0; i < n; i++) {
        if (strcmp(contatos[i].nome, nomeBusca) == 0) {
            printf("Contato encontrado:\n");
            printf("Nome: %s | Telefone: %s | Email: %s\n",
                   contatos[i].nome, contatos[i].telefone, contatos[i].email);
            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("Contato não encontrado.\n");
    }
}

void exibirContatos(Contato contatos[], int n) {
    if (n == 0) {
        printf("\nNenhum contato na agenda.\n");
        return;
    }

    printf("\n--- Lista de Contatos ---\n");
    for (int i = 0; i < n; i++) {
        printf("%d - Nome: %s | Telefone: %s | Email: %s\n",
               i + 1, contatos[i].nome, contatos[i].telefone, contatos[i].email);
    }
}

int main() {
    Contato contatos[MAX];
    int n = 0;
    int opcao;

    do {
        printf("\n===== MENU AGENDA =====\n");
        printf("1 - Adicionar contato\n");
        printf("2 - Buscar por nome\n");
        printf("3 - Exibir todos os contatos\n");
        printf("0 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                adicionarContato(contatos, &n);
                break;
            case 2:
                buscarContato(contatos, n);
                break;
            case 3:
                exibirContatos(contatos, n);
                break;
            case 0:
                printf("Saindo da agenda...\n");
                break;
            default:
                printf("Opção inválida.\n");
        }

    } while (opcao != 0);

    return 0;
}

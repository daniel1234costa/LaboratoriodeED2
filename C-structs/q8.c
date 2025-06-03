#include <stdio.h>
#include <string.h>

#define MAX 100

typedef struct {
    char nome[100];
    int codigo;
    int quantidade;
    float preco;
} Produto;

void cadastrarProduto(Produto produtos[], int *n) {
    if (*n >= MAX) {
        printf("Limite de produtos atingido.\n");
        return;
    }

    printf("\n--- Cadastro de Produto ---\n");
    printf("Nome: ");
    getchar(); 
    fgets(produtos[*n].nome, sizeof(produtos[*n].nome), stdin);
    produtos[*n].nome[strcspn(produtos[*n].nome, "\n")] = '\0';

    printf("Código: ");
    scanf("%d", &produtos[*n].codigo);

    printf("Quantidade: ");
    scanf("%d", &produtos[*n].quantidade);

    printf("Preço: ");
    scanf("%f", &produtos[*n].preco);

    (*n)++;
    printf("Produto cadastrado com sucesso!\n");
}

void buscarProduto(Produto produtos[], int n) {
    int codigo;
    printf("\nDigite o código do produto a buscar: ");
    scanf("%d", &codigo);

    for (int i = 0; i < n; i++) {
        if (produtos[i].codigo == codigo) {
            printf("Produto encontrado:\n");
            printf("Nome: %s | Código: %d | Quantidade: %d | Preço: R$%.2f\n",
                   produtos[i].nome, produtos[i].codigo, produtos[i].quantidade, produtos[i].preco);
            return;
        }
    }
    printf("Produto não encontrado.\n");
}

void listarProdutos(Produto produtos[], int n) {
    if (n == 0) {
        printf("\nNenhum produto cadastrado.\n");
        return;
    }

    printf("\n--- Lista de Produtos ---\n");
    for (int i = 0; i < n; i++) {
        printf("%d - %s | Código: %d | Quantidade: %d | Preço: R$%.2f\n",
               i + 1, produtos[i].nome, produtos[i].codigo, produtos[i].quantidade, produtos[i].preco);
    }
}

int main() {
    Produto produtos[MAX];
    int n = 0;
    int opcao;

    do {
        printf("\n===== MENU =====\n");
        printf("1 - Cadastrar produto\n");
        printf("2 - Buscar produto\n");
        printf("3 - Listar produtos\n");
        printf("0 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastrarProduto(produtos, &n);
                break;
            case 2:
                buscarProduto(produtos, n);
                break;
            case 3:
                listarProdutos(produtos, n);
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida!\n");
        }

    } while (opcao != 0);

    return 0;
}

#include<stdio.h>
int main (){
    int mat[3][3];
    int mat2[3][3];
    int cont = 1;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            printf("Informe o %d numero da primeira matriz:\n",cont++ );
            scanf("%d", &mat[i][j]);
        }

    }
     cont = 1;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            printf("Informe o %d numero da segunda matriz:\n",cont++ );
            scanf("%d", &mat2[i][j]);
        }

    }
    int soma = 0;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            
            soma = soma + (mat[i][j] + mat2[i][j]);
        }

    }
    printf("A soma dos elementos das duas matrizes é igual a : %d\n", soma);





    return 0;
}
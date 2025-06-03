#include<stdio.h>
void inversor(int n, int vet[]){

printf("A sequencia invertida e:\n\n");   

for(int i = n; i >= 0; i--){
    printf("%d\n", vet[i]);


}

}
int main (){
    int tam;
printf("Informe quantos numeros deseja adicionar:\n");
scanf("%d", &tam);
int vet[tam];
for(int i = 0; i <= tam -1; i++){
printf("informe o %d numero:\n", i + 1);
scanf("%d", &vet[i]);

} 
printf("\n\n");

inversor(tam-1, vet);


    return 0;
}

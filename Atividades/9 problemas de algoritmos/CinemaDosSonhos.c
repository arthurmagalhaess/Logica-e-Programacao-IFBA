#include <stdio.h> 
#include <stdlib.h> 

//História: Maria quer assistir a um filme proibido para menores de 16 anos. O programa deve verificarse ela tem idade suficiente.
#define IDADE_MIN 16

int main(){

    int idade;
    printf("Digite sua idade: ");
    scanf("%d", &idade);

    if(idade >= IDADE_MIN){
        printf("Voce pode assistir ao filme");
    }
    else{
        printf("Voce nao pode assistir ao filme");
    }

    return 0;
}
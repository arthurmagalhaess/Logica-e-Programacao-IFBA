#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Algoritmo 7.2.8: Considerando o registro de um produto de uma loja contendo as informações de descrição e valor, fazer um programa que, dado o registro de 50 produtos, os exiba na ordem inversa em que foram digitados.

int main(){
    struct produtoRegistro{
        char nome[50];
        float valor;
    };

    struct produtoRegistro item[50];


    for (int i = 0; i < 50; i++)
    {
        printf("PRODUTO %d\n", i+1);
        printf("Nome do produto: ");
        fgets(item[i].nome, 50, stdin);
        item[i].nome[strcspn(item[i].nome, "\n")] = '\0';

        printf("Valor: ");
        scanf("%f", &item[i].valor);
        getchar();
    }
    printf("\n----DADOS----\n");
    for (int i = 49; i >= 0; i--)
    {
        printf("PRODUTO %d\n", i+1);
        printf("Nome: %s\nValor: %.2f\n", item[i].nome, item[i].valor);

    }
    
    return 0;
}

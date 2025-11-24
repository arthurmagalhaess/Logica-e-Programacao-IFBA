#include <stdio.h>
#include <stdlib.h>

// Algoritmo 7.2.7: Montar uma estrutura que faça a simulação de um estoque com os seguintes dados: Valor unitário, quantidade armazenada e quantidade vendida. Esse controle tem 10 itens. Ao final, imprimir o valor unitário, quantidade armazenada, quantidade vendida e quantidade do estoque atual. Se a quantidade vendida for zero, mostrar a mensagem “Produto Encalhado!”
int main()
{
    struct produto
    {
        float valorUnitario;
        int quantidade;
        int vendas;
    };
    struct produto item[10];
    printf("ESTOQUE");
    for (int i = 0; i < 10; i++)
    {
        printf("\n-----PRODUTO %d-----\n", i + 1);
        printf("Valor unitario: ");
        scanf("%f", &item[i].valorUnitario);
        printf("Quantidade Armazenada: ");
        scanf("%d", &item[i].quantidade);
        printf("Quantidade Vendida: ");
        scanf("%d", &item[i].vendas);
    }
    printf("\n-----DADOS-----\n");
    for (int i = 0; i < 10; i++)
    {
        printf("PRODUTO %d\n", i + 1);
        printf("Valor unitario do produto: %.2f\nQuantidade em estoque: %d\nQuantidade vendida: %d\n", item[i].valorUnitario, item[i].quantidade, item[i].vendas);
        if (item[i].vendas == 0)
        {
            printf("Produto Encalhado!\n");
        }
    }
    return 0;
}
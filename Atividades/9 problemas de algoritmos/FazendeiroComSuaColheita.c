#include <stdio.h> 
#include <stdlib.h> 

//História: Um fazendeiro quer calcular quantas caixas de maçãs ele pode encher com sua colheitadiária. Cada caixa comporta 20 maçãs. 

#define QUANT_CAIXA 20 
int main()
{ 
    int colheitaDiaria, quantCaixas, sobra; 
    printf("Quantidade de macas colhidas: "); 
    scanf("%d", &colheitaDiaria); 

    quantCaixas = colheitaDiaria/QUANT_CAIXA;
    sobra = colheitaDiaria%QUANT_CAIXA;

    printf("Quantidade de Caixas cheias: %d \nQuantidade de macas que sobrou: %d", quantCaixas, sobra);

    return 0; 
}
#include <stdio.h> 
#include <stdlib.h> 

//História: Uma cafeteria cobra R$ 5,00 por café. Se o cliente comprar mais de 3 cafés, ganha umdesconto de 10%.


int main(){
    float precoDoCafe = 5, valorParaPagar;
    int cafesComprados;

    printf("Quantos cafes voce vai comprar?: ");
    scanf("%d", &cafesComprados);

    if(cafesComprados <= 3){
        valorParaPagar = cafesComprados * precoDoCafe;
    }else{
        valorParaPagar = (cafesComprados * precoDoCafe) * 0.9;
    }

    printf("Valor a pagar: %.2f", valorParaPagar);

    return 0;
}
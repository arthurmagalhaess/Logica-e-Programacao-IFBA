#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//História: Um programa gera um número aleatório entre 1 e 10. O jogador deve adivinhar até acertar

int main(){
    
    srand(time(NULL));
    int numeroSorteado = rand() % 10 + 1;
    int palpite, n = 0;
    printf("Digite seus palpites abaixo\n");

    do
    {
        n++;
        printf("Palpite %d: ", n);
        scanf("%d", &palpite);
    } while (palpite != numeroSorteado);
    
    printf("Parabens, voce acertou!!");


    return 0;
}
#include <stdio.h> 
#include <stdlib.h> 

//História: Um pirata precisa acertar a senha numérica (1234) para abrir um baú. Ele tem 3 tentativas.

#define SENHA 1234
#define QUANT_DE_TENTATIVAS 3

int main(){
    int tentativa, senhaColocada;
    for(tentativa = 0; tentativa < QUANT_DE_TENTATIVAS; tentativa++){
        printf("Tentativa %d. Digite uma senha e tente acertar: ", tentativa + 1);
        scanf("%d", &senhaColocada);
        if(senhaColocada == SENHA){
            tentativa = 3;
            printf("Parabens, vc acertou!!!!");
        }
        else{
            if(tentativa < 2){
                printf("Voce errou, continue tentando!\n");
            }else{
                printf("Voce falhou, acabaram suas tentativas");
            }
        }
    }

    return 0;
}
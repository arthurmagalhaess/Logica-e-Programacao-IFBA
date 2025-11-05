#include <stdio.h> 
#include <stdlib.h> 

//História: Um corredor quer saber se bateu seu recorde pessoal de 42 km. O programa deve comparar adistância percorrida com o recorde.

#define RECORDE 42

int main(){

    float distanciaPercorrida;
    printf("Distancia percorrida hoje: ");
    scanf("%f", &distanciaPercorrida);

    if(distanciaPercorrida > RECORDE){
        printf("Parabens, voce bateu seu recorde");
    }
    else if(distanciaPercorrida == RECORDE){
        printf("Voce igualou com seu recorde");
    }
    else{
        printf("Continue treinando");
    }

    return 0;
}
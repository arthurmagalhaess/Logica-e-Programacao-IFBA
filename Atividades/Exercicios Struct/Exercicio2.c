#include <stdio.h>
#include <stdlib.h>

//Exercicio: Declare uma estrutura capaz de armazenar o número, 3 notas para um dado aluno e a média dele, e faça um programa para ler o número e as 3 notas de 10 alunos.

int main(){
    struct aluno
    {
        int numeroDoAluno;
        float nota[3];
        float media;
    };

    struct aluno a[10];
    
    for(int i=0; i < 10; i++){
        printf("Numero do aluno: ");
        scanf("%d", &a[i].numeroDoAluno);
        float somaTotal = 0;
        for(int j=0; j < 3; j++){
            printf("Nota %d: ", j + 1);
            scanf("%f", &a->nota[j]);
            somaTotal += a->nota[j];
        }
        a[i].media = somaTotal/3;
        printf("Media do aluno %d: %.2f\n", a[i].numeroDoAluno, a[i].media);
    }


    return 0;
}
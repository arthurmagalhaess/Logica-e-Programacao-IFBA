#include <stdio.h>

//Algoritmo 7.2.4: Considerando o algoritmo 7.2.3, criar uma variável que é um vetor da estrutura DadosAluno. O programa deve calcular a média e a idade de 10 alunos. Depois, esses dados devem ser exibidos.

struct DadosAluno {
    float nota1;
    float nota2;
    int idade;
};

int main() {
    struct DadosAluno alunos[10];
    float medias[10];
    int i;

    
    for (i = 0; i < 10; i++) {
        printf("\n--- Aluno %d ---\n", i + 1);

        printf("Digite a primeira nota: ");
        scanf("%f", &alunos[i].nota1);

        printf("Digite a segunda nota: ");
        scanf("%f", &alunos[i].nota2);

        printf("Digite a idade: ");
        scanf("%d", &alunos[i].idade);

        medias[i] = (alunos[i].nota1 + alunos[i].nota2) / 2;
    }

    
    printf("\n=== Resultados ===\n");
    for (i = 0; i < 10; i++) {
        printf("\nAluno %d:\n", i + 1);
        printf("Media: %.2f\n", medias[i]);
        printf("Idade: %d\n", alunos[i].idade);
    }

    return 0;
}

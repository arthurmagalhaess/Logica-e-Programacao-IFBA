#include <stdio.h>

//Algoritmo 7.2.3: Criar uma estrutura chamada DadosAluno, que armazena duas notas e a idade de um aluno. Ler as notas e a idade do aluno e armazenar na variável criada na struct; exibir na tela a média das notas e a idade do aluno.

struct DadosAluno {
    float nota1;
    float nota2;
    int idade;
};

int main() {
    struct DadosAluno aluno;
    float media;

    printf("Digite a primeira nota: ");
    scanf("%f", &aluno.nota1);

    printf("Digite a segunda nota: ");
    scanf("%f", &aluno.nota2);

    printf("Digite a idade do aluno: ");
    scanf("%d", &aluno.idade);

    media = (aluno.nota1 + aluno.nota2) / 2;

    printf("\n--- Resultado ---\n");
    printf("Media das notas: %.2f\n", media);
    printf("Idade do aluno: %d\n", aluno.idade);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Algoritmo 7.2.10: Em uma pesquisa de campo envolvendo 250 entrevistados, uma editora solicitou os seguintes dados aos entrevistados: sexo, idade e quantidade de livros que leu no ano de 2009. Fazer um programa que leia os dados digitados pelo usuário e ao final, calcule e imprima: a) A quantidade total de livros lidos pelos entrevistados menores de 10 anos. b) A quantidade de mulheres que leram 5 livros ou mais. c) A média de idade dos homens que leram menos que 5 livros. d) O percentual de pessoas que não leram livros.

#define QTD_DE_ENTREVISTADOS 250

int main(){
    struct Entrevistado
    {
        char sexo;
        int idade;
        int qtdLivros;
    };

    struct Entrevistado pessoas[QTD_DE_ENTREVISTADOS];
    int qtdLivrosMenores10 = 0, qtdMulheres5Livros = 0, totalIdadeHomens = 0, qtdHomensMenosQue5 = 0, qtdPessoasQueNaoLeram = 0;
    float mediaIdadeHomensMenosQue5 = 0, percentualNaoLeram = 0;

    for (int i = 0; i < QTD_DE_ENTREVISTADOS; i++)
    {
        printf("---PESSOA %d---\n", i+1);
        printf("Idade: ");
        scanf("%d", &pessoas[i].idade);
        getchar();
        printf("Sexo [M/F]: ");
        scanf(" %c", &pessoas[i].sexo);
        printf("Quantidade de livros lidos em 2009: ");
        scanf("%d", &pessoas[i].qtdLivros);
    }
    for (int i = 0; i < QTD_DE_ENTREVISTADOS; i++)
    {
        if(pessoas[i].idade < 10){
            qtdLivrosMenores10 += pessoas[i].qtdLivros;
        }
        if (pessoas[i].sexo == 'F')
        {
            if(pessoas[i].qtdLivros >= 5){
                qtdMulheres5Livros++;   
            }
        }
        if(pessoas[i].sexo == 'M'){
            if(pessoas[i].qtdLivros < 5){
                qtdHomensMenosQue5++;
                totalIdadeHomens += pessoas[i].idade;
            }
        }
        if(pessoas[i].qtdLivros == 0){
            qtdPessoasQueNaoLeram++;
        }
        
    }

    mediaIdadeHomensMenosQue5 = totalIdadeHomens/qtdHomensMenosQue5;
    percentualNaoLeram = 100 * qtdPessoasQueNaoLeram / QTD_DE_ENTREVISTADOS;

    printf("Quantidade total de livros lidos por entrevistados menores de 10 anos: %d\nQuantidade de mulheres que leram 5 livros ou mais: %d\nMedia de idade dos homens que leram 5 livros ou menos: %.2f\nPercentual de pessoas que nao leram livros: %.2f%%", qtdLivrosMenores10, qtdMulheres5Livros, mediaIdadeHomensMenosQue5, percentualNaoLeram);
    
}
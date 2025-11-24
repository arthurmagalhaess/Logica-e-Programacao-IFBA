#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Algoritmo 7.2.11: Baseando-se no exercício 2, desenvolver o mesmo programa permitindo ao usuário escolher tipos de consulta diferentes: Consulta por ordem inversa de registro; Consulta por idade, ordem crescente; Consulta por idade, ordem decrescente; Consulta por sexo e por ordem de sexo. Ao final, apresentar os dados na ordem original.

#define QTD_PESSOAS 4

void menuDeConsusltas()
{
    printf("\n---CONSULTAS---\n");
    printf("1 - Ordem inversa dos registros\n");
    printf("2 - Idade (ordem crescente)\n");
    printf("3 - Idade (descrescente)\n");
    printf("4 - Por sexo\n");
}

int main()
{

    struct Pessoa
    {
        char nome[20];
        int idade;
        char sexo;
    };
    int tipoDaConsulta;

    struct Pessoa pessoas[QTD_PESSOAS];
    for (int i = 0; i < QTD_PESSOAS; i++)
    {
        printf("---PESSOA %d---\n", i + 1);
        printf("Nome: ");
        fgets(pessoas[i].nome, 20, stdin);
        pessoas[i].nome[strcspn(pessoas[i].nome, "\n")] = '\0';
        printf("Idade: ");
        scanf("%d", &pessoas[i].idade);

        printf("Sexo: ");
        scanf(" %c", &pessoas[i].sexo);
        getchar();
    }

    int idades[QTD_PESSOAS];
    for (int i = 0; i < QTD_PESSOAS; i++)
    {
        idades[i] = pessoas[i].idade;
    }

    do
    {
        menuDeConsusltas();
        printf("Escolha o tipo de consulta (digite 0 para sair): ");
        scanf("%d", &tipoDaConsulta);
        if (tipoDaConsulta == 0)
        {
            break;
        }
        switch (tipoDaConsulta)
        {
        case 1:
            for (int i = QTD_PESSOAS - 1; i >= 0; i--)
            {
                printf("---PESSOA %d---\n", i + 1);
                printf("Nome: %s\nIdade: %d\nSexo: %c\n", pessoas[i].nome, pessoas[i].idade, pessoas[i].sexo);
            }
            break;
        case 2:
            for (int i = 0; i < QTD_PESSOAS - 1; i++)
            {
                for (int j = 0; j < QTD_PESSOAS - 1; j++)
                {
                    if (idades[j] > idades[j + 1])
                    {
                        int temp = idades[j];
                        idades[j] = idades[j + 1];
                        idades[j + 1] = temp;
                    }
                }
            }
            for (int i = 0; i < QTD_PESSOAS; i++)
            {
                printf("%d\n", idades[i]);
            }
            break;

        case 3:
            for (int i = 0; i < QTD_PESSOAS - 1; i++)
            {
                for (int j = 0; j < QTD_PESSOAS - 1; j++)
                {
                    if (idades[j] < idades[j + 1])
                    {
                        int temp = idades[j];
                        idades[j] = idades[j + 1];
                        idades[j + 1] = temp;
                    }
                }
            }
            for (int i = 0; i < QTD_PESSOAS; i++)
            {
                printf("%d\n", idades[i]);
            }

            break;

        case 4:
            printf("---Sexo Masculino---\n");
            for (int i = 0; i < QTD_PESSOAS; i++)
            {
                if (pessoas[i].sexo == 'M')
                {
                    printf("%s\n", pessoas[i].nome);
                }
            }
            printf("---Sexo Feminino---\n");
            for (int i = 0; i < QTD_PESSOAS; i++)
            {
                if (pessoas[i].sexo == 'F')
                {
                    printf("%s\n", pessoas[i].nome);
                }
            }
            break;
        default:
            break;
        }
    } while (1);

    printf("---DADOS NA FORMA ORIGINAL---\n");

    for (int i = 0; i < QTD_PESSOAS; i++)
    {
        printf("PESSOA %d\n", i + 1);
        printf("Nome: %s\nIdade: %d\nSexo: %c\n", pessoas[i].nome, pessoas[i].idade, pessoas[i].sexo);
    }
}
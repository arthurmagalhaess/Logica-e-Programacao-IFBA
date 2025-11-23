#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Algoritmo 7.2.9: Uma prefeitura municipal necessita fazer uma cotação de preços em padarias para suprir a necessidade das creches e das escolas da cidade. Os produtos a serem cotados podem ser: pão francês 50 g, pacote de bolacha salgada 250 g, pacote de bolacha doce 250 g, biscoitos sortidos 250 g, pão de queijo. Todos os preços referem-se à unidade. O peso de cada produto pode variar e essa variação deve ser registrada pelo programa. O responsável pela cotação informará os produtos e a quantidade desejada no início do programa. Vale salientar que a quantidade é a mesma para todos os itens da cotação. Por lei, a prefeitura deverá analisar apenas três orçamentos. O programa deverá analisar os 3 orçamentos e disponibilizar os seguintes resultados: Empresas com o valor mais barato e mais caro: Geral (listagem de todos os produtos e respectivos preços); Empresas com seus respectivos valores: Por produto (É necessário gerar um menu com os produtos para que o usuário possa escolher o produto a ser avaliado). Deve ser utilizada uma struct para registrar os dados informados.

#define QTD_EMPRESAS 3
#define QTD_PRODUTOS 5

void mostrarMenuProdutos()
{
    printf("\n--- Produtos Disponiveis ---\n");
    printf("1 - Pão frances 50g\n");
    printf("2 - Pacote bolacha salgada 250g\n");
    printf("3 - Pacote bolacha doce 250g\n");
    printf("4 - Biscoitos sortidos 250g\n");
    printf("5 - Pao de queijo\n");
}

int main()
{
    struct Produto
    {
        char nome[40];
        float preco;
        float peso;
    };

    struct Empresa
    {
        char nome[40];
        struct Produto produtos[QTD_PRODUTOS];
    };

    struct Empresa empresas[QTD_EMPRESAS];
    int i, j;
    int quantidadeDesejada;

    char nomesProdutos[QTD_PRODUTOS][40] = {
        "Pao frances",
        "Bolacha salgada",
        "Bolacha doce",
        "Biscoitos sortidos",
        "Pao de queijo"};

    printf("Quantidade desejada (igual para todos os produtos): ");
    scanf("%d", &quantidadeDesejada);
    getchar();

    for (i = 0; i < QTD_EMPRESAS; i++)
    {

        printf("\nNome da empresa %d: ", i + 1);
        fgets(empresas[i].nome, 40, stdin);
        empresas[i].nome[strcspn(empresas[i].nome, "\n")] = '\0';

        printf("\nInforme o preco e o peso dos produtos da empresa %s:\n", empresas[i].nome);

        for (j = 0; j < QTD_PRODUTOS; j++)
        {

            strcpy(empresas[i].produtos[j].nome, nomesProdutos[j]);

            printf("\nProduto: %s\n", nomesProdutos[j]);

            printf("Peso (em gramas): ");
            scanf("%f", &empresas[i].produtos[j].peso);

            printf("Preco: R$ ");
            scanf("%f", &empresas[i].produtos[j].preco);
            getchar();
        }
    }

    float totais[QTD_EMPRESAS];
    for (i = 0; i < QTD_EMPRESAS; i++)
    {
        float soma = 0;
        for (j = 0; j < QTD_PRODUTOS; j++)
        {
            soma += empresas[i].produtos[j].preco * quantidadeDesejada;
        }
        totais[i] = soma;
    }

    int barata = 0, cara = 0;
    for (i = 1; i < QTD_EMPRESAS; i++)
    {
        if (totais[i] < totais[barata])
            barata = i;
        if (totais[i] > totais[cara])
            cara = i;
    }

    printf("\n--- Empresa mais barata ---\n");
    printf("%s - Total: R$ %.2f\n", empresas[barata].nome, totais[barata]);

    printf("\n--- Empresa mais cara ---\n");
    printf("%s - Total: R$ %.2f\n", empresas[cara].nome, totais[cara]);

    int opcao;
    mostrarMenuProdutos();

    do
    {
        printf("\nEscolha um produto para comparar (0 para sair): ");
        scanf("%d", &opcao);
        if (opcao == 0)
            break;

        opcao--;

        printf("\n--- Comparacao: %s ---\n", nomesProdutos[opcao]);
        for (i = 0; i < QTD_EMPRESAS; i++)
        {
            printf("%s -> Peso: %.1fg | Preco: R$ %.2f\n",
                   empresas[i].nome,
                   empresas[i].produtos[opcao].peso,
                   empresas[i].produtos[opcao].preco);
        }

    } while (1);

    return 0;
}

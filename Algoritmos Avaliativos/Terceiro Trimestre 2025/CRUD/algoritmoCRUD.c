#include <stdio.h>
#include <string.h>

/*
Faça um sistema de controle de produtos usando o conjunto de operações CRUD
C - Create (criar)
R - Read (ler)
U - Update (atualizar)
D - Delete (excluir)
*/


#define MAX 5

struct Produto
{
    int id;
    char nome[50];
    float valor;
    int quantidade;
    int ativo;
};

struct Produto produtos[MAX];
int totalAtual = 0;

void criar()
{
    if (totalAtual >= MAX)
    {
        printf("Numero maximo de produtos atingido\n");
        return;
    }

    produtos[totalAtual].id = totalAtual + 1;

    printf("-----CRIAR-----\n");
    printf("Nome: ");
    fgets(produtos[totalAtual].nome, 50, stdin);
    produtos[totalAtual].nome[strcspn(produtos[totalAtual].nome, "\n")] = '\0';

    printf("Valor: ");
    scanf("%f", &produtos[totalAtual].valor);

    printf("Quantidade: ");
    scanf("%d", &produtos[totalAtual].quantidade);
    getchar();

    produtos[totalAtual].ativo = 1;
    totalAtual++;

    printf("Produto registrado com sucesso\n");
}

void listar()
{
    printf("-----LISTAGEM DOS PRODUTOS-----\n");

    for (int i = 0; i < totalAtual; i++)
    {
        if (produtos[i].ativo == 1)
        {
            printf("Produto %d\n", i + 1);
            printf("ID: %d\nNome: %s\nValor: %.2f\nQuantidade: %d\n", produtos[i].id, produtos[i].nome, produtos[i].valor, produtos[i].quantidade);
        }
    }
}

void atualizar()
{
    int id;

    printf("-----ATUALIZAR PRODUTO-----\n");
    printf("Qual o ID do produto que voce deseja atualizar?\n");
    scanf("%d", &id);
    getchar();

    for (int i = 0; i < totalAtual; i++)
    {
        if (produtos[i].id == id && produtos[i].ativo == 1)
        {
            printf("Novo nome: ");
            fgets(produtos[i].nome, 50, stdin);
            produtos[i].nome[strcspn(produtos[i].nome, "\n")] = '\0';
            printf("Novo valor: ");
            scanf("%f", &produtos[i].valor);
            printf("Nova quantidade: ");
            scanf("%d", &produtos[i].quantidade);
            getchar();
            printf("Produto atualizado\n");
            return;
        }
    }
    printf("ID nao encontrado\n");
}

void deletar()
{
    int id;
    printf("Digite o ID para excluir: ");
    scanf("%d", &id);
    getchar();

    for (int i = 0; i < totalAtual; i++)
    {
        if (produtos[i].id == id && produtos[i].ativo == 1)
        {
            produtos[i].ativo = 0;
            printf("Produto removido com sucesso!\n");
            return;
        }
    }
    printf("Produto nao encontrado!\n");
}

int main()
{
    int acao;
    do
    {
        printf("-----MENU-----\n");
        printf("1 - Criar produto\n2 - Listar produtos\n3 - Atualizar produto\n4 - Deletar produto\n0 - Sair\n");
        printf("Digite o numero da acao que voce quer realizar: ");
        scanf("%d", &acao);
        getchar();

        switch (acao)
        {
        case 1:
            criar();
            break;
        case 2:
            listar();
            break;
        case 3:
            atualizar();
            break;
        case 4:
            deletar();
            break;
        case 0:
            printf("Encerrando o sistema...");
            break;
        default:
            printf("Opcao invalida\n");
        }
    } while (acao != 0);

}
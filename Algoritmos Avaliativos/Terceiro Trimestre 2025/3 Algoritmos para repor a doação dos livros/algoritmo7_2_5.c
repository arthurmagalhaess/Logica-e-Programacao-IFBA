#include <stdio.h>

//Fazer um programa que cria uma estrutura livro, que contém os elementos título, ano de edição, número de páginas e preço. Criar uma variável dessa estrutura, que é um vetor de 5 elementos. Ler os valores para a estrutura e imprimir a média do número de páginas dos livros. Caso algum número de páginas não seja informado, o mesmo deve ser desconsiderado no cálculo da média.

struct Livro {
    char titulo[50];
    int ano;
    int paginas;
    float preco;
};

int main() {
    struct Livro livros[5];
    int i, soma = 0, qtd = 0;

    for (i = 0; i < 5; i++) {
        printf("\nLivro %d\n", i+1);

        printf("Titulo: ");
        scanf("%s", livros[i].titulo);

        printf("Ano: ");
        scanf("%d", &livros[i].ano);

        printf("Paginas (0 se nao informado): ");
        scanf("%d", &livros[i].paginas);

        printf("Preco: ");
        scanf("%f", &livros[i].preco);

        if (livros[i].paginas > 0) {
            soma += livros[i].paginas;
            qtd++;
        }
    }

    if (qtd > 0)
        printf("\nMedia de paginas: %.2f\n", (float)soma / qtd);
    else
        printf("\nNenhum numero de paginas informado.\n");

    return 0;
}

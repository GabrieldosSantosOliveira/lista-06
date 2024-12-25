#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Produto
{
  char nome[50 + 1];
  double valor;
} Produto;
 
int main()
{
  int idas_feira;
  scanf("%d", &idas_feira);
  while (idas_feira--)
  {
    int quantidade_de_produtos;
    scanf("%d", &quantidade_de_produtos);
    Produto *produtos = (Produto *)calloc(sizeof(Produto), quantidade_de_produtos);
    int i;
    for (i = 0; i < quantidade_de_produtos; i++)
    {
      scanf("%s%lf", produtos[i].nome, &(produtos[i].valor));
    }
    int produtos_a_comprar;
    scanf("%d", &produtos_a_comprar);
    double soma = 0;
    for (i = 0; i < produtos_a_comprar; i++)
    {
      char nome[50 + 1];
      int quantidade;
      scanf("%s%d", nome, &quantidade);
      int j;
      for (j = 0; j < quantidade_de_produtos; j++)
      {
        if (strcmp(produtos[j].nome, nome) == 0)
        {
          soma += produtos[j].valor * quantidade;
          break;
        }
      }
    }
    printf("R$ %.2lf\n", soma);
    free(produtos);
  }
 
  return 0;
}
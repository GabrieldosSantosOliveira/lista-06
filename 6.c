#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct
{
  int matricula;
  int dia_de_nascimento;
  int mes_de_nascimento;
  int ano_de_nascimento;
  char nome[200 + 1];
} Aluno;
bool ComparaDataNasc(const Aluno *a1, const Aluno *a2)
{
  if (a1->ano_de_nascimento > a2->ano_de_nascimento)
  {
    return 0;
  }
  else if (a2->ano_de_nascimento > a1->ano_de_nascimento)
  {
    return 1;
  }
  if (a1->mes_de_nascimento > a2->mes_de_nascimento)
  {
    return 0;
  }
  else if (a2->mes_de_nascimento > a1->mes_de_nascimento)
  {
    return 1;
  }
  if (a1->dia_de_nascimento > a2->dia_de_nascimento)
  {
    return 0;
  }
  else if (a2->dia_de_nascimento > a1->dia_de_nascimento)
  {
    return 1;
  }
  return 1;
}
void bubble_sort(Aluno *v, int n)
{
  int i = 0;
  int end = (n - 1);
  while (end >= 1)
  {
    bool flag = false;
    int k;
    for (k = 0; k < end; k++)
    {
      if (ComparaDataNasc(&v[k], &v[k + 1]))
      {
        Aluno tmp = v[k];
        v[k] = v[k + 1];
        v[k + 1] = tmp;
        flag = true;
      }
    }
    end = end - 1;
    if (flag == false)
    {
      break;
    }
  }
}
int main()
{
  int n;
  scanf("%d", &n);
  Aluno *turma = (Aluno *)malloc(sizeof(Aluno) * n);
  int i;
  for (i = 0; i < n; i++)
  {
    scanf("%d%d%d%d%[^\n]%*c", &turma[i].matricula, &turma[i].dia_de_nascimento, &turma[i].mes_de_nascimento, &turma[i].ano_de_nascimento, turma[i].nome);
  }
  bubble_sort(turma, n);
  for (i = 0; i < n; i++)
  {
    printf("Matric.: %d Nome: %s Data Nasc: %d/%d/%d\n", turma[i].matricula, turma[i].nome, turma[i].dia_de_nascimento, turma[i].mes_de_nascimento, turma[i].ano_de_nascimento);
  }
  free(turma);
  return 0;
}
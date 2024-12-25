#include <stdio.h>
#include <stdlib.h>
typedef struct
{
  int code;
  float valor_por_credito;
  char nome[100 + 1];
} Curso;
typedef struct
{
  int code_curso;
  int creditos;
  char nome[500 + 1];
} Aluno;
 
Curso *find_curso_by_code(int code, Curso *cursos, int size_array_curso)
{
  int i;
  for (i = 0; i < size_array_curso; i++)
  {
    if (cursos[i].code == code)
    {
      return &cursos[i];
    }
  }
}
int main()
{
  int n, m;
  scanf("%d", &n);
  Curso *cursos = (Curso *)malloc(sizeof(Curso) * n);
  int i;
  for (i = 0; i < n; i++)
  {
    scanf("%d%f%*c%[^\n]%*c", &cursos[i].code, &cursos[i].valor_por_credito, cursos[i].nome);
  }
  scanf("%d", &m);
  Aluno *alunos = (Aluno *)malloc(sizeof(Aluno) * m);
 
  for (i = 0; i < m; i++)
  {
    scanf("%*c%[^\n]%*c%d%d", alunos[i].nome, &alunos[i].code_curso, &alunos[i].creditos);
    Curso *curso = find_curso_by_code(alunos[i].code_curso, cursos, n);
    printf("Aluno(a): %s Curso: %s Num. Creditos: %d Valor Credito: %.2f Mensalidade: %.2f\n", alunos[i].nome, curso->nome, alunos[i].creditos, curso->valor_por_credito, curso->valor_por_credito * alunos[i].creditos);
  }
  free(cursos);
  free(alunos);
  return 0;
}
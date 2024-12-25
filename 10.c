#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct Coef
{
  int potencia;
  float coeficiente;
} Coef;
 
void bubble_sort(Coef *v, int n)
{
  int end = (n - 1);
  while (end >= 1)
  {
    bool flag = false;
    int k;
    for (k = 0; k < end; k++)
    {
      if (v[k + 1].potencia < v[k].potencia)
      {
        Coef tmp = v[k];
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
 
void print_polinomio(Coef *this, int size)
{
  bubble_sort(this, size);
  int i;
  bool flag = true;
  for (i = size - 1; i >= 0; i--)
  {
    Coef tmp = this[i];
    if (tmp.potencia != 0 && tmp.coeficiente != 0)
    {
      flag = false;
      printf("%+.2f%c%c%d", tmp.coeficiente,'X','^', tmp.potencia);
    }
    else if (tmp.coeficiente != 0)
    {
      flag = false;
      printf("%+.2f", this[i].coeficiente);
    }
  }
  if (flag)
  {
    printf("%.2lf", 0.0);
  }
  printf("\n");
}
int find(Coef *v1, int size_v1, int potencia)
{
  int i = 0;
  for (i = 0; i < size_v1; i++)
  {
    if (v1[i].potencia == potencia)
    {
      return i;
    }
  }
  return -1;
}
int soma(Coef *v1, int size_v1, Coef *v2, int size_v2, Coef *v3, int maior_potencia)
{
  int i = 0;
  int v3_posicao = 0;
  for (i = 0; i <= maior_potencia; i++)
  {
    double m = 0, n = 0;
    int index_v1 = find(v1, size_v1, i);
    int index_v2 = find(v2, size_v2, i);
    if (index_v1 == -1 && index_v2 == -1)
    {
      continue;
    }
    if (index_v1 != -1)
    {
      m = v1[index_v1].coeficiente;
    }
    if (index_v2 != -1)
    {
      n = v2[index_v2].coeficiente;
    }
    v3[v3_posicao].potencia = i;
    v3[v3_posicao].coeficiente = m + n;
    v3_posicao++;
  }
  return v3_posicao;
}
int main()
{
  int n;
  scanf("%d%*c", &n);
  while (n--)
  {
    char cod;
    scanf("%c%*c", &cod);
    int m;
    scanf("%d", &m);
    int tamanho_primeiro_polinomio = m;
    int maior_potencia_primeiro_polinomio = 0;
 
    Coef *primeiro_polinomio = (Coef *)calloc(m, sizeof(Coef));
    int i = 0;
    for (i = 0; i < m; i++)
    {
      int potencia;
      float coeficiente;
      scanf("%f%d%*c", &coeficiente, &potencia);
      primeiro_polinomio[i].coeficiente = coeficiente;
      primeiro_polinomio[i].potencia = potencia;
      if (potencia > maior_potencia_primeiro_polinomio)
      {
        maior_potencia_primeiro_polinomio = potencia;
      }
    }
    scanf("%d", &m);
    int tamanho_segundo_polinomio = m;
    int maior_potencia_segundo_polinomio = 0;
 
    Coef *segundo_polinomio = (Coef *)calloc(m, sizeof(Coef));
    for (i = 0; i < m; i++)
    {
      int potencia;
      float coeficiente;
      scanf("%f%d%*c", &coeficiente, &potencia);
      segundo_polinomio[i].coeficiente = coeficiente;
      segundo_polinomio[i].potencia = potencia;
      if (potencia > maior_potencia_segundo_polinomio)
      {
        maior_potencia_segundo_polinomio = potencia;
      }
    }
    int maior_potencia = maior_potencia_segundo_polinomio;
    if (maior_potencia_primeiro_polinomio > maior_potencia_segundo_polinomio)
    {
      maior_potencia = maior_potencia_primeiro_polinomio;
    }
    Coef *soma_result = (Coef *)calloc(tamanho_primeiro_polinomio + tamanho_segundo_polinomio, sizeof(Coef));
    int t;
    if (cod == '+')
    {
      t = soma(primeiro_polinomio, tamanho_primeiro_polinomio, segundo_polinomio, tamanho_segundo_polinomio, soma_result, maior_potencia);
      print_polinomio(soma_result, t);
    }
    else if (cod == '-')
    {
      int i;
      for (i = 0; i < tamanho_segundo_polinomio; i++)
      {
        segundo_polinomio[i].coeficiente = -(segundo_polinomio[i].coeficiente);
      }
      t = soma(primeiro_polinomio, tamanho_primeiro_polinomio, segundo_polinomio, tamanho_segundo_polinomio, soma_result, maior_potencia);
      print_polinomio(soma_result, t);
    }
    free(primeiro_polinomio);
    free(segundo_polinomio);
  }
  return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
typedef struct
{
  double x, y, z, a;
  double distancia;
} Vector;
double norma(Vector *vector)
{
  return sqrt(pow(vector->a, 2) + pow(vector->x, 2) + pow(vector->y, 2) + pow(vector->z, 2));
}
 
void bubble_sort(Vector *v, int n)
{
  int i = 0;
  int end = (n - 1);
  while (end >= 1)
  {
    bool flag = false;
    int k;
    for (k = 0; k < end; k++)
    {
      if (v[k + 1].distancia < v[k].distancia)
      {
        Vector tmp = v[k];
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
  int i;
  Vector *vectors = (Vector *)malloc(sizeof(Vector) * n);
  for (i = 0; i < n; i++)
  {
    scanf("%lf%lf%lf%lf", &vectors[i].x, &vectors[i].y, &vectors[i].z, &vectors[i].a);
    vectors[i].distancia = norma(&vectors[i]);
  }
  bubble_sort(vectors, n);
  for (i = 0; i < n; i++)
  {
    printf("Vetor: (%.2lf, %.2lf, %.2lf, %.2lf) Norma: %.2lf\n", vectors[i].x, vectors[i].y, vectors[i].z, vectors[i].a, vectors[i].distancia);
  }
  free(vectors);
  return 0;
}
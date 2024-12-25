#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
 
typedef struct
{
  double x, y, z, a;
  double distancia;
} Vector;
double distancia_vetor(const Vector *v1, const Vector *v2)
{
  return sqrt(pow(v1->a - v2->a, 2) + pow(v1->x - v2->x, 2) + pow(v1->y - v2->y, 2) + pow(v1->z - v2->z, 2));
}
 
int main()
{
  int n, i;
  scanf("%d", &n);
  Vector *vectors = (Vector *)malloc(sizeof(Vector) * n);
  scanf("%lf%lf%lf%lf", &vectors[0].x, &vectors[0].y, &vectors[0].z, &vectors[0].a);
  for (i = 1; i < n; i++)
  {
    scanf("%lf%lf%lf%lf", &vectors[i].x, &vectors[i].y, &vectors[i].z, &vectors[i].a);
    printf("%.2lf\n", distancia_vetor(&vectors[i], &vectors[i - 1]));
  }
 
  free(vectors);
  return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define read_fraction(p) (scanf("%d%*c%d", &((p)->x), &((p)->y)))
typedef struct
{
  int x, y;
} Fraction;
 
int calcular_mdc(int a, int b)
{
  if (a == 0)
    return b;
  else if (b == 0)
    return a;
 
  if (a < b)
  {
    int tmp = a;
    a = b;
    b = tmp;
  }
  int rest = a % b;
  while (rest != 0)
  {
    a = b;
    b = rest;
    rest = a % b;
  }
  return b;
}
 
bool is_equal(Fraction f1, Fraction f2)
{
  Fraction rf1 = f1;
  Fraction rf2 = f2;
  int mdcf1 = calcular_mdc(f1.x, f1.y);
  int mdcf2 = calcular_mdc(f2.x, f2.y);
 
  if ((rf1.x / mdcf1) == (rf2.x / mdcf2) && (rf2.y / mdcf2) == (rf1.y / mdcf1))
  {
    return true;
  }
  return false;
}
int main()
{
  int nc, nl;
  scanf("%d", &nl);
  int n;
  for (n = 0; n < nl; n++)
  {
    scanf("%d", &nc);
    Fraction *list = (Fraction *)calloc(nc, sizeof(Fraction *));
    int i = 0;
    for (i = 0; i < nc; i++)
    {
      read_fraction(&list[i]);
    }
    printf("Caso de teste %d\n", n + 1);
    int quant = 0;
    for (i = 0; i < nc; i++)
    {
      int j;
      for (j = i + 1; j < nc; j++)
      {
        if (is_equal(list[i], list[j]))
        {
          quant++;
          printf("%d/%d equivalente a %d/%d\n", list[i].x, list[i].y, list[j].x, list[j].y);
        }
      }
    }
    if (quant == 0)
    {
      printf("Nao ha fracoes equivalentes na sequencia\n");
    }
    free(list);
  }
  return 0;
}
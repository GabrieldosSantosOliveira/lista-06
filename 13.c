#include <stdio.h>
#include <math.h>
typedef struct Complex
{
  double i;
  double real;
} Complex;
 
typedef struct RaizEqu2
{
  Complex x1, x2;
} RaizEqu2;
/**
 * Função que calula as raízes de uma equação de segundo grau.
 *
 * @param a coeficiente quadrado
 * @param b coeficiente linear
 * @param c constante
 * @return retorna uma estrutura RaizEqu2 com dois números complexos
 */
 
struct RaizEqu2 calcula_raiz_equ_2(float a, float b, float c)
{
  double delta = (b * b) - (4 * (a * c));
  // double complex raiz = csqrt(delta);
  // double complex x1 = (-b + raiz) / (2 * a);
  // double complex x2 = (-b - raiz) / (2 * a);
  Complex x1;
  Complex x2;
  if (delta >= 0)
  {
    x1.i = 0.0;
    x1.real = (-b + sqrt(delta)) / (2 * a);
    x2.i = 0.0;
    x2.real = (-b - sqrt(delta)) / (2 * a);
  }
  else if (delta < 0)
  {
    x1.i = (sqrt(-delta)) / (2 * a);
    x1.real = (-b) / (2 * a);
    x2.i = (-sqrt(-delta)) / (2 * a);
    x2.real = (-b) / (2 * a);
  }
  RaizEqu2 raizes = {
      .x1 = x1,
      .x2 = x2,
  };
  return raizes;
};
 
/**
* Imprime numeros complexos na saída padrão do sistema. A impressão segue o formato
* a + bi, onde a é a parte real e b a imaginária. Os valores são apresentados
* somente se forem diferente de zero. No caso de a e b forem zero, o valor 0 é
* apresentado. Se o valor de b for 1 ou -1, somente o caracter i ou -i é
apresentado.
*
* @param c Numero complexo a ser impresso.
*/
void complex_print(struct Complex c, char *name)
{
  printf("%s = ", name);
 
  if (c.real == 0.0 && c.i == 0.0)
  {
    printf("0.00\n");
  }
  else if (c.i == 0.0)
  {
    printf("%.2f\n", c.real);
  }
  else if (c.real == 0.0)
  {
    if (c.i == 1.0)
    {
      printf("i\n");
    }
    else if (c.i == -1.0)
    {
      printf("-i\n");
    }
    else
    {
      printf("%.2fi\n", c.i);
    }
  }
  else
  {
    if (c.i == 1.0)
    {
      printf("%.2f+i\n", c.real);
    }
    else if (c.i == -1.0)
    {
      printf("%.2f-i\n", c.real);
    }
    else if (c.i > 0)
    {
      printf("%.2f+%.2fi\n", c.real, c.i);
    }
    else
    {
      printf("%.2f%.2fi\n", c.real, c.i);
    }
  }
};
 
int main(int argc, char const *argv[])
{
  float a, b, c;
  scanf("%f%f%f", &a, &b, &c);
  RaizEqu2 raizes = calcula_raiz_equ_2(a, b, c);
  complex_print(raizes.x1, "x1");
  complex_print(raizes.x2, "x2");
  return 0;
}
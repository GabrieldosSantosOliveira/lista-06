#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define JUMP 5
#define ERROR_ALLOCATE_MEMORY 10
#define ERROR_OUT_OF_BOUNDARIES 50
typedef struct tRacional
{
  int numerador, denominador;
} tRacional;
 
/**
 * Calcula o MDC de x e y
 * @param x
 * @param y
 * @return
 */
int MDC(int x, int y)
{
  if (x == 0)
    return y;
  else if (y == 0)
    return x;
 
  if (x < y)
  {
    int tmp = x;
    x = y;
    y = tmp;
  }
  int rest = x % y;
  while (rest != 0)
  {
    x = y;
    y = rest;
    rest = x % y;
  }
  if (y < 0)
  {
    return y * -1;
  }
  return y;
};
/**
 * Recebe dois inteiros a e b e retorna o racional
 * @param a numerador
 * @param b denominador
 * @return
 */
struct tRacional
racional(int a, int b)
{
  tRacional t = {.numerador = a, .denominador = b};
  return t;
};
/**
 * Recebe um racional e retorna o seu negativo (-r).
 * @param r numero racional
 * @return
 */
struct tRacional
negativo(struct tRacional r)
{
  r.numerador = r.numerador * -1;
  return r;
};
/**
 * Recebe dois racionais e retorna a adição de ambos (r1 + r2).
 * @param r1 fator esquerdo da soma
 * @param r2 fator direito da soma
 * @return
 */
struct tRacional
soma(struct tRacional r1, struct tRacional r2)
{
  int denominador = r1.denominador * r2.denominador;
  int numerador = (r1.numerador * r2.denominador) + (r2.numerador * r1.denominador);
  tRacional a = {.denominador = denominador, .numerador = numerador};
  return a;
};
struct tRacional
subtrair(struct tRacional r1, struct tRacional r2)
{
  int denominador = r1.denominador * r2.denominador;
  int numerador = (r1.numerador * r2.denominador) - (r2.numerador * r1.denominador);
  tRacional a = {.denominador = denominador, .numerador = numerador};
  return a;
};
/**
   * Recebe dois racionais e retorna o produto de ambos (r1 * r2).
   * @param r1 primeiro fator do produto
   * @param r2 segundo fator do produto
   * @return
 
   */
struct tRacional
mult(struct tRacional r1, struct tRacional r2)
{
  tRacional a = {
      .denominador = r1.denominador * r2.denominador,
      .numerador = r1.numerador * r2.numerador,
  };
  return a;
};
/**
 * Recebe dois racionais e retorna o quociente de ambos (r1/r2).
 * @param r1 numerador
 * @param r2 denominador
 * @return
 */
struct tRacional dividir(struct tRacional r1, struct tRacional r2)
{
  tRacional a = {
      .numerador = r1.numerador * r2.denominador,
      .denominador = r1.denominador * r2.numerador,
  };
 
  return a;
};
/**
 * Recebe um racional e reduz a fração ao máximo.
 * @param r o número racional a ser reduzido
 */
void reduzFracao(struct tRacional *r)
{
  int mdc = MDC(r->denominador, r->numerador);
  r->denominador = r->denominador / mdc;
  r->numerador = r->numerador / mdc;
};
typedef struct List
{
  tRacional *vector;
  size_t size_vector;
  size_t count_items;
  void (*add)(struct List *, const tRacional *);
  tRacional *(*get)(struct List *, size_t);
  void (*clear)(struct List *);
  tRacional *(*first)(struct List *);
  tRacional *(*second)(struct List *);
 
} List;
tRacional *first(struct List *this)
{
  return this->get(this, 0);
};
tRacional *second(struct List *this)
{
  return this->get(this, 1);
};
void clear(List *this)
{
  this->vector = realloc(this->vector, sizeof(tRacional) * JUMP);
  this->size_vector = JUMP;
  this->count_items = 0;
}
tRacional *get(struct List *this, const size_t index)
{
  if (index >= this->count_items)
  {
    exit(ERROR_OUT_OF_BOUNDARIES);
  }
  return &this->vector[index];
}
 
void add(List *this, const tRacional *f)
{
  if (this->count_items == this->size_vector)
  {
    this->vector = (tRacional *)realloc(this->vector, sizeof(tRacional) * (this->size_vector + JUMP));
    if (this->vector == NULL)
    {
      exit(ERROR_ALLOCATE_MEMORY);
    }
    this->size_vector = this->size_vector + JUMP;
  }
  this->vector[this->count_items] = *f;
  this->count_items = this->count_items + 1;
}
List *new_list()
{
  List *f = (List *)malloc(sizeof(List) * 1);
  f->vector = (tRacional *)malloc(sizeof(tRacional) * JUMP);
  f->size_vector = JUMP;
  f->count_items = 0;
  f->add = add;
  f->get = get;
  f->clear = clear;
  f->first = first;
  f->second = second;
  return f;
}
void delete(List *this)
{
  free(this->vector);
  free(this);
}
typedef enum
{
  DIVIDIR,
  MULTIPLICAR,
  SUBTRAIR,
  SOMAR,
} Operacao;
Operacao split(List *list, char *str)
{
  tRacional f;
  char *x = strtok(str, " ");
  Operacao o;
  while (x != NULL)
  {
    if (strncmp(x, "+", 2) == 0)
    {
      o = SOMAR;
      x = strtok(NULL, " ");
      continue;
    }
    else if (strncmp(x, "-", 2) == 0)
    {
      o = SUBTRAIR;
      x = strtok(NULL, " ");
      continue;
    }
    else if (strncmp(x, "*", 2) == 0)
    {
      o = MULTIPLICAR;
      x = strtok(NULL, " ");
      continue;
    }
    else if (strncmp(x, "/", 2) == 0)
    {
      o = DIVIDIR;
      x = strtok(NULL, " ");
      continue;
    }
 
    int k = atoi(x);
    x = strtok(NULL, " ");
 
    int n = atoi(x);
 
    f.numerador = k;
    f.denominador = n;
    list->add(list, &f);
    x = strtok(NULL, " ");
  }
  return o;
}
 
int main()
{
  char buffer[100];
  List *list = new_list();
  while (scanf("%[^\n]%*c", buffer) != EOF)
  {
    Operacao code = split(list, buffer);
 
    tRacional a;
    if (code == DIVIDIR)
    {
      a = dividir(*list->first(list), *list->second(list));
    }
    else if (code == MULTIPLICAR)
    {
      a = mult(*list->first(list), *list->second(list));
    }
    else if (code == SOMAR)
    {
      a = soma(*list->first(list), *list->second(list));
    }
    else if (code == SUBTRAIR)
    {
      a = subtrair(*list->first(list), *list->second(list));
    }
    reduzFracao(&a);
    printf("%d %d\n", a.numerador, a.denominador);
    list->clear(list);
  };
  delete (list);
  return 0;
}
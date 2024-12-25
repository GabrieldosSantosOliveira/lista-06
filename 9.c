#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#define JUMP 5
#define ERROR_ALLOCATE_MEMORY 50
#define ERROR_OUT_OF_BOUNDARIES 100
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
 
bool is_equal(const Fraction *const f1, const Fraction *const f2)
{
  int mdcf1 = calcular_mdc(f1->x, f1->y);
  int mdcf2 = calcular_mdc(f2->x, f2->y);
 
  if ((f1->x / mdcf1) == (f2->x / mdcf2) && (f2->y / mdcf2) == (f1->y / mdcf1))
  {
    return true;
  }
  return false;
}
typedef struct List
{
  Fraction *vector;
  size_t size_vector;
  size_t count_items;
  void (*add)(struct List *, const Fraction *);
  Fraction *(*get)(struct List *, size_t);
  void (*clear)(struct List *);
} List;
void clear(List *this)
{
  this->vector = realloc(this->vector, sizeof(Fraction) * JUMP);
  this->size_vector = JUMP;
  this->count_items = 0;
}
Fraction *get(struct List *this, const size_t index)
{
  if (index >= this->count_items)
  {
    exit(ERROR_OUT_OF_BOUNDARIES);
  }
  return &this->vector[index];
}
 
void add(List *this, const Fraction *f)
{
  if (this->count_items == this->size_vector)
  {
    this->vector = (Fraction *)realloc(this->vector, sizeof(Fraction) * (this->size_vector + JUMP));
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
  f->vector = (Fraction *)malloc(sizeof(Fraction) * JUMP);
  f->size_vector = JUMP;
  f->count_items = 0;
  f->add = add;
  f->get = get;
  f->clear = clear;
  return f;
}
void delete(List *this)
{
  free(this->vector);
  free(this);
}
void split(List *list, char *str)
{
  Fraction f;
  char *x = strtok(str, " ");
  while (x != NULL)
  {
    int i = 0;
    while (x[i] != '/')
    {
      i++;
    }
    x[i] = '\0';
    f.x = atoi(x);
    f.y = atoi(&x[i + 1]);
    list->add(list, &f);
    x = strtok(NULL, " ");
  }
}
 
void print_equals(Fraction *f1, Fraction *f2)
{
  printf("%d/%d equivalente a %d/%d\n", f1->x, f1->y, f2->x, f2->y);
}
 
int main()
{
  int n, i = 0;
  scanf("%d%*c", &n);
  List *list = new_list();
  Fraction f;
  int l = 0;
  char buffer[100];
  int qauntidade = 0;
  int t = 1;
  while (scanf("%[^\n]%*c", buffer) != EOF)
  {
    split(list, buffer);
    printf("Caso de teste %d\n", t);
    int quant = 0;
    for (i = 0; i < list->count_items; i++)
    {
      int j;
      for (j = i + 1; j < list->count_items; j++)
      {
        Fraction *f1 = list->get(list, i);
        Fraction *f2 = list->get(list, j);
        if (is_equal(f1, f2))
        {
          quant++;
          print_equals(f1, f2);
        }
      }
    }
    if (quant == 0)
    {
      printf("Nao ha fracoes equivalentes na sequencia\n");
    }
    t = t + 1;
    list->clear(list);
  }
  delete (list);
 
  return 0;
}
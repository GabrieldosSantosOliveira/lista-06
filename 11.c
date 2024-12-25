#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define JUMP 5
#define ERROR_ALLOCATE_MEMORY 50
#define ERROR_OUT_OF_BOUNDARIES 100
typedef struct
{
  int consumo, pessoas;
  int media;
} Residencia;
 
void bubble_sort(Residencia *v, int n)
{
  int i = 0;
  int end = (n - 1);
  while (end >= 1)
  {
    bool flag = false;
    int k;
    for (k = 0; k < end; k++)
    {
      if (v[k].media > v[k + 1].media)
      {
        Residencia tmp = v[k];
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
 
typedef struct List
{
  int *vector;
  size_t size_vector;
  size_t count_items;
  void (*add)(struct List *, int);
  int (*find)(struct List *, int);
  void (*clear)(struct List *);
} List;
void clear(List *this)
{
  this->vector = realloc(this->vector, sizeof(int) * JUMP);
  this->size_vector = JUMP;
  this->count_items = 0;
}
int find(struct List *this, int value)
{
  int i;
  for (i = 0; i < this->count_items; i++)
  {
    if (value == this->vector[i])
    {
      return i;
    }
  }
  return -1;
}
 
void add(List *this, int f)
{
  if (this->count_items == this->size_vector)
  {
    this->vector = (int *)realloc(this->vector, sizeof(int) * (this->size_vector + JUMP));
    if (this->vector == NULL)
    {
      exit(ERROR_ALLOCATE_MEMORY);
    }
    this->size_vector = this->size_vector + JUMP;
  }
  this->vector[this->count_items] = f;
  this->count_items = this->count_items + 1;
}
List *new_list()
{
  List *f = (List *)malloc(sizeof(List) * 1);
  f->vector = (int *)malloc(sizeof(int) * JUMP);
  f->size_vector = JUMP;
  f->count_items = 0;
  f->add = add;
  f->find = find;
  f->clear = clear;
  return f;
}
void delete(List *this)
{
  free(this->vector);
  free(this);
}
int quantidade_de_pessoas(Residencia *r, int media, int size)
{
  int i;
  int pessoas = 0;
  for (i = 0; i < size; i++)
  {
    if (media == r[i].media)
    {
      pessoas += r[i].pessoas;
    }
  }
  return pessoas;
}
int main()
{
  int n;
  scanf("%d", &n);
  int j = 1;
  while (n != 0)
  {
    int i = 0;
    Residencia *lista = (Residencia *)malloc(sizeof(Residencia) * n);
    List *medias = new_list();
    double consumo = 0;
    int quantidade_pessoas = 0;
    for (i = 0; i < n; i++)
    {
      scanf("%d%d", &lista[i].pessoas, &lista[i].consumo);
      lista[i].media = lista[i].consumo / lista[i].pessoas;
      consumo += lista[i].consumo;
      quantidade_pessoas += lista[i].pessoas;
    }
    bubble_sort(lista, n);
    printf("Cidade# %d:\n", j);
 
    for (i = 0; i < n; i++)
    {
      if (medias->find(medias, lista[i].media) != -1)
      {
        continue;
      }
      int q = quantidade_de_pessoas(lista, lista[i].media, n);
      if (!((i + 1) < n))
      {
        printf("%d-%d\n", q, lista[i].media);
      }
      else
      {
        printf("%d-%d ", q, lista[i].media);
      }
      medias->add(medias, lista[i].media);
    }
 
    printf("Consumo medio: %.2lf m3.\n", consumo / quantidade_pessoas);
    scanf("%d", &n);
    j++;
    free(lista);
    delete (medias);
  }
  return 0;
}
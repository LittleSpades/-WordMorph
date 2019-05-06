#include "defs.h"
#include "heap.h"

#define DEMO

struct _heap {
  int (*less) (int, int);     /* Ponteiro para funcao na qual
                                    entram elementos da heap */
  int n_elements;          /*numero de elementos na heap*/
  int size;                     /* tamanho maximo da heap */
  Vertice **heapdata;
};

struct _vertice {
  int indice_at;
};



/***********************************************
 *  Funcao:
 *    create_struct_vertice
 *
 *  Descricao:
 *  - Aloca um Ponteiro para struct _vertice

 *  Argumentos:
 *    - Nenhum
 *
 *  Retorna:
 *  O ponteiro criado
 *
 *************************************************/

Vertice *create_struct_vertice()
{
  Vertice* v = (Vertice *)calloc(1, sizeof(Vertice));
  return (v);
}


/***********************************************
 *  Funcao:
 *    Ins_indice_at
 *
 *  Descricao:
 *  - Insere o indice atual do vetor num inteiro

 *  Argumentos:
 *    - Ponteiro para struct Vertice
 *    - Inteiro no qual se vai inserir
 *
 *  Retorna:
 *  Nada
 *
 *************************************************/

void Ins_indice_at(Vertice* a, int b)
{
  a->indice_at = b;
}


/***********************************************
 *  Funcao:
 *    Get_indice_at
 *
 *  Descricao:
 *  - Obtem o indice atual do vetor

 *  Argumentos:
 *    - Ponteiro para struct Vertice
 *
 *  Retorna:
 *  O indice
 *
 *************************************************/

int Get_indice_at(Vertice * a)
{
  return(a->indice_at);
}


/***********************************************
 *  Funcao:
 *    Get_Pointer
 *
 *  Descricao:
 *  - Obtem o valor de heapdata na posicao dada por indice

 *  Argumentos:
 *    - Ponteiro para struct Heap
 *    - Indice ao qual se vai buscar a informacao
 *
 *  Retorna:
 *  O valor da Heapdata na posicao
 *
 *************************************************/

Vertice* Get_Pointer(Heap * h, int indice)
{
  return(h->heapdata[indice]);
}


/***********************************************
 *  Funcao:
 *    Ins_Pointer
 *
 *  Descricao:
 *  - Insere a heapdata num inteiro

 *  Argumentos:
 *    - Ponteiro para struct Heap
 *    - Indice no qual sevai procurar
 *    - Inteiro no qual se vai inserir
 *
 *  Retorna:
 *  Nada
 *
 *************************************************/

void Ins_Pointer(Heap *h, int indice, Vertice* a)
{
   (h->heapdata[indice]) = a;
}


/***********************************************
 *  Funcao:
 *    Get_n_el
 *
 *  Descricao:
 *  - Obtem o numero de elementos na heap

 *  Argumentos:
 *    - Ponteiro para struct Heap
 *
 *  Retorna:
 *  Numero de elementos
 *
 *************************************************/

int Get_n_el(Heap *h)
{
  return(h->n_elements);
}


/******************************************************************************
 * FixUp()
 *
 * Arguments: h - pointer to heap structure
 *                    k - index of element to fixup
 *                    Vetor de Inteiros pesos_a_origem
 *                    Vetor de inteiros _heap_pos;
 * Returns:
 * Side-Effects: none
 *
 * Description: Faz FixUp a partir do indice k
 *
 *****************************************************************************/

void FixUp(Heap * h, int k, int* pesos_a_origem, int* _heap_pos)
{
  Vertice* t;
  while ((k > 0) && (h->less) (pesos_a_origem[Get_indice_at(Get_Pointer(h, k))],pesos_a_origem[Get_indice_at(Get_Pointer(h, ((k-1)/2)))])) {

    if(k > h->n_elements)
    {
      printf("ERRO POSICAO INVALIDA NA HEAP\n");
    }


    _heap_pos[Get_indice_at(Get_Pointer(h, k))]=((k-1)/2);
    _heap_pos[Get_indice_at(Get_Pointer(h, ((k-1)/2)))]=k;

    t = Get_Pointer(h, k);
    Ins_Pointer(h, k, Get_Pointer(h, ((k-1)/2)));
    Ins_Pointer(h, ((k-1)/2), t);

    k = (k - 1) / 2;
  }

  return;
}

/***********************************************
 *  Funcao:
 *    FixDown
 *
 *  Descricao:
 *  - Faz o FixDown na heap

 *  Argumentos:
 *    - Ponteiro para a heap
 *    - Indice sobre o qual se vai atuar
 *    - Vetor de Inteiros pesos_a_origem
 *    - Vetor de inteiros _heap_pos;
 *
 *
 *  Retorna:
 *  Nada
 *
 *************************************************/

void FixDown(Heap * h, int k, int* pesos_a_origem, int* _heap_pos)
{
  int j;
  Vertice* t;

  while ((2 * k + 1) < h->n_elements) {
    j = 2 * k + 1;
    if (((j + 1) < h->n_elements) &&
        (h->less) (pesos_a_origem[Get_indice_at(Get_Pointer(h, j+1))], pesos_a_origem[Get_indice_at(Get_Pointer(h, j))])) {
      j++;
    }
    if (!(h->less) (pesos_a_origem[Get_indice_at(Get_Pointer(h, j))], pesos_a_origem[Get_indice_at(Get_Pointer(h, k))])) {
      break;
    }

  /*nao estao bem ordenados, e preciso troca-los*/

  _heap_pos[Get_indice_at(Get_Pointer(h, k))]=j;
  _heap_pos[Get_indice_at(Get_Pointer(h, j))]=k;

    t = Get_Pointer(h, k);
    Ins_Pointer(h, k, Get_Pointer(h, j));
    Ins_Pointer(h, j, t);
    k = j;
  }

  return;
}


 /***********************************************
  *  Funcao:
  *    NewHeap
  *
  *  Descricao:
  *  - Aloca espaco para uma niva heap com tamanho especifico

  *  Argumentos:
  *    - Tamanho da heap (size)
  *    - Ponteiro para funcao de comparacao (less)
  *
  *  Retorna:
  *  A Heap
  *
  *************************************************/

Heap *NewHeap(int size, int (*less) (int, int))
{
  Heap *h;

  h = (Heap *) malloc(sizeof(Heap));
  if (h == ((Heap *) NULL)) {
    fprintf(stderr, "Error in malloc of heap\n");
    exit(1);
  }

  h->n_elements = 0;
  h->less = less;
  h->size = size;
  h->heapdata = (Vertice **) calloc(size+1, sizeof(Vertice*));
  if (h->heapdata ==  NULL) {
    fprintf(stderr, "Error in malloc of heap data\n");
    exit(1);
  }

  return (h);
}

 /***********************************************
  *  Funcao:
  *    FreeHeap
  *
  *  Descricao:
  *  - Liberta a Heap

  *  Argumentos:
  *    - Ponteiro para Heap
  *
  *  Retorna:
  *  Nada
  *
  *************************************************/

void FreeHeap(Heap * h)
{
  if(h->n_elements!=0)
    CleanHeap(h);
  free(h->heapdata);
  free(h);
}


 /***********************************************
  *  Funcao:
  *    Insert
  *
  *  Descricao:
  *  - Adiciona um elemento no fim da heap e incrementa o numero de elementos

  *  Argumentos:
  *    - Ponteiro para Heap
  *    - Elemento a ser adicionado
  *
  *  Retorna:
  *  0 caso a heap esteja cheia e 1 caso ainda se possam adicionar elementos
  *
  *************************************************/

int Insert(Heap * h, Vertice* element)
{
  if (h->n_elements == h->size) {
    return 0;
  }
  Ins_Pointer(h, h->n_elements, element);

  h->n_elements++;

  return 1;
}


 /***********************************************
  *  Funcao:
  *    RemoveHead
  *
  *  Descricao:
  *  - Troca o primeiro com o ultimo elemento da heap e depois liberta a ultima posicao

  *  Argumentos:
  *    - Ponteiro para struct Heap
  *    - Vetor de Inteiros _heap_pos
  *
  *  Retorna:
  *  Nada
  *
  *************************************************/

void RemoveHead(Heap * h, int* _heap_pos)
{
  Vertice* t;

  if (h->n_elements > 0) {

    _heap_pos[h->heapdata[0]->indice_at]=h->n_elements-1;
    _heap_pos[h->heapdata[h->n_elements-1]->indice_at]=0;

    t = Get_Pointer(h, 0);
    Ins_Pointer(h, 0, Get_Pointer(h, (h->n_elements-1)));
    Ins_Pointer(h, (h->n_elements-1), t);
    free(Get_Pointer(h, (h->n_elements-1)));
    h->n_elements--;
  }
}


 /***********************************************
  *  Funcao:
  *    CleanHeap
  *
  *  Descricao:
  *  - Limpa a heap

  *  Argumentos:
  *    - Ponteiro para struct Heap
  *
  *  Retorna:
  *   Nada
  *
  *************************************************/

void CleanHeap(Heap * h)
{
     while((h->n_elements)>0)
     {
       free(Get_Pointer(h, (h->n_elements-1)));
       h->n_elements--;
     }
  return;
}

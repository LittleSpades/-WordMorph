#ifndef resolveHeader
#define resolveHeader


#include "tabpal.h"
#include "heap.h"

typedef struct Adjacencia Adj;

Adj** CriaVetorGrafo(int nrpal);

void Ins_Lista_Adj(Adj** _VetorGrafo, Adj** _VetorGrafoBack, TabPal** _Dicionario, int Dic_Pos, int indice_p, int* _ja_no_grafo);

void freeVetorGrafo(Adj** x, Adj** y, int nrpal);

int Get_perm(Adj* x);

void Ins_perm(Adj* x, int y);

int Get_indice(Adj* x);

void Ins_indice(Adj* x, int y);

Adj* Get_next(Adj* x);

void Ins_next(Adj* x, Adj* y);

int Dif_Let(char* P1, char* P2, int _nr_perm_max);

int bisearch(TabPal **_Dicionario, int _DicPos, char *_palavra);

int LessNum(int a, int b);

void Percorre_Lista_Adj(Heap* _h, Vertice* _hd, Adj* _VetorGrafo, int indice_VetorGrafo, int* path, int* pesos_a_origem, int* head_before, Prob* _Problema, int* _heap_pos);

Heap* StartHeap(int indice_Origem, int* pesos_a_origem, TabPal** _Dicionario, int DicPos, int* _heap_pos);

void Ins_new_vertices(Heap* h, Adj* _VetorGrafo, int indice_VetorGrafo, Prob* _Problema, int* pac, int* path);

int Stop_Cond(Heap* h,  int _ind_chegada);

/*int VerifyHead(Heap* h, int* _pac);*/

void resolve_com_grafo(Adj** VetorGrafo, Adj** VetorGrafoBack, int* ja_no_grafo, TabPal** _Dicionario, int DicPos, Prob* _Problema, int _ind_origem, int _ind_chegada);

void responde_probs(TabPal** _Dicionario, int _tmin, Prob** _VetorProb, int _probmax);



#endif

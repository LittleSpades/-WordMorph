#ifndef heapHeader
#define heapHeader

typedef struct _heap Heap;

typedef struct _vertice Vertice;

Vertice *create_struct_vertice();

void Ins_indice_at(Vertice* a, int b);

int Get_indice_at(Vertice * a);

Vertice* Get_Pointer(Heap * h, int indice);

void Ins_Pointer(Heap *h, int indice, Vertice * a);

int Get_n_el(Heap *h);

void FixUp(Heap * h, int k, int* pesos_a_origem, int* _heap_pos);

void FixDown(Heap * h, int k, int* pesos_a_origem, int* _heap_pos);

Heap *NewHeap(int size, int (*less) (int, int));

void FreeHeap(Heap * h);

int Insert(Heap * h, Vertice* element);

void RemoveHead(Heap * h, int* _heap_pos);

void CleanHeap(Heap * h);

void Heapify(Heap * h, int* pesos_a_origem);

#endif

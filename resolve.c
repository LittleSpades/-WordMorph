#include "defs.h"
#include "resolve.h"
#include <limits.h>

struct Adjacencia{
  int perm;
  int indice;

  Adj* next;
};

/***********************************************
 *  Funcao:
 *      LessNum
 *
 *  Descricao:
 *    Função de Comparação entre dois inteiros
 *
 *  Argumentos:
 *    - a, b (os dois inteiros para serem comparados)
 *
 *  Retorna:
 *  Inteiro com o resultado da comparação
 *************************************************/

int LessNum(int a, int b)
{
  return (a < b);
}

/***********************************************
 *  Funcao:
 *      CriaVetorGrafo
 *
 *  Descricao:
 *    Aloca o Vetor de ponteiros para struct Adj
 *
 *  Argumentos:
 *    - Inteiro que corresponde ao numero de
 *      palavras do mesmo tamanho guardadas
 *      no vetor DIcionario
 *
 *  Retorna:
 *  Vetor de ponteiros para struct Adj
 *************************************************/

Adj** CriaVetorGrafo(int nrpal)
{
  Adj** y =(Adj**) calloc(nrpal, sizeof(Adj*));
  return(y);
}


/***********************************************
 *  Funcao:
 *      Get_perm
 *
 *  Descricao:
 *    Obtém o numero letras diferentes (perm)
 *    guardado na struct adj
 *
 *  Argumentos:
 *    - Ponteiro para struct Adj (x)
 *
 *  Retorna:
 *  x->perm
 *************************************************/

int Get_perm(Adj* x)
{
  return(x->perm);
}


/***********************************************
 *  Funcao:
 *      Ins_perm
 *
 *  Descricao:
 *    Guarda o int y no parametro perm da struct
 *    Adj x
 *
 *  Argumentos:
 *    - Ponteiro para struct Adj (x)
 *    - Inteiro y
 *
 *  Retorna:
 *  Nada
 *************************************************/

void Ins_perm(Adj* x, int y)
{
  x->perm=y;
}

/***********************************************
 *  Funcao:
 *      Get_indice
 *
 *  Descricao:
 *    Obtém o indice da palavra adjacente (indice)
 *    guardado na struct adj
 *
 *  Argumentos:
 *    - Ponteiro para struct Adj (x)
 *
 *  Retorna:
 *  x->indice
 *************************************************/

int Get_indice(Adj* x)
{
  return(x->indice);
}

/***********************************************
 *  Funcao:
 *      Ins_indice
 *
 *  Descricao:
 *    Guarda o int y no parametro indice da struct
 *    Adj x
 *
 *  Argumentos:
 *    - Ponteiro para struct Adj (x)
 *    - Inteiro y
 *
 *  Retorna:
 *  Nada
 *************************************************/

void Ins_indice(Adj* x, int y)
{
  x->indice=y;
}

/***********************************************
 *  Funcao:
 *      Get_next
 *
 *  Descricao:
 *    Obtém o ponteiro para a proxima struct da
 *    lista (next)
 *
 *  Argumentos:
 *    - Ponteiro para struct Adj (x)
 *
 *  Retorna:
 *  x->next
 *************************************************/

Adj* Get_next(Adj* x)
{
  return(x->next);
}

/***********************************************
 *  Funcao:
 *      freeVetorGrafo
 *
 *  Descricao:
 *    Liberta a memória dos Vetores de
 *    apontadores para estruturas x e y
 *
 *  Argumentos:
 *    - Vetor de Ponteiros para struct Adj x
 *    - Vetor de Ponteiros para struct Adj y
 *    - Tamanho dos Vetores anteriores (nrpal)
 *
 *  Retorna:
 *  x->next
 *************************************************/

void freeVetorGrafo(Adj** x, Adj** y, int nrpal)
{
  int i;
  Adj* aux1=NULL;
  Adj* aux2=NULL;

  for(i=0; i<nrpal; i++)
  {
    if(x[i] != NULL)
    {
      aux1=x[i];
      while(Get_next(aux1) != NULL)
      {
        aux2=Get_next(aux1);
        free(aux1);
        aux1=aux2;
      }
      free(aux1);
    }
  }

  free(x);
  free(y);
}

/***********************************************
 *  Funcao:
 *      Ins_Lista_Adj
 *
 *  Descricao:
 *    Insere Adjacentes à palavra de indice indice_p
 *
 *  Argumentos:
 *    - Vetor _VetorGrafo de ponteiros para struct Adj
 *    - Vetor _VetorGrafoBack de ponteiros para struct Adj
 *    - Vetor Dicionario de ponteiros para struct TabPal
 *    - Posicao no Vetor Dicionario Dic_Pos
 *    - Inteiro indice_p
 *    - Vetor de inteiros _ja_no_grafo
 *
 *  Retorna:
 *  Nada
 *************************************************/

void Ins_Lista_Adj(Adj** _VetorGrafo, Adj** _VetorGrafoBack, TabPal** _Dicionario, int Dic_Pos, int indice_p, int* _ja_no_grafo)
{
  int i=0;
  int new_perm;
  int nr_perm_max=Get_nrpermmax(_Dicionario[Dic_Pos]);

  char* p_ind_adj = Get_Word(_Dicionario, Dic_Pos, indice_p);
  char* p_new_adj = NULL;

  for(i=0; i<Get_nrpalavrastotal(_Dicionario,  Dic_Pos); i++)
  {
    if(_ja_no_grafo[i]!=1)
    {
      p_new_adj = Get_Word(_Dicionario, Dic_Pos, i);
      new_perm = Dif_Let(p_ind_adj, p_new_adj, nr_perm_max);

      if((new_perm>0) && (new_perm<=nr_perm_max))
      {
        if(_VetorGrafo[indice_p]==NULL)   /*Se ainda não houver nada na lista do indice_p*/
        {

          _VetorGrafo[indice_p] = (Adj*) calloc(1,sizeof(Adj));
          if ( _VetorGrafo[indice_p] == NULL ) {
            fprintf ( stderr, "ERROR: not enough memory available!\n" );
            exit ( 2 );
          }

          _VetorGrafoBack[indice_p]=_VetorGrafo[indice_p];

          Ins_perm(_VetorGrafoBack[indice_p], new_perm);
          Ins_indice(_VetorGrafoBack[indice_p], i);
        }
        else
        {
          (_VetorGrafoBack[indice_p])->next=(Adj*) calloc(1,sizeof(Adj));
          if ( Get_next(_VetorGrafoBack[indice_p]) == NULL ) {
            fprintf ( stderr, "ERROR: not enough memory available!\n" );
            exit ( 2 );
          }

          _VetorGrafoBack[indice_p]=Get_next(_VetorGrafoBack[indice_p]);

          Ins_perm(_VetorGrafoBack[indice_p], new_perm);
          Ins_indice(_VetorGrafoBack[indice_p], i);
        }

        if(_VetorGrafo[i]==NULL)   /*Se ainda não houver nada na lista do i*/
        {
          _VetorGrafo[i] = (Adj*) calloc(1,sizeof(Adj));
          if ( _VetorGrafo[i] == NULL ) {
            fprintf ( stderr, "ERROR: not enough memory available!\n" );
            exit ( 2 );
          }

          _VetorGrafoBack[i]=_VetorGrafo[i];

          Ins_perm(_VetorGrafoBack[i], new_perm);
          Ins_indice(_VetorGrafoBack[i], indice_p);
        }
        else
        {
          (_VetorGrafoBack[i])->next=(Adj*) calloc(1,sizeof(Adj));
          if ( Get_next(_VetorGrafoBack[i]) == NULL ) {
            fprintf ( stderr, "ERROR: not enough memory available!\n" );
            exit ( 2 );
          }

          _VetorGrafoBack[i]=Get_next(_VetorGrafoBack[i]);

          Ins_perm(_VetorGrafoBack[i], new_perm);
          Ins_indice(_VetorGrafoBack[i], indice_p);
        }
      }
    }
  }
}

/***********************************************
 *  Funcao:
 *      Dif_Let
 *
 *  Descricao:
 *    Calcula o numero de letras diferentes, tendo em
 *    conta o _nr_perm_max
 *
 *  Argumentos:
 *    - String P1
 *    - String P2
 *    - Inteiro _nr_perm_max
 *
 *  Retorna:
 *  Numero de letras diferentes sem ultrapassar
 *  o permitido
 *************************************************/

int Dif_Let(char* P1, char* P2, int _nr_perm_max)
{
  int i=0, diferencas=0;
  int _tam=strlen(P1);

  for(i=0 ; i < _tam ; i++)
  {
    if(P1[i] != P2[i])
    {
      diferencas++;
    }

    if(diferencas>_nr_perm_max)
    {
      break;
    }
  }
    return(diferencas);
}

/***********************************************
 *  Funcao:
 *      bisearch
 *
 *  Descricao:
 *    Procura a posição na tabela de palavras da
 *    uma palavra através de um algoritmo de
 *    binary search
 *
 *  Argumentos:
 *    - Vetor Dicionario de ponteiros para
 *      struct TabPal
 *    - Posicao no Vetor Dicionario
 *    - String _palavra
 *
 *  Retorna:
 *  Indice na Tabela da Palavra _palavra
 *************************************************/

int bisearch(TabPal **_Dicionario, int _DicPos, char *_palavra)
{
  int prim=0;
  int ult=(Get_nrpalavrastotal(_Dicionario, _DicPos))-1;
  int mid=(prim+ult)/2;
  char** tabela=Get_Tab(_Dicionario,  _DicPos);

  while(strcmp(_palavra, tabela[mid])!=0)
  {
    if(strcmp(_palavra, tabela[mid])<0)
    {
      ult=mid-1;
      mid=(prim+ult)/2;
    }
    if(strcmp(_palavra, tabela[mid])>0)
    {
      prim=mid+1;
      mid=(prim+ult)/2;
    }
  }
  return(mid);
}

/***********************************************
 *  Funcao:
 *      Percorre_LIsta_Adj
 *
 *  Descricao:
 *    Percorre uma certa Lista de adjacencias a
 *    uma palavra e faz as devidas alterações à
 *    heap para se realizar o Algoritmo de Dijkstra
 *
 *  Argumentos:
 *    - Ponteiro para struct do tipo Heap
 *    - Ponteiro para a Head da Heap
 *    - Ponteiro para a struct Adj que
 *    corresponde à primeira struct da LIsta de
 *    Adjacencias à palavra cujo de indice
 *    indice_VetorGrafo
 *    - Indice do da palavra de origem da
 *    LIsta de Adj
 *    - Vetor de inteiros path
 *    - Vetor de inteiros pesos_a_origem
 *    - Vetor de Inteiros head_before
 *    - Ponteiro para a struct com as informaçĩes
 *    do Problema
 *    - Vetror de inteiros _heap_pos
 *
 *  Retorna:
 *  Nada
 *************************************************/

void Percorre_Lista_Adj(Heap* _h, Vertice* _hd, Adj* _VetorGrafo, int indice_VetorGrafo, int* path, int* pesos_a_origem, int* head_before, Prob* _Problema, int* _heap_pos)
{
  Vertice* v;
  Adj* aux=NULL;
  int int_prob=Get_nr_int(_Problema);
  int perm_aux, indice_aux;
  int indice_hd=Get_indice_at(_hd);
  RemoveHead(_h, _heap_pos);
  FixDown(_h, 0, pesos_a_origem, _heap_pos);

  for (aux=_VetorGrafo; aux !=NULL; aux=Get_next(aux))
  {
    perm_aux=Get_perm(aux);
    indice_aux=Get_indice(aux);

    if((perm_aux<=int_prob) && (head_before[indice_aux]==0) && (pesos_a_origem[indice_aux]>(pesos_a_origem[indice_hd]+(perm_aux*perm_aux))))
    {
      if(pesos_a_origem[indice_aux]==INT_MAX)  /*Caso o vertice não esteja já na heap*/
      {
        _heap_pos[indice_aux]=Get_n_el(_h);

        v = create_struct_vertice();

        Ins_indice_at(v, indice_aux);
        if (Insert(_h, v) == 0)
          free(v);
      }
      pesos_a_origem[indice_aux]=pesos_a_origem[indice_hd]+(perm_aux*perm_aux);
      path[indice_aux]=indice_hd;

      FixUp(_h, _heap_pos[indice_aux], pesos_a_origem, _heap_pos);
    }
  }
}

/***********************************************
 *  Funcao:
 *      StartHeap
 *
 *  Descricao:
 *    Inicializa a struct com todas as informações
 *    da Heap que é usada para o Algoritmo
 *    de Dijkstra
 *
 *  Argumentos:
 *    - Indice da Palavra de Origem do Problema
 *    - Vetor de Inteiros pesos_a_origem
 *    - Vetor Dicionario de ponteiros para struct TabPal
 *    - Posicao no Vetor Dicionario
 *    - Vetor de Inteiros _heap_pos
 *
 *  Retorna:
 *  Ponteiro para a struct Heap criada
 *************************************************/

Heap* StartHeap(int indice_Origem, int* pesos_a_origem, TabPal** _Dicionario, int DicPos, int* _heap_pos)
{
  Vertice* v;
  Heap* _h=NewHeap(Get_nrpalavrastotal(_Dicionario, DicPos), LessNum);

  v = create_struct_vertice();
  Ins_indice_at(v, indice_Origem);
  pesos_a_origem[indice_Origem]=0;
  _heap_pos[indice_Origem]=0;

  if (Insert(_h, v) == 0)
    free(v);

  return(_h);
}

/***********************************************
 *  Funcao:
 *      Stop_Cond
 *
 *  Descricao:
 *    Verifica se o Problema em especifico
 *    já possui uma solução
 *
 *  Argumentos:
 *    - Ponteiro para struct do tipo Heap
 *    - Indice da palavra de destino do problema
 *
 *  Retorna:
 *  0 -> se já houver uma solução para o Problema
 *  1 -> se ainda não houver uma solução para
 *          o Problema
 *************************************************/

int Stop_Cond(Heap* h,  int _ind_chegada)
{
  Vertice* t;

  if(Get_n_el(h) == 0)
  {
    return(0);
  }

  t = Get_Pointer(h, 0);

  if(Get_indice_at(t)==_ind_chegada)
  {
    return(0);
  }
  else
    return(1);
}

/***********************************************
 *  Funcao:
 *      resolve_com_grafo
 *
 *  Descricao:
 *    Resolve um Problema que precisa de
 *    um grafo para ser resolvido
 *
 *  Argumentos:
 *    - Vetor _VetorGrafo de ponteiros para
 *     struct Adj
 *    - Vetor _VetorGrafoBack de ponteiros para
 *     struct Adj
 *    - Vetor de inteiros ja_no_grafo
 *    - Vetor Dicionario de ponteiros para
 *     struct TabPal
 *    - Posicao no Vetor Dicionario
 *    - Ponteiro para a struct com as informaçĩes
 *     do Problema
 *    - Indice da palavra de origem do Problema
 *    - Indice da palavra de chegada do Problema
 *
 *  Retorna:
 *  Nada
 *************************************************/

void resolve_com_grafo(Adj** VetorGrafo, Adj** VetorGrafoBack, int* ja_no_grafo, TabPal** _Dicionario, int DicPos, Prob* _Problema, int _ind_origem, int _ind_chegada)
{
  int  i, a=0, b=0;
  int indice_at_hd;
  int nr_palavras_dic=Get_nrpalavrastotal(_Dicionario, DicPos);
  Heap *h;
  Vertice* hd;
  int* resposta=NULL;
  int* head_before = (int *)calloc(nr_palavras_dic, sizeof(int));

  int* pesos_a_origem = (int *)malloc(nr_palavras_dic*sizeof(int));  /*vetor dos pesos atuais correspondentes a cada vertice*/
  for(i=0; i<nr_palavras_dic; i++)
  {
    pesos_a_origem[i]=INT_MAX; /*Mete todos os valores do vetor para inf (maior inteiro possivel)*/
  }

  int* path = (int *)malloc(nr_palavras_dic*sizeof(int)); /*vetor do caminho*/

  int* heap_pos = (int *)malloc(nr_palavras_dic*sizeof(int));

  h=StartHeap(_ind_origem, pesos_a_origem, _Dicionario, DicPos, heap_pos);

  while(Stop_Cond(h,  _ind_chegada)) /*Verifica se a heap naoestá vazia ou se já chegou à palavra destino*/
  {
    hd=Get_Pointer(h, 0);
    indice_at_hd=Get_indice_at(hd);

    head_before[indice_at_hd]=1;

    if(VetorGrafo[indice_at_hd]==NULL || ja_no_grafo[indice_at_hd]!=1)
    {
      Ins_Lista_Adj(VetorGrafo, VetorGrafoBack, _Dicionario, DicPos, indice_at_hd, ja_no_grafo); /*Caso o indice da head ainda não exista no grafo, é criada a respetiva lista de adj*/
      ja_no_grafo[indice_at_hd]=1;
    }
    Percorre_Lista_Adj(h, hd, VetorGrafo[indice_at_hd], indice_at_hd, path, pesos_a_origem, head_before, _Problema,  heap_pos);
  }


  if(Get_n_el(h)== 0)
  {
    Ins_Custo(_Problema, -1);
  }
  else
  {
    hd = Get_Pointer(h, 0);

    Ins_Custo(_Problema, pesos_a_origem[Get_indice_at(hd)]);

    for(i=_ind_chegada; i!=_ind_origem; i=path[i])
    {
      a++;
    }

    a--;

    if(a!=0)
    {
      resposta=(int *)malloc(a*sizeof(int));
      Ins_tam_resposta(_Problema, a);
    }


    for(i=path[_ind_chegada]; i!=_ind_origem; i=path[i])
    {
      resposta[b]=i;
      b++;
    }
    Ins_Vet_Resp(_Problema, resposta);
  }
  FreeHeap(h);
  free(pesos_a_origem);
  free(path);
  free(head_before);
  free(heap_pos);
}


/***********************************************
 *  Funcao:
 *      responde_probs
 *
 *  Descricao:
 *    Responde os problemas um a um, tendo
 *    em conta cada caso
 *
 *  Argumentos:
 *    - Vetor Dicionario de ponteiros para struct TabPal
 *    - Inteiro de tamanho minimo de palavras
 *    - Vetor de problemas
*     - Numero total de problemas
 *
 *  Retorna:
 *  Nada
 *************************************************/

void responde_probs(TabPal** _Dicionario, int _tmin, Prob** _VetorProb, int _probmax)
{
  int i=0, tam_grafo_at=0, x;
  int ind_origem, ind_chegada, tam_prob;
  Adj** VetorGrafo=NULL;
  Adj** VetorGrafoBack=NULL;
  int* ja_no_grafo=NULL;



  for(i=0; i<_probmax; i++)     /*Verificação de diferença do tamanho anterior*/
  {
    tam_prob=Get_tam(_VetorProb[i]);

    if(i != 0 && Get_tam(_VetorProb[i-1]) != tam_prob && VetorGrafo != NULL)
    {
      freeVetorGrafo(VetorGrafo, VetorGrafoBack, tam_grafo_at);
      free(ja_no_grafo);
      VetorGrafo=NULL;
      VetorGrafoBack=NULL;
    }

    if(Get_nr_int(_VetorProb[i])==-1)
    {
      /*Dif uma letra*/
      Ins_Custo(_VetorProb[i], 1);

    }
    else if(Get_nr_int(_VetorProb[i])==0)
    {
      /*Se as palavras forem iguais peso caminho 0, se nao forem nao existe caminho*/

      if(strcmp(Get_P1(_VetorProb[i]),Get_P2(_VetorProb[i]))==0)
      {
        Ins_Custo(_VetorProb[i], 0);
      }
      else
      {
        Ins_Custo(_VetorProb[i], -1);
      }
    }
    else
    {
      if(VetorGrafo==NULL)
      {
        tam_grafo_at=Get_nrpalavrastotal(_Dicionario, tam_prob -_tmin);
        VetorGrafo = CriaVetorGrafo(tam_grafo_at);
        VetorGrafoBack = CriaVetorGrafo(tam_grafo_at);
        ja_no_grafo=(int*) malloc(tam_grafo_at*sizeof(int));
        for(x=0; x<tam_grafo_at; x++)
        {
          ja_no_grafo[x]=0;
        }
      }

      ind_origem=bisearch(_Dicionario, (tam_prob -_tmin), Get_P1(_VetorProb[i]));
      ind_chegada=bisearch(_Dicionario, (tam_prob -_tmin), Get_P2(_VetorProb[i]));

      resolve_com_grafo(VetorGrafo, VetorGrafoBack, ja_no_grafo, _Dicionario, tam_prob -_tmin, _VetorProb[i], ind_origem, ind_chegada);
    }
  }

  if(VetorGrafo!=NULL)
  {
    freeVetorGrafo(VetorGrafo, VetorGrafoBack, tam_grafo_at);
    free(ja_no_grafo);
  }
}

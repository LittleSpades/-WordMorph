#include "defs.h"
#include "fprob.h"


struct Problema{
  int nr_prob;
  int nr_int; /* -1 -> Diferenca de uma letra || 0 -> apenas verificar se as palavras são iguais ou nao*/
  int tamanho;

  char *p1;
  char *p2;

  int custo;
  int tam_resposta;
  int* resposta;
};

/***********************************************
 *  Funcao:
 *      Ins_tam_resposta
 *
 *  Descricao:
 *    Insere num int o tamanho da resposta
 *
 *  Argumentos:
 *    - Ponteiro para struct Problema
 *    - Um inteiro ao qual se pretende igualar o tamanho
 *
 *  Retorna:
 *  Nada
 *
 *************************************************/

void Ins_tam_resposta(Prob* x, int y)
{
  x->tam_resposta=y;
}



/***********************************************
 *  Funcao:
 *      Get_tam_resposta
 *
 *  Descricao:
 *    Obtem o tamanho da resposta
 *
 *  Argumentos:
 *    - Ponteiro para struct Problema
 *
 *  Retorna:
 *  Problema->tam_resposta
 *************************************************/

int Get_tam_resposta(Prob* x)
{
  return(x->tam_resposta);
}

/***********************************************
 *  Funcao:
 *      Ins_Custo
 *
 *  Descricao:
 *    Insere num int o custo
 *
 *  Argumentos:
 *    - Ponteiro para struct Problema
 *    - Um inteiro ao qual se pretende igualar o custo
 *
 *  Retorna:
 *  Nada
 *************************************************/

void Ins_Custo(Prob* x, int y)
{
  x->custo=y;
}


/***********************************************
 *  Funcao:
 *      Get_Custo
 *
 *  Descricao:
 *    Obtem o custo
 *
 *  Argumentos:
 *    - Ponteiro para struct Problema
 *
 *  Retorna:
 *  Problema->custo
 *************************************************/

int Get_Custo(Prob* x)
{
  return(x->custo);
}


/***********************************************
 *  Funcao:
 *      Ins_Vet_Resp
 *
 *  Descricao:
 *    Insere num int o vetor de resposta
 *
 *  Argumentos:
 *    - Ponteiro para struct Problema
 *    - Um ponteiro para inteiro no qual se pretende inserir o vetor de resposta
 *
 *  Retorna:
 *  Nada
 *************************************************/

void Ins_Vet_Resp(Prob* x, int* n)
{
  x->resposta=n;
}


/***********************************************
 *  Funcao:
 *      Get_Vet_Resp
 *
 *  Descricao:
 *    Obtem o vetor de resposta
 *
 *  Argumentos:
 *    - Ponteiro para struct Problema
 *
 *  Retorna:
 *  Problema->resposta
 *************************************************/

int* Get_Vet_Resp(Prob* x)
{
  return(x->resposta);
}

/***********************************************
 *  Funcao:
 *      Ins_nr_prob
 *
 *  Descricao:
 *    Insere num int o numero do problema
 *
 *  Argumentos:
 *    - Ponteiro para struct Problema
 *    - Um inteiro no qual se pretende inserir o numero do problema
 *
 *  Retorna:
 *  Nada
 *************************************************/

void Ins_nr_prob(Prob* x, int _nr_prob)
{
  x->nr_prob=_nr_prob;
}


/***********************************************
 *  Funcao:
 *      Get_nr_prob
 *
 *  Descricao:
 *    Obtem o numero do problema
 *
 *  Argumentos:
 *    - Ponteiro para struct Problema
 *
 *  Retorna:
 *  Problema->nr_prob
 *************************************************/

int Get_nr_prob(Prob* x)
{
  return(x->nr_prob);
}


/***********************************************
 *  Funcao:
 *      Ins_nr_int
 *
 *  Descricao:
 *    Insere num int o numero inteiro relativo ao problema
 *
 *  Argumentos:
 *    - Ponteiro para struct Problema
 *    - Um inteiro no qual se pretende inserir inteiro do problema
 *
 *  Retorna:
 *  Nada
 *************************************************/

void Ins_nr_int(Prob* x, int _nr_int)
{
  x->nr_int=_nr_int;
}

/***********************************************
 *  Funcao:
 *      Get_nr_int
 *
 *  Descricao:
 *    Obtem o inteiro do problema
 *
 *  Argumentos:
 *    - Ponteiro para struct Problema
 *
 *  Retorna:
 *  Problema->nr_int
 *************************************************/

int Get_nr_int(Prob* x)
{
  return(x->nr_int);
}


/***********************************************
 *  Funcao:
 *      Ins_tam
 *
 *  Descricao:
 *    Insere num int o tamanho das palavras do problema
 *
 *  Argumentos:
 *    - Ponteiro para struct Problema
 *    - Um inteiro no qual se pretende inserir o tamanho
 *
 *  Retorna:
 *  Nada
 *************************************************/

void Ins_tam(Prob* x, int _tam)
{
  x->tamanho=_tam;
}

/***********************************************
 *  Funcao:
 *      Get_tam
 *
 *  Descricao:
 *    Obtem o tamanho das palavras do problema
 *
 *  Argumentos:
 *    - Ponteiro para struct Problema
 *
 *  Retorna:
 *  Problema->tamanho
 *************************************************/

int Get_tam(Prob* x)
{
  return(x->tamanho);
}


/***********************************************
 *  Funcao:
 *      Ins_P1
 *
 *  Descricao:
 *    Insere numa string a palavra 1 do problema
 *
 *  Argumentos:
 *    - Ponteiro para struct Problema
 *    - Uma string na qual se pretende guardar a palavra P1
 *
 *  Retorna:
 *  Nada
 *************************************************/

void Ins_P1(Prob* x, const char *new_word)
{
  x->p1=(char*) malloc((Get_tam(x)+1)*sizeof(char));

  strcpy(x->p1, new_word);
}


/***********************************************
 *  Funcao:
 *      Get_P1
 *
 *  Descricao:
 *    Obtem a palavra 1
 *
 *  Argumentos:
 *    - Ponteiro para struct Problema
 *
 *  Retorna:
 *  Palavra 1 do problema
 *************************************************/

char* Get_P1(Prob* x)
{
  return(x->p1);
}


/***********************************************
 *  Funcao:
 *      Ins_P2
 *
 *  Descricao:
 *    Insere numa string a palavra 2 do problema
 *
 *  Argumentos:
 *    - Ponteiro para struct Problema
 *    - Uma string na qual se pretende guardar a palavra P2
 *
 *  Retorna:
 *  Nada
 *************************************************/

void Ins_P2(Prob* x, const char *new_word)
{
  x->p2=(char*) malloc((Get_tam(x)+1)*sizeof(char));

  strcpy(x->p2, new_word);
}


/***********************************************
 *  Funcao:
 *      Get_P2
 *
 *  Descricao:
 *    Obtem a palavra 2
 *
 *  Argumentos:
 *    - Ponteiro para struct Problema
 *
 *  Retorna:
 *  Palavra 2 do problema
 *************************************************/

char* Get_P2(Prob* x)
{
  return(x->p2);
}


/***********************************************
 *  Funcao:
 *      VerifyLetDif1
 *
 *  Descricao:
 *    Verifica se as palavras apenas diferem numa letra
 *
 *  Argumentos:
 *    - Ponteiro para struct Problema
 *
 *  Retorna:
 *  1 caso true, 0 caso false
 *************************************************/

int VerifyLetDif1(Prob* x, int tam)
{
  int i=0, diferencas=0;
  char* P1=Get_P1(x);
  char* P2=Get_P2(x);

  for(i=0 ; i < tam ; i++)
  {
    if(P1[i] != P2[i])
			diferencas++;
  }
  if(diferencas == 1)
  {
    return(1);
  }
  if(diferencas==0)
  {
    return(0);
  }
  else
  {
    return(2);
  }
}


/***********************************************
 *  Funcao:
 *      Create_Prob
 *
 *  Descricao:
 *    Aloca espaço para um problema
 *
 *  Argumentos:
 *   Nenhum
 *
 *  Retorna:
 *  Ponteiro para a struct Problema
 *************************************************/

Prob* Create_Prob()
{
  Prob* x=(Prob*) calloc(1,sizeof(Prob));
  if ( x == NULL ) {
    fprintf ( stderr, "ERROR: not enough memory available!\n" );
    exit ( 2 );
  }

  return(x);
}


/***********************************************
 *  Funcao:
 *      criavetorprob
 *
 *  Descricao:
 *    A partir do ficheiro de problemas cria um vetor de ponteiros
 *    para a struct Problema em que cada indice guarda um problema
 *
 *  Argumentos:
 *    - Nome do ficheiro de problemas
 *    - Tamanho maximo
 *    - Tamanho minimo
 *    - Numero maximo de problemas
 *
 *  Retorna:
 *  Duplo ponteiro para a struct Problema
 *************************************************/

Prob** criavetorprob(const char* nomefileprob, int *tmax, int *tmin, int *probmax)
{
  int i=0, b, nperm;
  char p1[PMAX], p2[PMAX];
  FILE *fpin;
  Prob** _vetorprob;

  fpin = fopen(nomefileprob, "r");
  if ( fpin == NULL ) {
  fprintf ( stderr, "ERROR: It is not possible to open file %s!\n", nomefileprob );
  exit ( 1 );
  }

  while(fscanf(fpin, "%s %s %d", p1, p2, &nperm)==3) /*Conta o numero de Probs*/
  {
    i++;
  }

  _vetorprob=(Prob**) calloc(i,sizeof(Prob*));
  if ( _vetorprob == NULL ) {
    fprintf ( stderr, "ERROR: not enough memory available!\n" );
    exit ( 2 );
  }

  *probmax=i;

rewind(fpin);

  for(i=0; fscanf(fpin, "%s %s %d", p1, p2, &nperm)==3; i++)
  {
    _vetorprob[i]=Create_Prob();
    b=strlen(p1);

    Ins_tam(_vetorprob[i], b);

    Ins_P1(_vetorprob[i], p1);
    Ins_P2(_vetorprob[i], p2);


    if(VerifyLetDif1(_vetorprob[i], b)==0)
    {
      Ins_nr_int(_vetorprob[i], 0);
    }
    else if(VerifyLetDif1(_vetorprob[i], b)==1)
    {
      Ins_nr_int(_vetorprob[i],-1);
    }
    else if(nperm > b)  /*Caso o numero de permutações for superior ao tamanho da palavra*/
    {
      Ins_nr_int(_vetorprob[i],b);

      if(b>(*tmax))
      {
        (*tmax)=b;
      }

      if(b<(*tmin))
      {
        (*tmin)=b;
      }
    }
    else
    {
      if(b>(*tmax))
      {
        (*tmax)=b;
      }

      if(b<(*tmin))
      {
        (*tmin)=b;
      }


      Ins_nr_int(_vetorprob[i],nperm);
    }

    Ins_nr_prob(_vetorprob[i], i);
  }

  fclose(fpin);

  return(_vetorprob);
}


/***********************************************
 *  Funcao:
 *      freeprob
 *
 *  Descricao:
 *    Liberta a memoria alocada para o vetor de problemas
 *
 *  Argumentos:
 *    - Vetor de problemas
 *    - Numero máximo de problemas
 *
 *  Retorna:
 *  Nada
 *************************************************/

void freeprob(Prob **_VetorProb, int _probmax)
{
  int i;

  for(i=0; i<(_probmax); i++)
  {

    free((_VetorProb[i])->p1);
    free((_VetorProb[i])->p2);
    if((_VetorProb[i])->resposta!=NULL)
    {
      free((_VetorProb[i])->resposta);
    }

    free(_VetorProb[i]);

  }

  free(_VetorProb);
}

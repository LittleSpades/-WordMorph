#include "defs.h"
#include "tabpal.h"

struct tabpal{
  int nrpalavrastotal;
  int nrpalavrasatual;

  int nrpermmax;

  char **tabela;
};


/***********************************************
 *  Funcao:
 *      Create_Dicionario
 *
 *  Descricao:
 *    Aloca o Vetor de ponteiros para struct TabPal
 *
 *  Argumentos:
 *    - Inteiros de tamanho maximo e minimo de palavras
 *
 *  Retorna:
 *  Vetor de ponteiros para struct TabPal
 *************************************************/

TabPal** Create_Dicionario(int _tmin, int _tmax)
{
  TabPal** _Dicionario = (TabPal**) calloc((_tmax-_tmin+1),sizeof(TabPal*));
  if ( _Dicionario == NULL ) {
    fprintf ( stderr, "ERROR: not enough memory available!\n" );
    exit ( 2 );
  }

  return(_Dicionario);
}


/***********************************************
 *  Funcao:
 *      Create_TabPal
 *
 *  Descricao:
 *    Aloca o Vetor de ponteiros para struct TabPal
 *
 *  Argumentos:
 *    - Inteiros de tmanhao maximo e minimo de palavras
 *
 *  Retorna:
 *  Vetor de ponteiros para struct TabPal
 *************************************************/

TabPal* Create_TabPal()
{
  TabPal* TP=(TabPal*) calloc(1, sizeof(TabPal));
  if ( TP == NULL ) {
    fprintf ( stderr, "ERROR: not enough memory available!\n" );
    exit ( 2 );
  }

  return(TP);
}

/***********************************************
 *  Funcao:
 *      criavetordic
 *
 *  Descricao:
 *    Cria o Vetor de ponteiros para struct TabPal e cria tabelas de palavras
 *     nas posicoes necessarias do vetor
 *
 *  Argumentos:
 *    - Inteiros de tmanhao maximo e minimo de palavras
 *    - Vetor de problemas
 *    - Numero total de problemas
 *
 *  Retorna:
 *  Vetor de ponteiros para struct TabPal
 *************************************************/

TabPal** criavetordic(int _tmax, int _tmin, Prob** _VetorProb, int _probmax)
{
  int i;
  TabPal** _Dicionario;

  _Dicionario = Create_Dicionario(_tmin, _tmax);

  for(i=0; i<_probmax; i++)
  {
    if(_Dicionario[(Get_tam(_VetorProb[i]))-(_tmin)]==NULL)
    {
      _Dicionario[(Get_tam(_VetorProb[i]))-(_tmin)] = Create_TabPal();
    }

    if(Get_nrpermmax(_Dicionario[(Get_tam(_VetorProb[i]))-(_tmin)])<Get_nr_int(_VetorProb[i]))
    {
      Ins_nrpermmax(_Dicionario[(Get_tam(_VetorProb[i]))-(_tmin)], Get_nr_int(_VetorProb[i]));
    }
  }

  return(_Dicionario);
}


/***********************************************
 *  Funcao:
 *      CreateTabelaPalavras
 *
 *  Descricao:
 *    Aloca a tabela de palavras
 *
 *  Argumentos:
 *    - Vetor Dicionario de ponteiros para struct TabPal
 *    - Inteiros de tamanho maximo e minimo de palavras
 *
 *  Retorna:
 *  Nada
 *************************************************/

void CreateTabelaPalavras(TabPal** _Dicionario, int _tmin, int _tmax)
{
  int i, a;

  for(i=0; i<=(_tmax-_tmin); i++)
  {
    if(_Dicionario[i]!=NULL)
    {
      (_Dicionario[i])->tabela = (char **)malloc(((_Dicionario[i])->nrpalavrastotal)*sizeof (char *));
      if ( (_Dicionario[i])->tabela == NULL ) {
        fprintf ( stderr, "ERROR: not enough memory available!\n" );
        exit ( 2 );
      }

      for(a=0; a<((_Dicionario[i])->nrpalavrastotal); a++)
      {
        (_Dicionario[i])->tabela[a] = (char *)malloc((i+_tmin+1) * sizeof (char));
        if ( (_Dicionario[i])->tabela[a] == NULL ) {
          fprintf ( stderr, "ERROR: not enough memory available!\n" );
          exit ( 2 );
        }
      }
    }
  }
}


/***********************************************
 *  Funcao:
 *      VerifyDicPos
 *
 *  Descricao:
 *    Verifica se o Vetor Dicionario esta vazio na posicao _DicPos
 *
 *  Argumentos:
 *    - O Vetor Dicionario de ponteiros para struct TabPal
 *
 *  Retorna:
 *  0 caso esteja vazio, 1 caso nao esteja
 *************************************************/

int VerifyDicPos(TabPal **_Dicionario, int _DicPos)
{
  if(_Dicionario[_DicPos]==NULL)
    return(0);
  else
    return(1);
}

/***********************************************
 *  Funcao:
 *      freedic
 *
 *  Descricao:
 *    Liberta o Vetor Dicionario
 *
 *  Argumentos:
 *    - Vetor Dicionario de ponteiros para struct TabPal
 *    - Inteiros de tamanho maximo e minimo de palavras
 *
 *  Retorna:
 *  Vetor de ponteiros para struct TabPal
 *************************************************/

void freedic(TabPal **_Dicionario, int _tmax, int _tmin)
{
  int i, j;

  for(i=0; i<=(_tmax-_tmin); i++)
  {
    if(_Dicionario[i]!=NULL)
    {
      for(j=0; j<=(((_Dicionario[i])->nrpalavrastotal)-1); j++)
      {
        free((_Dicionario[i])->tabela[j]);
      }
      free((_Dicionario[i])->tabela);
      free(_Dicionario[i]);
    }
  }

  free(_Dicionario);
}


/***********************************************
 *  Funcao:
 *      Ins_nrpalavrastotal
 *
 *  Descricao:
 *    Insere num int o nmero de palavras total numa posicao do vetor dicionario
 *
 *  Argumentos:
 *    - Vetor Dicionario de ponteiros para struct TabPal
 *    - Um inteiro ao qual se pretende igualar o numero de palavras total
 *
 *  Retorna:
 *  Nada
 *************************************************/

void Ins_nrpalavrastotal(TabPal **_Dicionario, int _DicPos, int _newnpt)
{
  _Dicionario[_DicPos]->nrpalavrastotal=_newnpt;
}


/***********************************************
 *  Funcao:
 *      Inc_nrpalavrastotal
 *
 *  Descricao:
 *    Incrementa o numero total de palavras na posicao _DicPos do Dicionario
 *
 *  Argumentos:
 *    - Vetor Dicionario de ponteiros para struct TabPal
 *    - Posicao no Dicionario
 *
 *  Retorna:
 *  Nada
 *************************************************/

void Inc_nrpalavrastotal(TabPal **_Dicionario, int _DicPos)
{
  (_Dicionario[_DicPos]->nrpalavrastotal)++;
}



/***********************************************
 *  Funcao:
 *      Get_nrpalavrastotal
 *
 *  Descricao:
 *    Obtem o numero de palavras total de uma tabela na posicao
 *    _DicPos do Vetor Dicionario
 *
 *  Argumentos:
 *    - Vetor Dicionario de ponteiros para struct TabPal
 *    - Posicao no Vetor Dicionario
 *
 *  Retorna:
 *  _Dicionario[_DicPos]->nrpalavrastotal
 *************************************************/

int Get_nrpalavrastotal(TabPal **_Dicionario, int _DicPos)
{
  return(_Dicionario[_DicPos]->nrpalavrastotal);
}


/***********************************************
 *  Funcao:
 *      Ins_nrpalavrasatual
 *
 *  Descricao:
 *    Insere o numero de palavras atual num inteiro na posicao dada por _DicPos
 *
 *  Argumentos:
 *    - Vetor Dicionario de ponteiros para struct TabPal
 *    - Posicao no Dicionario
 *    - Inteiro em que se vai inserir o numero de palavras atual
 *
 *  Retorna:
 *  Nada
 *************************************************/

void Ins_nrpalavrasatual(TabPal **_Dicionario, int _DicPos, int _newnpa)
{
  _Dicionario[_DicPos]->nrpalavrasatual=_newnpa;
}


/***********************************************
 *  Funcao:
 *      Inc_nrpalavrasatual
 *
 *  Descricao:
 *    Incrementa o numero atual de palavras na posicao _DicPos do Dicionario
 *
 *  Argumentos:
 *    - Vetor Dicionario de ponteiros para struct TabPal
 *    - Posicao no Dicionario
 *
 *  Retorna:
 *  Nada
 *************************************************/

void Inc_nrpalavrasatual(TabPal **_Dicionario, int _DicPos)
{
  (_Dicionario[_DicPos]->nrpalavrasatual)++;
}


/***********************************************
 *  Funcao:
 *      Get_nrpalavrasatual
 *
 *  Descricao:
 *    Obtem o numero de palavras atual de uma tabela na posicao
 *    _DicPos do Vetor Dicionario
 *
 *  Argumentos:
 *    - Vetor Dicionario de ponteiros para struct TabPal
 *    - Posicao no Vetor Dicionario
 *
 *  Retorna:
 *  _Dicionario[_DicPos]->nrpalavrasatual
 *************************************************/

int Get_nrpalavrasatual(TabPal **_Dicionario, int _DicPos)
{
  return(_Dicionario[_DicPos]->nrpalavrasatual);
}


/***********************************************
 *  Funcao:
 *      Ins_Word
 *
 *  Descricao:
 *    Insere uma palavra numa string
 *
 *  Argumentos:
 *    - Vetor Dicionario de ponteiros para struct TabPal
 *    - Posicao no Dicionario
 *    - String em que se vai inserir a palavra
 *
 *  Retorna:
 *  Nada
 *************************************************/

void Ins_Word(TabPal **_Dicionario, int _DicPos, const char *new_word)
{
  strcpy((_Dicionario[_DicPos])->tabela[Get_nrpalavrasatual(_Dicionario, _DicPos)], new_word);
  Inc_nrpalavrasatual(_Dicionario,  _DicPos);
}


/***********************************************
 *  Funcao:
 *      Get_Tab
 *
 *  Descricao:
 *    Obtem a tabela na posicao
 *    _DicPos do Vetor Dicionario
 *
 *  Argumentos:
 *    - Vetor Dicionario de ponteiros para struct TabPal
 *    - Posicao no Vetor Dicionario
 *
 *  Retorna:
 *  _Dicionario[_DicPos]->tabela
 *************************************************/

char** Get_Tab(TabPal **_Dicionario, int _DicPos)
{
  return(_Dicionario[_DicPos]->tabela);
}


/***********************************************
 *  Funcao:
 *      Get_Word
 *
 *  Descricao:
 *    Obtem uma palavra da tabela na posicao
 *    _DicPos do Vetor Dicionario
 *
 *  Argumentos:
 *    - Vetor Dicionario de ponteiros para struct TabPal
 *    - Posicao no Vetor Dicionario
 *    - Indice na tabela;
 *
 *  Retorna:
 *  _Dicionario[_DicPos]->tabela[_indTab]
 *************************************************/

char* Get_Word(TabPal **_Dicionario, int _DicPos, int _indTab)
{
  return(_Dicionario[_DicPos]->tabela[_indTab]);
}


/***********************************************
 *  Funcao:
 *      Ins_nrpermmax
 *
 *  Descricao:
 *    Insere o numero de permutacoes maximo num inteiro
 *
 *  Argumentos:
 *    - Ponteiro para struct TabPal (Dicionario)
 *    - Inteiro em que se vai inserir o numero de permutacoes maximo
 *
 *  Retorna:
 *  Nada
 *************************************************/

void Ins_nrpermmax(TabPal *_Dicionario, int _nrperm)
{
  _Dicionario->nrpermmax=_nrperm;
}


/***********************************************
 *  Funcao:
 *      Get_nrpermmax
 *
 *  Descricao:
 *    Obtem o numero de permutacoes maximo entre palavras da tabela
 *
 *  Argumentos:
 *    - Ponteiro para struct TabPal
 *
 *  Retorna:
 *  _Dicionario[_DicPos]->nrpalavrastotal
 *************************************************/

int Get_nrpermmax(TabPal *_Dicionario)
{
  return(_Dicionario->nrpermmax);
}

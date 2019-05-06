#include "imprimef.h"
#include "defs.h"


/***********************************************
 *  Funcao:
 *      imprime_res
 *
 *  Descricao:
 *    Imprime o ficheiro de saida
 *    (Esta funcao considera 3 casos: ser possivel e ser diferenca 1, ser
 *    possivel e ser diferenca 2, ser impossivel isto e -1)
 *
 *  Argumentos:
 *    - Nome do ficheiro de probemas
 *    - Tabela de palavras
 *    - Tamanho minimo das palavras
 *    - Vetor de problemas
 *    - Numero maximo de problemas
 *
 *  Retorna:
 *  Nada
 *************************************************/

void imprime_res(const char* nomefileprob, TabPal **_Dicionario, int _tmin, Prob** _VetorProb, int _probmax)
{
  int i, a;
  int* resp_aux=NULL;
  char nomefres[PMAX];
  int num =strlen(nomefileprob)-3;
  FILE *fpout;

  strncpy(nomefres,nomefileprob,num);
  nomefres[strlen(nomefileprob)-4] = '\0';

  strcat(nomefres, ".path");

  fpout = fopen(nomefres, "w");
  if ( fpout == NULL ) {
  fprintf ( stderr, "ERROR: It is not possible to open file %s!\n", nomefileprob );
  exit ( 1 );
  }

  for(i=0; i<_probmax; i++)
  {
    if(Get_Custo(_VetorProb[i])==-1)
    {
      fprintf(fpout, "%s -1\n", Get_P1(_VetorProb[i]));
      fprintf(fpout, "%s\n\n", Get_P2(_VetorProb[i]));
    }
    else if(Get_nr_int(_VetorProb[i])==-1)
    {
      fprintf(fpout, "%s 1\n", Get_P1(_VetorProb[i]));
      fprintf(fpout, "%s\n\n", Get_P2(_VetorProb[i]));
    }
    else if(Get_nr_int(_VetorProb[i])==0)
    {
      fprintf(fpout, "%s %d\n", Get_P1(_VetorProb[i]), Get_Custo(_VetorProb[i]));
      fprintf(fpout, "%s\n\n", Get_P2(_VetorProb[i]));
    }
    else
    {
      fprintf(fpout, "%s %d\n", Get_P1(_VetorProb[i]), Get_Custo(_VetorProb[i]));
      resp_aux = Get_Vet_Resp(_VetorProb[i]);

      for(a=Get_tam_resposta(_VetorProb[i])-1; a>=0; a--)
      {
        fprintf(fpout, "%s\n", Get_Word(_Dicionario,  Get_tam(_VetorProb[i])-_tmin, resp_aux[a]));
      }

      fprintf(fpout, "%s\n\n", Get_P2(_VetorProb[i]));
    }
  }
  fclose(fpout);
}

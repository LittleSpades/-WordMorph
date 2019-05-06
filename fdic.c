#include "fdic.h"


/***********************************************
 *  Funcao:
 *    preenchedic
 *
 *  Descricao:
 *    Preenche os campos da estrutura TabPal (numero de palavras total,
 *    tabela de palavras) e organiza as palavras por tamanho
 *
 *  Argumentos:
 *    - Ponteiro para o ficheiro de dicionario
 *    - A tabela de palavras (duplo ponteiro para struct)
 *    - Tamanho da maior palavra
 *    - Tamanho da menor palavra
 *
 *  Retorna:
 *  Nada
 *
 *************************************************/

void preenchedic(const char *nomefiledic, TabPal **_Dicionario, int tmax, int tmin)
{
    int i;
    char palavra[PMAX];
    FILE *fpin;

  fpin = fopen(nomefiledic, "r");
  if ( fpin == NULL ) {
    fprintf ( stderr, "ERROR: It is not possible to open file %s!\n", nomefiledic );
    exit ( 1 );
  }

  while(fscanf(fpin, "%s", palavra) == 1)
  {
    i = strlen(palavra);
    if((i-tmin>=0)&&(i<=tmax)&&(VerifyDicPos(_Dicionario, i-tmin)))   /*Verifica se essa palavra é necessária (através do seu tamanho)*/
    {
      Inc_nrpalavrastotal(_Dicionario, i-tmin);
    }
  }

  CreateTabelaPalavras(_Dicionario, tmin, tmax);

  rewind(fpin);

  while(fscanf(fpin, "%s", palavra) == 1)
  {
    i = strlen(palavra);

    if((i-tmin>=0)&&(i<=tmax)&&(VerifyDicPos(_Dicionario, i-tmin)))   /*Verifica se essa palavra é necessária (através do seu tamanho)*/
    {
      Ins_Word(_Dicionario, i-tmin, palavra);
    }
  }

  for(i=0; i<=(tmax-tmin); i++)
  {
    if(VerifyDicPos(_Dicionario, i))
    {
      quicksortchar(Get_Tab(_Dicionario, i), 0, (Get_nrpalavrastotal(_Dicionario, i))-1);
    }
  }

  fclose(fpin);
}

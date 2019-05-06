#include "defs.h"
#include "tabpal.h"
#include "fdic.h"
#include "resolve.h"
#include "fprob.h"
#include "quicks.h"
#include "imprimef.h"

int main(int argc, char const *argv[]) {

  int tmax=0, tmin=PMAX, probmax=0; /*probmax=numero maximo do problema*/
  TabPal** Dicionario=NULL;
  Prob** VetorProb=NULL;

  if (argc < 3) {
    fprintf(stderr, "Usage: %s <file>...\n", argv[0]);
    exit(1);
  }

  /*Cria o vetor de problemas e ordena-o por tamanho de palavras*/

  VetorProb = criavetorprob(argv[2], &tmax, &tmin, &probmax);

  if(tmin!=tmax)
  {
    quicksorttam(VetorProb, 0, probmax-1);
  }

/*Cria o Vetor Dicionario de ponteiros para TabPal e preeche o mesmo*/

  Dicionario = criavetordic(tmax, tmin, VetorProb, probmax);
  preenchedic(argv[1], Dicionario, tmax, tmin);

/*Comeca a responder aos problemas*/
  responde_probs(Dicionario, tmin, VetorProb, probmax);

  if(tmin!=tmax)
  {
    quicksortex(VetorProb, 0, probmax-1);
  }

/*Apos a resoluca, imprime o resultadono ficheiro de saida*/

  imprime_res(argv[2], Dicionario, tmin, VetorProb, probmax);

/*Liberta a memória alocada*/

  freedic(Dicionario, tmax, tmin);
  freeprob(VetorProb, probmax);
  return 0;
}

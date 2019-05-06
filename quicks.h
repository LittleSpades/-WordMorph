#ifndef quicksHeader
#define quicksHeader

#include "fprob.h"

void string_swap(char** _tabela, int _i, int _j);
int partitionchar( char** _tabela, int l, int r);
void quicksortchar(char** _tabela, int l, int r);

void quicksorttam(Prob** _VetorProb, int l, int r);
int partitiontam(Prob** _VetorProb, int l, int r);

void quicksortex(Prob** _VetorProb, int l, int r);
int partitionex(Prob** _VetorProb, int l, int r);

void tam_ex_swap(Prob** _VetorProb, int _i, int _j);

#endif

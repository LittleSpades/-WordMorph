#ifndef estruturasHeader
#define estruturasHeader

#include "fprob.h"

typedef struct tabpal TabPal;

TabPal** criavetordic(int _tmax, int _tmin, Prob** _VetorProb, int _probmax);

TabPal** Create_Dicionario(int _tmin, int _tmax);

TabPal* Create_TabPal();

void CreateTabelaPalavras(TabPal** _Dicionario, int _tmin, int _tmax);

int VerifyDicPos(TabPal **_Dicionario, int _DicPos);

void freedic(TabPal **_Dicionario, int _tmax, int _tmin);

void Ins_nrpalavrastotal(TabPal **_Dicionario, int _DicPos, int _newnpt);

void Inc_nrpalavrastotal(TabPal **_Dicionario, int _DicPos);

int Get_nrpalavrastotal(TabPal **_Dicionario, int _DicPos);

void Ins_nrpalavrasatual(TabPal **_Dicionario, int _DicPos, int _newnpa);

void Inc_nrpalavrasatual(TabPal **_Dicionario, int _DicPos);

int Get_nrpalavrasatual(TabPal **_Dicionario, int _DicPos);

void Ins_Word(TabPal **_Dicionario, int _DicPos, const char *new_word);

char** Get_Tab(TabPal **_Dicionario, int _DicPos);

char* Get_Word(TabPal **_Dicionario, int _DicPos, int _indTab);

void Ins_nrpermmax(TabPal *_Dicionario, int _nrperm);

int Get_nrpermmax(TabPal *_Dicionario);

#endif

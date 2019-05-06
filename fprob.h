#ifndef fprobHeader
#define fprobHeader

typedef struct Problema Prob;

void Ins_tam_resposta(Prob* x, int y);

int Get_tam_resposta(Prob* x);

void Ins_Custo(Prob* x, int y);

int Get_Custo(Prob* x);

void Create_Vet_Resp(Prob* x, int y);

void Ins_nr_resposta(Prob* x, int indice, int n);

void Ins_Vet_Resp(Prob* x, int* n);

int* Get_Vet_Resp(Prob* x);

void Ins_nr_prob(Prob* x, int _nr_prob);

int Get_nr_prob(Prob* x);

void Ins_nr_prob(Prob* x, int _nr_int);

int Get_nr_int(Prob* x);

void Ins_tam(Prob* x, int _tam);

int Get_tam(Prob* x);

void Ins_P1(Prob* x, const char *new_word);

char* Get_P1(Prob* x);

void Ins_P2(Prob* x, const char *new_word);

char* Get_P2(Prob* x);

int VerifyLetDif1(Prob* x, int tam);

Prob* Create_Prob();

Prob** criavetorprob(const char* nomefileprob, int *tmax, int *tmin, int *probmax);

void freeprob(Prob **_VetorProb, int _probmax);

#endif

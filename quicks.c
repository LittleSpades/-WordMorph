#include "quicks.h"
#include "defs.h"


/***********************************************
 *  Funcao:
 *      string_swap
 *
 *  Descricao:
 *    Troca duas strings
 *
 *  Argumentos:
 *    - A tabela de palavras
 *    - Dois inteiros que sao as posicoes que se pretende trocar
 *
 *  Retorna:
 *  Nada
 *************************************************/

void string_swap(char** _tabela, int _i, int _j)
{
	char *temp=NULL;

	temp = _tabela[_i];
	_tabela[_i]= _tabela[_j];
	_tabela[_j]= temp;
}


/***********************************************
 *  Funcao:
 *      partitionchar
 *
 *  Descricao:
 *    Faz uma particao na tabela. E como que a primeira
 *		iteracao daquilo que sera a base do algoritmo de quicksort
 *
 *  Argumentos:
 *    - Tabela de palavras
 *    - Dois inteiros (l,r) que vao designar os limites esquerdo (l) e
 *		direito (r) de onde se vai fazer a ordenacao
 *
 *  Retorna:
 *  Conteudo da posicao da particao
 *************************************************/

int partitionchar( char** _tabela, int l, int r)
{
	int i, j;
	char* pivot;
	pivot = _tabela[r]; i = l; j = r;

	while(1)
	{
		while (strcmp(_tabela[i], pivot) < 0)
		{
			i++;
		}

		while (strcmp(_tabela[--j], pivot ) > 0)
		{
			if (j == l) break;
		}

		if (i >= j) break;
		string_swap(_tabela, i, j);
	}
	string_swap(_tabela, i, r);
	return i;
}


/***********************************************
 *  Funcao:
 *      quicksortchar
 *
 *  Descricao:
 *    Algoritmo de quicksort para as palavras (Recursivo)
 *
 *  Argumentos:
 *    - Tabela de palavras
 *    - Dois inteiros (l,r) que vao designar os limites esquerdo (l) e
 *		direito (r) de onde se vai fazer a ordenacao
 *
 *  Retorna:
 *  Nada
 *************************************************/

void quicksortchar(char** _tabela, int l, int r)
{
 int i;

 if (r <= l) return;

 i = partitionchar(_tabela, l, r);
 quicksortchar(_tabela, l, i-1);
 quicksortchar(_tabela, i+1, r);
}

void tam_ex_swap(Prob** _VetorProb, int _i, int _j)
{
	Prob *temp=NULL;

	temp = _VetorProb[_i];
	_VetorProb[_i]= _VetorProb[_j];
	_VetorProb[_j]= temp;
}


/***********************************************
 *  Funcao:
 *      partitiontam
 *
 *  Descricao:
 *    Faz uma particao no vetor. E como que a primeira
 *		iteracao daquilo que sera a base do algoritmo de quicksort
 *
 *  Argumentos:
 *    - Vetor de problemas
 *    - Dois inteiros (l,r) que vao designar os limites esquerdo (l) e
 *		direito (r) de onde se vai fazer a ordenacao
 *
 *  Retorna:
 *  Conteudo da posicao da particao
 *************************************************/

int partitiontam(Prob** _VetorProb, int l, int r)
{
	int i, j;
	Prob* pivot;
	pivot = _VetorProb[r]; i = l; j = r;

	while(1)
	{
		while (Get_tam(_VetorProb[i])<Get_tam(pivot))
		{
			i++;
		}

		while (Get_tam(_VetorProb[--j])>Get_tam(pivot))
		{
			if (j == l) break;
		}

		if (i >= j) break;
		tam_ex_swap(_VetorProb, i, j);
	}
	tam_ex_swap(_VetorProb, i, r);
	return i;
}



/***********************************************
 *  Funcao:
 *      quicksorttam
 *
 *  Descricao:
 *    Algoritmo de quicksort para os tamanhos dos problemas (Recursivo)
 *
 *  Argumentos:
 *    - Vetor de problemas
 *    - Dois inteiros (l,r) que vao designar os limites esquerdo (l) e
 *		direito (r) de onde se vai fazer a ordenacao
 *
 *  Retorna:
 *  Nada
 *************************************************/

void quicksorttam(Prob** _VetorProb, int l, int r)
{
 int i;

 if (r <= l) return;

 i = partitiontam(_VetorProb, l, r);
 quicksorttam(_VetorProb, l, i-1);
 quicksorttam(_VetorProb, i+1, r);
}


/***********************************************
 *  Funcao:
 *      partitionnex
 *
 *  Descricao:
 *    Faz uma particao no vetor. E como que a primeira
 *		iteracao daquilo que sera a base do algoritmo de quicksort
 *
 *  Argumentos:
 *    - Vetor de problemas
 *    - Dois inteiros (l,r) que vao designar os limites esquerdo (l) e
 *		direito (r) de onde se vai fazer a ordenacao
 *
 *  Retorna:
 *  Conteudo da posicao da particao
 *************************************************/

int partitionex(Prob** _VetorProb, int l, int r)
{
	int i, j;
	Prob* pivot;
	pivot = _VetorProb[r]; i = l; j = r;

	while(1)
	{
		while (Get_nr_prob(_VetorProb[i])<Get_nr_prob(pivot))
		{
			i++;
		}

		while (Get_nr_prob(_VetorProb[--j])>Get_nr_prob(pivot))
		{
			if (j == l) break;
		}

		if (i >= j) break;
		tam_ex_swap(_VetorProb, i, j);
	}
	tam_ex_swap(_VetorProb, i, r);
	return i;
}


/***********************************************
 *  Funcao:
 *      quicksortex
 *
 *  Descricao:
 *    Algoritmo de quicksort para os numeros dos problemas pela
 *		ordem em que aparecem no ficheiro inicialmente (Recursivo)
 *
 *  Argumentos:
 *    - Vetor de problemas
 *    - Dois inteiros (l,r) que vao designar os limites esquerdo (l) e
 *		direito (r) de onde se vai fazer a ordenacao
 *
 *  Retorna:
 *  Nada
 *************************************************/

void quicksortex(Prob** _VetorProb, int l, int r)
{
 int i;

 if (r <= l) return;

 i = partitionex(_VetorProb, l, r);
 quicksortex(_VetorProb, l, i-1);
 quicksortex(_VetorProb, i+1, r);
}

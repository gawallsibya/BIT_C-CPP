#include <malloc.h>
#include <string.h>

#define ERROR			0
#define NOT				0
#define OK				1

typedef unsigned 		mtoken;
typedef struct _OPRAND	oprand;
typedef struct _OPTOR	optor;
typedef struct _MLEAF	mleaf;

enum _DES
{
	ENDTOK,
	RAND,
	TOR
};

enum _PRI
{
	ADD_SUB,
	MUL_DIV
};
enum _TOR
{
	ADD,
	SUB,
	MUL,
	DIV
};

struct _OPTOR
{
	unsigned des: 2;
	unsigned opch:2;
	unsigned oppr:2;
	unsigned res:26;
};

struct _OPRAND
{
	unsigned des: 2;
	unsigned val:30;
};

struct _MLEAF
{
	mtoken *tval;
	mleaf *left;
	mleaf *right;
};



int fnIsDigit(char i_c);
int fnIsTor(char i_c);
char *fnMakeRand(mtoken *i_t,char *i_pc);
char *fnMakeTor(mtoken *i_t,char *i_pc);
int fnLexical(mtoken *i_t,char *pIn);
int fnSyntax(mtoken *i_t);
mleaf *fnParse(mtoken *i_t);
int fnCal(mleaf *i_l);

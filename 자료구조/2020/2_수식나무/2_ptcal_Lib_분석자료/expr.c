#include "expr.h"

static mleaf *mroot;



//-----------------------------------------------------------------
// 함 수 명 : fnIsDigit
// 함수설명 : 매개변수로 들어온 문자의 숫자여부 확인
//-----------------------------------------------------------------
// 매개변수 : 문자( 숫자 판단 여부 문자 )
// 리 턴 값 : 숫자일 경우 OK(1), 아닐경우 NOT(0)
//-----------------------------------------------------------------

int fnIsDigit(char i_c)
{
	if((i_c>='0')&&(i_c<='9'))
	{
		return OK;
	}
	return NOT;
}



//-----------------------------------------------------------------
// 함 수 명 : fnIsTor
// 함수설명 : 매개변수로 들어온 문자의 연산자 여부 확인
//-----------------------------------------------------------------
// 매개변수 : 문자( 연산자  판단 여부 문자 )
// 리 턴 값 : 연산자일 경우 OK(1), 아닐경우 NOT(0)
//-----------------------------------------------------------------

int fnIsTor(char i_c)
{
	switch(i_c)
	{
	case '+': case '-': case '*': case '/':
		return OK;
	}
	return NOT;
}



//-----------------------------------------------------------------
// 함 수 명 : fnMakeRand
// 함수설명 : 피연산자를 매개변수로 받아서 구조체를 채워서 배열에 저장
//-----------------------------------------------------------------
// 매개변수 : mtoken *i_t ( 토큰별 분리해서 수식을 저장할 1차원 배열 ) 
//            char *i_pc  ( 수식이 저장되어 있는 1차원 배열 )
// 리 턴 값 : 매개변수로 들어온 1차원 배열을(i_pc) 자리수 증가시켜 리턴
//-----------------------------------------------------------------
// 부가설명 : 피연산자들을 배열에서(i_pc) 순차적으로 꺼내서 구조체에 저장
//-----------------------------------------------------------------

char *fnMakeRand(mtoken *i_t,char *i_pc)
{
	oprand *t;

	t		= (oprand *)i_t;
	t->des	= RAND;
	t->val	= 0;

	while(fnIsDigit(*i_pc))
	{
		t->val = t->val*10 + (*i_pc -'0');
		i_pc++;
	}	

//	t++;
	return i_pc;
}



//-----------------------------------------------------------------
// 함 수 명 : fnMakeTor
// 함수설명 : 연산자를 매개변수로 받아서 구조체를 채워서 배열에 저장 
//-----------------------------------------------------------------
// 매개변수 : mtoken *i_t ( 토큰별 분리해서 수식을 저장할 1차원 배열 ) 
//            char *i_pc  ( 수식이 저장되어 있는 1차원 배열 )
// 리 턴 값 : 매개변수로 들어온 1차원 배열을(i_pc) 자리수 증가시켜 리턴
//-----------------------------------------------------------------

char *fnMakeTor(mtoken *i_t,char *i_pc)
{
	optor *t;

	t = (optor *)i_t;		//  왜 할까??

	t->des = TOR;
	
	switch(*i_pc)
	{
	case '+':
		t->opch = ADD;
		t->oppr = ADD_SUB;
		break;
	case '-':
		t->opch = SUB;
		t->oppr = ADD_SUB;
		break;
	case '*':
		t->opch = MUL;
		t->oppr = MUL_DIV;
		break;
	case '/':
		t->opch = DIV;
		t->oppr = MUL_DIV;
		break;
	}

//	t++;
	i_pc++;
	return i_pc;
}



//-----------------------------------------------------------------
// 함 수 명 : fnLexical
// 함수설명 : 연산식을 연산자 피연산자로 분류하여 배열에 저장   
//-----------------------------------------------------------------
// 매개변수 : mtoken *i_t  ( 토큰별 분리해서 수식을 저장할 1차원 배열 )
//		      char   *pIn  ( 연산식이(중위) 저장되어 있는 배열의 첫번째 위치 )

// 리 턴 값 : 연산자 or 피연산자일 경우 OK(1)
//            위의 내용이 아닐경우  ERROR(0)을 리턴
//-----------------------------------------------------------------
int fnLexical(mtoken *i_t,char *pIn)
{
	while(*pIn)
	{
		if(fnIsDigit(*pIn))
		{
			pIn = fnMakeRand(i_t,pIn);
			i_t++;
		}
		else if(fnIsTor(*pIn))
		{
			pIn = fnMakeTor(i_t,pIn);
			i_t++;
		}
		else
		{
			((unsigned)i_t) = ENDTOK;
			return ERROR;
		}
	}
	return OK;
}



//-----------------------------------------------------------------
// 함 수 명 : fnSyntax
// 함수설명 : 연산식이 정상적인 수식인지 확인 
//-----------------------------------------------------------------
// 매개변수 : mtoken *i_t  ( 토큰별 분리해서 저장되어 있는 수식)
// 리 턴 값 : 정상적 수식일 경우 OK(1), 아닐경우 ERROR(0)
//-----------------------------------------------------------------

int fnSyntax(mtoken *i_t)
{
	optor *t;
	t = (optor *)i_t;
	
	if(t->des==RAND)
	{
		t++;
		while(t->des)
		{
			if((t->des == TOR)&&((t+1)->des == RAND))
			{
				t = t+2;
			}
			else
			{
				return ERROR;
			}
			
		}
		return OK;
	}
	return ERROR;
}



mleaf *fnLalloc(mtoken *i_t)
{
	mleaf *t;
	t = (mleaf *)malloc(sizeof(mleaf));
	memset(t,0,sizeof(mleaf));
	t->tval = i_t;
	return t;
}

fnHangL(mleaf *now)
{
	now->left = mroot;
	mroot = now;
}
fnHangR(mleaf *now)
{
	now->left = mroot->right;
	mroot->right = now;
}

fnHangRand(mleaf *i_n)
{
	mleaf *sr;
	sr = mroot;
	while(sr->right)
	{
		sr = sr->right;
	}
	sr->right = i_n;
}





mleaf *fnParse(mtoken *i_t)
{
	optor *tt,*ts;
	mleaf  *now;
	
	mroot = fnLalloc(i_t);
	
	i_t++;
	ts = (optor *)i_t;

	while(ts->des)
	{
		tt = (optor *)mroot->tval;
		now = fnLalloc(i_t);
		if((tt->des == RAND)||(ts->oppr <= tt->oppr))
		{
			fnHangL(now);
		}
		else
		{
			fnHangR(now);
		}

		i_t++;
		now = fnLalloc(i_t);
		fnHangRand(now);
		i_t++;
		ts = (optor *)i_t;
	}
	return mroot;
}



int fnCal(mleaf *i_l)
{
	int rval;
	int lval;
	int re;

	if(((oprand *)(i_l->tval))->des==RAND)
	{
		re =  ((oprand *)(i_l->tval))->val;
		free(i_l);
		return re;
	}

	if(i_l->left)
	{
		lval = fnCal(i_l->left);
	}
	if(i_l->right)
	{
		rval = fnCal(i_l->right);
	}

	switch(((optor *)(i_l->tval))->opch)
	{
		free(i_l->left);
		free(i_l->right);
	case ADD:
		return lval + rval;
	case SUB:
		return lval - rval;
	case MUL:
		return lval * rval;
	case DIV:
		if(rval ==0)
		{
			return 0;
		}
		return  lval / rval;
	}

	return 0;
}
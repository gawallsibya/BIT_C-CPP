#include "expr.h"

static mleaf *mroot;



//-----------------------------------------------------------------
// �� �� �� : fnIsDigit
// �Լ����� : �Ű������� ���� ������ ���ڿ��� Ȯ��
//-----------------------------------------------------------------
// �Ű����� : ����( ���� �Ǵ� ���� ���� )
// �� �� �� : ������ ��� OK(1), �ƴҰ�� NOT(0)
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
// �� �� �� : fnIsTor
// �Լ����� : �Ű������� ���� ������ ������ ���� Ȯ��
//-----------------------------------------------------------------
// �Ű����� : ����( ������  �Ǵ� ���� ���� )
// �� �� �� : �������� ��� OK(1), �ƴҰ�� NOT(0)
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
// �� �� �� : fnMakeRand
// �Լ����� : �ǿ����ڸ� �Ű������� �޾Ƽ� ����ü�� ä���� �迭�� ����
//-----------------------------------------------------------------
// �Ű����� : mtoken *i_t ( ��ū�� �и��ؼ� ������ ������ 1���� �迭 ) 
//            char *i_pc  ( ������ ����Ǿ� �ִ� 1���� �迭 )
// �� �� �� : �Ű������� ���� 1���� �迭��(i_pc) �ڸ��� �������� ����
//-----------------------------------------------------------------
// �ΰ����� : �ǿ����ڵ��� �迭����(i_pc) ���������� ������ ����ü�� ����
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
// �� �� �� : fnMakeTor
// �Լ����� : �����ڸ� �Ű������� �޾Ƽ� ����ü�� ä���� �迭�� ���� 
//-----------------------------------------------------------------
// �Ű����� : mtoken *i_t ( ��ū�� �и��ؼ� ������ ������ 1���� �迭 ) 
//            char *i_pc  ( ������ ����Ǿ� �ִ� 1���� �迭 )
// �� �� �� : �Ű������� ���� 1���� �迭��(i_pc) �ڸ��� �������� ����
//-----------------------------------------------------------------

char *fnMakeTor(mtoken *i_t,char *i_pc)
{
	optor *t;

	t = (optor *)i_t;		//  �� �ұ�??

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
// �� �� �� : fnLexical
// �Լ����� : ������� ������ �ǿ����ڷ� �з��Ͽ� �迭�� ����   
//-----------------------------------------------------------------
// �Ű����� : mtoken *i_t  ( ��ū�� �и��ؼ� ������ ������ 1���� �迭 )
//		      char   *pIn  ( �������(����) ����Ǿ� �ִ� �迭�� ù��° ��ġ )

// �� �� �� : ������ or �ǿ������� ��� OK(1)
//            ���� ������ �ƴҰ��  ERROR(0)�� ����
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
// �� �� �� : fnSyntax
// �Լ����� : ������� �������� �������� Ȯ�� 
//-----------------------------------------------------------------
// �Ű����� : mtoken *i_t  ( ��ū�� �и��ؼ� ����Ǿ� �ִ� ����)
// �� �� �� : ������ ������ ��� OK(1), �ƴҰ�� ERROR(0)
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
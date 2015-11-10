#include "total.h"

//-----------------------------------------------------------
// [ data ]
//-----------------------------------------------------------

char str[10][100]	=	{	

		"12+45"			    , "12-3+",
		"1-2*4"				, "12*4+-2",
		"123*45-23/4*45-6"	, "1-2-4*4/2-2/2",
		"2*5$34"			, "23-2*1-2/3",
		"12-3*45/-4"		, "12-3-4/2"

		};


mtoken texpr[100];			// 문자열을 unsigned로 분리해서 배열에 저장

//int t_ind=0;				// 저장 개수 

//---------------------------------------------------------------------------


fnSim(int i)
{
	int re = 0;
	if(fnLexical(texpr,str[i]))
	{
		if(fnSyntax(texpr))
		{
			re = fnCal(fnParse(texpr));
			printf("%s = [%d]\n",str[i],re);
		}
		else
		{
			printf("%s is Syntax Error\n",str[i]);
		}
	}
	else
	{
		printf("%s is Lexical Error\n",str[i]);
	}
	getchar();
	memset(texpr,0,sizeof(mtoken)*100);
}


main()
{
	int i=0;
	while(i<10)
	{
		fnSim(i);
		i++;
	}
}
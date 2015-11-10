#include <stdio.h>
#include <string.h>
#define DATA_MAX	5

void foo( char (*pname)[20], const char* str);
void woo( char* pname,        const char* str);
void goo( char (*pname)[20], const char* str);
void hoo( char* pname,        const char* str);
void ooo(char* pname,        const char* str);
int NameToIdx(char (*pname)[20], const char* str);
void PrintData1( char (*pname)[20], int idx);
void PrintData2( char (*pname)[20]);
void PrintData3( char *pname);
void main()
{
	char names[DATA_MAX][20];
	int i;
	foo(names, "홍길동");			// names[1] 에 저장,
	woo(names[1], "김길동");		// names[0] 에 저장
	goo(names+2, "고길동");			// names[3] 에 저장
	hoo(&names[4][0], "최길동");	// names[2] 에 저장
	ooo(*(names+2), "강길동");		// names[4] 에 저장

	{
		int idx = NameToIdx(names, "고길동");		//3,  -1
		if( idx != -1 )
		{
			PrintData1(names, idx);
			PrintData2(names+idx);
			PrintData3(names[idx]);
		}
	}


	for(i=0; i<DATA_MAX; i++)
	{
		printf("[%d] %s\n", i, names[i]);
	}
}
void PrintData1( char (*pname)[20], int idx)
{
	printf("검색명1 : %s\n", pname[idx]);
}
void PrintData2( char (*pname)[20])
{
	printf("검색명2 : %s\n", pname[0]);
}
void PrintData3( char *pname)
{
	printf("검색명3 : %s\n", pname);
}
int NameToIdx(char (*pname)[20], const char* str)
{
	int i;
	for(i=0; i< DATA_MAX; i++)
	{
		if( !strcmp( pname[i], str))
			return i;
	}
	return -1;
}


void ooo(char* pname,        const char* str)
{
	strcpy(pname+40, str);
}

void hoo( char* pname,        const char* str)
{
	strcpy(pname-40, str);
}
void goo( char (*pname)[20], const char* str)
{
	strcpy(pname[1],str);
}

void woo( char* pname,        const char* str)
{
	strcpy(pname-20, str);
}

void foo( char (*pname)[20], const char* str)
{
	strcpy(pname[1], str);
}

/*
void InsertName( char* pname);
void PrintName( const char* pname);
void main()
{
	char name[20];

	InsertName(name);	// 이름을 입력 받는 함수

	PrintName(name);	// 입력받은 이름을 출력하는 함수
}

void InsertName( char* pname)
{
	printf("이름 : ");		gets(pname);
}

void PrintName( const char* pname)
{
	printf("저장 : %s\n", pname);
}
*/

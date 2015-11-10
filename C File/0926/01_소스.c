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
	foo(names, "ȫ�浿");			// names[1] �� ����,
	woo(names[1], "��浿");		// names[0] �� ����
	goo(names+2, "��浿");			// names[3] �� ����
	hoo(&names[4][0], "�ֱ浿");	// names[2] �� ����
	ooo(*(names+2), "���浿");		// names[4] �� ����

	{
		int idx = NameToIdx(names, "��浿");		//3,  -1
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
	printf("�˻���1 : %s\n", pname[idx]);
}
void PrintData2( char (*pname)[20])
{
	printf("�˻���2 : %s\n", pname[0]);
}
void PrintData3( char *pname)
{
	printf("�˻���3 : %s\n", pname);
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

	InsertName(name);	// �̸��� �Է� �޴� �Լ�

	PrintName(name);	// �Է¹��� �̸��� ����ϴ� �Լ�
}

void InsertName( char* pname)
{
	printf("�̸� : ");		gets(pname);
}

void PrintName( const char* pname)
{
	printf("���� : %s\n", pname);
}
*/

//21
#include <stdio.h>
// �Լ������Ͷ�?
// �Լ������� ���� ����
// �Լ������͸� �����ϴ� �迭
// �Լ��� typedef
// �Լ��� ���� 

/*
typedef int INT;
typedef unsigned int UINT;

int foo(int num)	{	}

typedef int(*FUNC)(int);	// FUNC Ÿ��

void main()
{
	int (*Func)(int)	= foo;		// Func ����

	FUNC  func			= foo;
}
*/


//  �Լ��� �����ϴ� �Լ�??
typedef void (*FUNC)(int,int);	// FUNC Ÿ��
void foo(int n1,int n2)
{
	printf("FOO :%d:%d\n", n1, n2);
}

FUNC add()
{
	return foo;
}
void main()
{
	add()(10,20);		//add() => foo(10,20)
}


/*
int add(int num1, int num2)		{return num1 + num2;}
int sub(int num1, int num2)		{return num1 - num2;}
int mul(int num1, int num2)		{return num1 * num2;}
int div(int num1, int num2)		{return num1 / num2;}

void main()
{
	int (*Func[4])(int, int) = {add, sub, mul, div};

	int n1 = 10, n2 = 20;
	int op;
	printf("������ :(0:+,1:-, 2:*, 3:/)) ");		scanf("%d", &op);
	
	printf("%d\n", Func[op](n1, n2));

	switch(op)
	{
	case 1: printf("%d\n", add(n1, n2));		break;
	case 2: printf("%d\n", sub(n1, n2));		break;
	case 3: printf("%d\n", mul(n1, n2));		break;
	case 4: printf("%d\n", div(n1, n2));		break;
	}
}
*/

/*
int hoo(int n1)
{
	printf("HOO : %d\n", n1);
	return n1;
}
void goo(int n1, int n2)
{
	printf("GOO : %d : %d\n", n1, n2);
}
// �Լ��� ���ڷ� ���� 
void woo( void (*Func)(int,int), int(*Func1)(int), int num)
{
	Func(num, num);		// goo(num, num)
	Func1(num);			// hoo(num)
}

void foo(int);

void main()
{
	woo( goo, hoo, 10);


//	void(*Func)(int) = foo;	//Func ���� 
//	Func	= foo;

//	Func(10);		// foo(10);
}

void foo(int num)
{
	printf("FOO : %d\n", num);
}
*/

// �̸��� �ּҰ� : �迭, �Լ�
/*
void foo();

void main()
{
	printf("%d\n", main);		// 4198405
	printf("%d\n", foo);		// 4198410
}

void foo()
{
}
*/

/*
void main()
{
	int *p;		// ������ 
	int *p1 = 0;
	int *p2 = NULL;		//#define NULL    ((void *)0)
}
*/

/*
#define DATA_MAX	5

void num_insertall( int * pnum, int size);
void num_printall( const int * pnum, int size);

void main()
{
	int num[DATA_MAX];		// int num[5];
	num_insertall( num, DATA_MAX );	// 1,2,3,4,5	num_insertall( num, 5 );
	num_printall( num, DATA_MAX );
}

void num_printall( const int * pnum, int size)
{
	int i;
	for(i=0; i<size; i++)
	{
		printf("num[%d] = %d\n", i, pnum[i]);
	}
}

void num_insertall( int * pnum, int size )
{
	int i;
	for(i=0; i<size; i++)
	{
		pnum[i] = i+1;
	}
}
*/
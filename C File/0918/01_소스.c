#include <stdio.h>

#include <stdio.h>

int InputNum();
int SelectMenu();
int Operation(int num1, int sel, int num2);
void ResultPrint(int n1, char s, int n2, int sum);

char IdxToOper( int idx );


int main(void)
{
	int sel, num1, num2, sum;
	
	num1	= InputNum();
	num2	= InputNum();
	sel		= SelectMenu();
	sum		= Operation(num1, sel, num2);
	ResultPrint(num1, IdxToOper(sel), num2, sum);
}

int InputNum()
{
	int num;
	printf("���� �Է� : ");		scanf("%d", &num);
	return num;
}

int SelectMenu()
{
	int sel;
	printf("--- �޴� ���� ---\n");
	printf(" 1.����, 2.����, 3.����, 4.������ : ");
	scanf("%d", &sel);
	return sel;
}

int Operation(int num1, int sel, int num2)
{
	int sum;
	switch(sel)
	{
	case 1:	sum = num1 + num2;	break;
	case 2:	sum = num1 - num2;	break;
	case 3:	sum = num1 * num2;	break;
	case 4:	sum = num1 / num2;	break;
	}
	return sum;
}

void ResultPrint(int n1, char s, int n2, int sum)
{
	printf("���� ��� : %d %c %d = %d\n", n1, s, n2, sum);
}

char IdxToOper( int idx )
{
	char op;
	switch(idx)
	{
	case 1:		op	= '+';		break;
	case 2:		op  = '-';		break;
	case 3:		op  = '*';		break;
	case 4:		op  = '/';		break;
	}

	return op;
}


/*
int foo(int num, char ch);

void main()
{
	int num = 10;
	char ch = 'a';
	int result;
	result = foo( num,  ch );	// �Լ��� ȣ��
}

int foo(int num, char ch)
{	
	return 0;
}
*/

/*
void foo();

void main()
{
	int num;
//	num	=	 foo();		//  L-value = R-value	int = void
	foo();
}

void foo()		// �Ű����� : void, ���ϰ� : void 
{
	return 0;	// error..
}
*/
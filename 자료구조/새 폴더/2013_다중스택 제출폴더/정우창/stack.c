#include "std.h"

Stack stak;

void stack_init()
{
	stak.start = -1;
	stak.end = MAX;
}

void stack1_push()
{
	int data;

	stack1_now();

	printf("���ڸ� �Է��Ͻÿ� : ");		scanf("%d", &data);

	if(stak.start+1 != stak.end)
	{
		stak.arr[++stak.start] = data;
	}
	else
	{
		printf("OVERFLOW : ��������� �����ϴ�.\n");
	}

	start_printall();
}

void stack1_pop()
{
	if(stak.start < 0)
	{
		printf("UNDERFLOW : �����Ͱ� �������� �ʽ��ϴ�.\n");
	}
	else
	{
		printf("%d�� �����Խ��ϴ�.\n", stak.arr[stak.start]);
		stak.arr[stak.start] = 0;
		stak.start--;
	}

	start_printall();
}

void stack2_push()
{
	int data;

	stack2_now();

	printf("���ڸ� �Է��Ͻÿ� : ");		scanf("%d", &data);

	if(stak.end+1 != stak.start)
	{
		stak.arr[--stak.end] = data;
	}
	else
	{
		printf("OVERFLOW : ��������� �����ϴ�.\n");
	}

	end_printall();
}

void stack2_pop()
{
	if(stak.end >= MAX)
	{
		printf("UNDERFLOW : �����Ͱ� �������� �ʽ��ϴ�.\n");
	}
	else
	{
		printf("%d�� �����Խ��ϴ�.\n", stak.arr[stak.end]);
		stak.arr[stak.end] = 0;
		stak.end++;
	}

	end_printall();
}

void start_printall()
{
	int i;

	for(i = MAX-1; i>-1; i--)
	{
		printf("%d\t",stak.arr[i]);
	}
	printf("\n");
}

void end_printall()
{
	int i;

	for(i = 0; i<MAX; i++)
	{
		printf("%d\t",stak.arr[i]);
	}
	printf("\n");
}

void stack1_now()
{
	if(stak.start+1 == stak.end)
	{
		printf("Now Stack Is Full\n");
	}
	else if(stak.start == -1)
	{
		printf("Now Stack Is Empty\n");
	}
}

void stack2_now()
{
	if(stak.end-1 == stak.start)
	{
		printf("Now Stack Is Full\n");
	}
	else if(stak.end == MAX)
	{
		printf("Now Stack Is Empty\n");
	}
}

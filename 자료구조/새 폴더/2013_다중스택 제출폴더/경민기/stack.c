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

	printf("숫자 입력 : ");		scanf("%d", &data);

	if(stak.start+1 != stak.end)
	{
		stak.arr[++stak.start] = data;
	}
	else
	{
		printf("overflow : 저장공간이 없습니다.\n");
	}

	start_printall();
}

void stack1_pop()
{
	if(stak.start < 0)
	{
		printf("underflow : 데이터가 존재하지 않습니다.\n");
	}
	else
	{
		printf("%d를 빼내왔습니다.\n", stak.arr[stak.start]);
		stak.arr[stak.start] = 0;
		stak.start--;
	}

	start_printall();
}

void stack2_push()
{
	int data;

	stack2_now();

	printf("숫자 입력 : ");		scanf("%d", &data);

	if(stak.end+1 != stak.start)
	{
		stak.arr[--stak.end] = data;
	}
	else
	{
		printf("overflow : 저장공간이 없습니다.\n");
	}

	end_printall();
}

void stack2_pop()
{
	if(stak.end >= MAX)
	{
		printf("underflow : 데이터가 존재하지 않습니다.\n");
	}
	else
	{
		printf("%d를 빼내왔습니다.\n", stak.arr[stak.end]);
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
		printf("꽉찼습니다....\n");
	}
	else if(stak.start == -1)
	{
		printf("비어있습니다...\n");
	}
}

void stack2_now()
{
	if(stak.end-1 == stak.start)
	{
		printf("꽉찼습니다....\n");
	}
	else if(stak.end == MAX)
	{
		printf("비어있습니다...\n");
	}
}

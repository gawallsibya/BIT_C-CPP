//manager.c
#include "manager.h"
#include "stack.h"
#include "std.h"
STACK stack;

void manager_init()
{
	stack.top1 = -1;
	stack.top2 = MAX;
}

void manager_push_front_insert()
{
	int data;
	++stack.top1;
	printf("숫자를 입력하시오 : ");		scanf("%d", &data);

	if(stack.top1 != stack.top2)
	{
		stack.data[stack.top1] = data;
	}
	else
	{
		printf("OVERFLOW : 저장공간이 없습니다.\n");
	}
}

void manager_push_front_push_pop()
{
	if(stack.top1 < 0)
	{
		printf("UNDERFLOW : 데이터가 존재하지 않습니다.\n");
	}
	else
	{
		printf("%d를 빼내왔습니다.\n", stack.data[stack.top1]);
		stack.data[stack.top1] = 0;
		stack.top1--;
	}
}

void manager_push_front_printall()
{
	int i;
	for(i = 0; i<=stack.top1; i++)
	{
		printf("%d\n",stack.data[i]);
	}
	printf("\n");
}

void manager_push_back_insert()
{
	int data;
	--stack.top2;
	printf("숫자를 입력하시오 : ");		scanf("%d", &data);

	if(stack.top1 != stack.top2)
	{
		stack.data[stack.top2] = data;
	}
	else
	{
		printf("OVERFLOW : 저장공간이 없습니다.\n");
	}
}

void manager_push_back_push_pop()
{
	if(stack.top2 > 9)
	{
		printf("UNDERFLOW : 데이터가 존재하지 않습니다.\n");
	}
	else
	{
		printf("%d를 빼내왔습니다.\n", stack.data[stack.top2]);
		stack.data[stack.top2] = 0;
		stack.top2--;
	}
}

void manager_push_back_printall()
{
	int i;
	for(i = MAX-1; i>=stack.top2; i--)
	{
		printf("%d\n",stack.data[i]);
	}
	printf("\n");
}

void manager_printall()
{
	int i;
	for(i = 0; i<MAX; i++)
	{
		printf("%d\n",stack.data[i]);
	}
	printf("\n");
}

void stack_top1_now()
{
	if(stack.top1+1 == stack.top2)
	{
		printf("Now Stack Is Full\n");
	}
	else if(stack.top1 == -1)
	{
		printf("Now Stack Is Empty\n");
	}
}

void stack_top2_now()
{
	if(stack.top1+1 == stack.top2)
	{
		printf("Now Stack Is Full\n");
	}
	else if(stack.top2 == MAX)
	{
		printf("Now Stack Is Empty\n");
	}
}
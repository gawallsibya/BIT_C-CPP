#include <stdio.h>
#include "sta.h"
/*
DATA front;
DATA back;

void stack_init()
{
	front.top = -1;
	back.top = MAX;
}

void front_push()
{
	int data;
	printf("��ġ�� �Է��ϼ��� : ");  scanf("%d",&data);
	if(front.top +1 == back.top)
	{
		printf("Overflow.....\n");
		return;
	}
	front.sta[++front.top] = data;
}

void back_push()
{
	int data;
	printf("��ġ�� �Է��ϼ��� : ");  scanf("%d",&data);
	if(front.top +1 == back.top)
	{
		printf("Overflow.....\n");
		return;
	}
	back.sta[--back.top] = data;	
}

void front_pop()
{
	if(front.top < 0)
	{
		printf("Underflow.....\n");
		return;
	}
	printf("%d ��° ����Ÿ : %d\n",front.top+1,front.sta[front.top]);
	front.top--;
}

void back_pop()
{
	if(back.top >= MAX)
	{
		printf("Underflow.....\n");
		return;
	}
	printf("%d ��° ����Ÿ : %d\n",back.top+1,back.sta[back.top]);
	back.top++;	
}
*/



//�ϳ��� �޸𸮷� �����ؼ�?....

DATA mul;

void stack_init()
{
	mul.front = -1;
	mul.back = MAX;
}

void front_push()
{
	int data;
	printf("��ġ�� �Է��ϼ��� : ");  scanf("%d",&data);
	if(mul.front +1 == mul.back)
	{
		printf("Overflow.....\n");
		return;
	}
	mul.sta[++mul.front] = data;
}

void back_push()
{
	int data;
	printf("��ġ�� �Է��ϼ��� : ");  scanf("%d",&data);
	if(mul.front +1 == mul.back)
	{
		printf("Overflow.....\n");
		return;
	}
	mul.sta[--mul.back] = data;	
}

void front_pop()
{
	if(mul.front < 0)
	{
		printf("Underflow.....\n");
		return;
	}
	printf("%d ��° ����Ÿ : %d\n",mul.front+1,mul.sta[mul.front]);
	mul.front--;
}

void back_pop()
{
	if(mul.back >= MAX)
	{
		printf("Underflow.....\n");
		return;
	}
	printf("%d ��° ����Ÿ : %d\n",mul.back+1,mul.sta[mul.back]);
	mul.back++;	
}



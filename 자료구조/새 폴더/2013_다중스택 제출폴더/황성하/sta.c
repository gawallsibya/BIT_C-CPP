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
	printf("수치를 입력하세요 : ");  scanf("%d",&data);
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
	printf("수치를 입력하세요 : ");  scanf("%d",&data);
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
	printf("%d 번째 데이타 : %d\n",front.top+1,front.sta[front.top]);
	front.top--;
}

void back_pop()
{
	if(back.top >= MAX)
	{
		printf("Underflow.....\n");
		return;
	}
	printf("%d 번째 데이타 : %d\n",back.top+1,back.sta[back.top]);
	back.top++;	
}
*/



//하나의 메모리로 생성해서?....

DATA mul;

void stack_init()
{
	mul.front = -1;
	mul.back = MAX;
}

void front_push()
{
	int data;
	printf("수치를 입력하세요 : ");  scanf("%d",&data);
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
	printf("수치를 입력하세요 : ");  scanf("%d",&data);
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
	printf("%d 번째 데이타 : %d\n",mul.front+1,mul.sta[mul.front]);
	mul.front--;
}

void back_pop()
{
	if(mul.back >= MAX)
	{
		printf("Underflow.....\n");
		return;
	}
	printf("%d 번째 데이타 : %d\n",mul.back+1,mul.sta[mul.back]);
	mul.back++;	
}



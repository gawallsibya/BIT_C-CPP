#include "stack.h"
#include "std.h"

void stack_init(Stack* a)
{
	a->top1=-1;
	a->top2=MAX;
}
void Upstack_push_front(Stack* a,int num)
{
	if(a->top1+1 == a->top2)
	{
		printf("Overflow..\n");
		return;
	}
	else
		a->arr[++a->top1]=num;
}

int Upstack_pop_front(Stack* a)
{
	if(a->top1 < 0)
	{
		printf("Unerflow..\n");
		return -1;
	}
	//printf("%d\n",a->arr[a->top1--]);
	return a->arr[a->top1--];
}
void Downstack_push_front(Stack* a,int num)
{
	if(a->top1+1 == a->top2)
	{
		printf("Overflow..\n");
		return;
	}
	a->arr[--a->top2]=num;
	return;
}
int Downstack_pop_front(Stack* a)
{
	if(a->top2 >= MAX)
	{
		printf("Unerflow..\n");
		return -1;
	}
	//printf("%d\n",a->arr[a->top2++]);
	return a->arr[a->top2++];
}

void stack_state(Stack* a)
{
	if(a->top1+1 == a->top2)
	{
		printf("Now Stack Is Full\n");
	}
	else if(a->top1==-1)
	{
		printf("Now Stack Is Empty\n");
	}
	else if(a->top2==MAX)
	{
		printf("Now Stack Is Empty\n");
	}
}
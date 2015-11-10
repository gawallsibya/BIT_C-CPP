#include "std.h"
#include "stack.h"



void stack_init(DATA *s)
{
	s->top1 = -1;
	s->top2 = MAX;
}

void stack_push_up(DATA *s, int ar)
{
	//1. IsOverflow
	//1.1
	//1.2
	if(s->top1+1 != s->top2)
	{
//		s->top1++;
		s->arr[++s->top1] = ar;
		
	}
	else
	{
		printf("Overflow\n");
	}
}

void stack_push_down(DATA *s, int ar)
{
	if(s->top1+1 != s->top2)
	{
		s->arr[s->top2-1] = ar;
		s->top2--;
	}
	else
	{
		printf("Overflow\n");
	}
}

int stack_pop_up(DATA *s)
{
	if(s->top1 > -1)
	{
		s->top1--;
		return 1;
	}
	else
	{
		printf("Underflow\n");
		return 0;
	}
}

int stack_pop_down(DATA *s)
{
	if(s->top2 < MAX)
	{
		s->top2++;
		return 1;
	}
	else
	{
		printf("Underflow\n");
		return 0;
	}
}


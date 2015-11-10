#include "stack.h"


void init_stack(STACK *stack)
{
	stack->stack[MAX]=0;
	stack->top = -1;
	stack->Max = MAX-1;
	stack->Under = 0;
}
void frontpush_stack(STACK *stack, int num)
{

	if(stack->top>= MAX-1)
	{
		printf("Stack overflow.\n");
		return;
	}
	else
	{
		stack->stack[stack->Under] = num;
		stack->Under++;
		stack->top++;
	}
}
void toppush_stack(STACK *stack, int num)
{
	if(stack->top>= MAX-1)
	{
		printf("Stack overflow.\n");
		return;
	}
	else
	{
		stack->stack[stack->Max] = num;
		stack->Max--;
		stack->top++;
	}
}

void toppop_stack(STACK *stack)
{
	
	if(stack->top < 0)
	{
		printf("Stack underflow.\n");
		return;
	}
	else
	{

		stack->stack[stack->Max+1] = NULL;
		stack->Max++;
		stack->top--;
	}
}
void frontpop_stack(STACK *stack)
{
	if(stack->top < 0)
	{
		printf("Stack underflow.\n");
		return;
	}
	else
	{

		stack->stack[stack->Under-1] = NULL;
		stack->Under--;
		stack->top--;

	}
}
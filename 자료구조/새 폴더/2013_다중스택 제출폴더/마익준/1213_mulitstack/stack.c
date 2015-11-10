#include "std.h"
#include "stack.h"

void Stack_Init(Stack *s)
{
	s->top1 = -1;//林狼
	s->top2 = MAX;
}
void push_stack1(Stack *stack,int ch)
{
	if (stack->top1+1 != stack->top2)//林狼
	{
		stack->arr[stack->top1+1] = ch;//林狼
		stack->top1++;
	}
	else printf("stack overflow\n");
}
void pop_stack1(Stack* s)
{
	int i = s->top1;
	for (;i>-1;i--)
	{
		printf("%d\t",s->arr[i]);
	}
}
void push_stack2(Stack *stack,int ch)
{
	if (stack->top1+1 != stack->top2)//林狼
	{
		stack->arr[stack->top2-1] = ch;//林狼
		stack->top2--;
	}
	else printf("stack overflow\n");
}
void pop_stack2(Stack* s)
{
	int i = s->top2;
	for (;i<MAX;i++)
	{
		printf("%d\t",s->arr[i]);
	}
}
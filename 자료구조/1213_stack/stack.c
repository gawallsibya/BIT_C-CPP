#include "std.h"
#include "stack.h"

void Stack_Init(Stack *s)
{
	s->count = -1;//����
}
void push(Stack *stack,int ch)
{
	if (stack->count < MAX-1)//����
	{
		stack->arr[stack->count+1] = ch;//����
		stack->count++;
	}
	else printf("stack overflow\n");
}
void pop(Stack* s)
{
	int i = s->count;
	for (;i>-1;i--)
	{
		printf("%d\t",s->arr[i]);
	}
}
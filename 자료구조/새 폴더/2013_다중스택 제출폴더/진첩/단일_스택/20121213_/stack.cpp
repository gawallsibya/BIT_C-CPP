#include"std.h"
void init_stack(stack *Stack)
{
	Stack->top=-1;
}
int push(stack *Stack,int i)
{
	if(Stack->top>=MAX-1)
	{
		printf("stack overflow.\n");
			return -1;
	}
	Stack->arr[++Stack->top]=i;
	return i;
}
void print_stack(stack *Stack)
{
	int i;
	printf("\nStack content:Top----->Bottom\n");
	if(Stack->top==-1)
	printf("[stack empty]");
	for(i=Stack->top;i>=0;i--)
	{
		printf("%4d",Stack->arr[i]);
	}
	printf("\n");
}
int pop(stack *Stack)
{
	if(Stack->top<0)
	{
		printf("stack underflow.\n");
		return -1;
	}
	return Stack->arr[Stack->top--];
}
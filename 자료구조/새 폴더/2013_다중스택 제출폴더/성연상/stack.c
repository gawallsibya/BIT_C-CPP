#include "std.h"
#include "stack.h"
void Stack_Init(Stack *stack)//ÃÊ±âÈ­
{
	stack->count = -1;
	stack->count1 = MAX;//5
}
//=====================================================================
//count
void Push(Stack *stack,int ch)
{

	scanf("%d",&ch);
	if(stack->count+1 != stack->count1)//not overflow
	{
		stack->arr[stack->count+1] = ch;
		stack->count++;
	}
	else printf("overflow");
}
void Pop(Stack *stack)//
{
	int i =	stack->count;
	for(;i>-1;i--)
	{
		printf("%d",stack->arr[i]);
	}
}

//=====================================================================
//count1
void Push1(Stack *stack,int ch)
{

	scanf("%d",&ch);
	if(stack->count1+1 != stack->count)//not overflow
	{
		stack->arr[stack->count1-1] = ch;
		stack->count1--;
	}
	else printf("overflow");
}
void Pop1(Stack *stack)//
{
	int i =	stack->count1;
	for(;i<MAX;i++)
	{
		printf("%d",stack->arr[i]);
	}
}
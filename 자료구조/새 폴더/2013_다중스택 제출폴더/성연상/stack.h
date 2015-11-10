#ifndef _STACK_H_
#define _STACK_H_
#define MAX 5
typedef struct Stack Stack;
struct Stack
{
	int arr[MAX];
	int count;//top
	int count1;//top1
};
void Stack_Init(Stack *stack);
void Push(Stack *stack,int ch);
void Push1(Stack *stack,int ch);
void Pop(Stack *stack);
void Pop1(Stack *stack);
#endif
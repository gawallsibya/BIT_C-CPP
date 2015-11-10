#ifndef _STACK_H_
#define _STACK_H_
#define MAX 5
typedef struct STACK stack;
struct STACK 
{
	int arr[MAX];
	int top;
};
void init_stack(stack *Stack);
int push(stack *Stack,int i);
void print_stack(stack *Stack);
int pop(stack *Stack);
#endif
//stack.h
#ifndef _STACK_H_
#define _STACK_H_
#define MAX 10
typedef struct Stack Stack; //¡÷¿« 
struct Stack
{
	int arr[MAX];
	int top1;
	int top2;
};
void Stack_Init(Stack *s);
void push_stack1(Stack *,int);
void pop_stack1(Stack*);
void push_stack2(Stack *,int);
void pop_stack2(Stack*);
#endif /*_STACK_H_*/
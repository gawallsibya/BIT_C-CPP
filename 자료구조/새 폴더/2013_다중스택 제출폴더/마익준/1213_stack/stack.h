//stack.h
#ifndef _STACK_H_
#define _STACK_H_
#define MAX 5
typedef struct Stack Stack; //¡÷¿« 
struct Stack
{
	int arr[MAX];
	int count;
};
void Stack_Init(Stack *s);
void push(Stack *,int);
void pop(Stack*);
#endif /*_STACK_H_*/
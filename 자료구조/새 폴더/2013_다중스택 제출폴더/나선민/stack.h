#ifndef _STACK_H_
#define _STACK_H_
#include "std.h"

typedef struct tagSTACK STACK;
struct tagSTACK
{
	int stack[MAX];
	int top;
	int Max;
	int Under;
};

void init_stack(STACK *stack);
void frontpush_stack(STACK *stack, int num);
void toppush_stack(STACK *stack, int num);
void toppop_stack(STACK *stack);
void frontpop_stack(STACK *stack);

#endif /*_STACK_H_*/
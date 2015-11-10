#include "std.h"
#ifndef _STACK_H_
#define _STACK_H_
#define MAX 5

typedef struct Stack stack;
struct Stack
{
	int stack[MAX];
	int count;
	int a_count;
};

void init();
void a_push();
void a_pop();
void b_push();
void b_pop();
void printall();

#endif /*_STACK_H_*/
#include "std.h"
#include "stack.h"

int main()

{
	int i;
	Stack stack;
	Stack_Init(&stack);
	/*
	for (i = 1; i < MAX+1; i++)
	{
		push_stack1(&stack,i);
	}
	pop_stack1(&stack);
	*/
	for (i = 1; i < MAX+1; i++)
	{
		push_stack2(&stack,i);
	}
	pop_stack2(&stack);
	return 0;
}
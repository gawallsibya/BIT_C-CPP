#include "std.h"
#include "stack.h"

int main()
{
	int i;
	Stack stack;
	Stack_Init(&stack);
	for (i = 1; i < MAX+1; i++)
	{
		push(&stack,i);
	}
	pop(&stack);
	printf("\n");
	return 0;
}
#include "std.h"
void main()
{
	int i;
	Stack stack;
	Stack_Init(&stack);//√ ±‚»≠
	printf("STACK IN INSERT!!");
	printf("\n");

	for(i=1;i<MAX+1;i++)
	{
		Push(&stack,i);
	}
	printf("\n");
	printf("POP");
	Pop(&stack);
	printf("\n");

/*
	for(i=1;i<MAX+1;i++)
	{
		Push1(&stack,i);
	}

	printf("\n");
	printf("POP");
	Pop1(&stack);
	printf("\n");
*/
}

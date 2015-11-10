#include "std.h"
#include "stack.h"
void main()
{
	int i,n=0;
	int ch;
	Stack stack;
	stack_init(&stack);
	
	printf("[1] Upstack\n");
	printf("[2] Downstack\n");
	scanf("%d",&ch);
	if(ch==1)
	{
		printf("==================\n");
		for(i=0;i<MAX;i++)
		{
			Upstack_push_front(&stack,i+1);
		}
		stack_state(&stack);
		for(i=MAX-1;i>-1;i--)
		{
			printf("%d\t",Upstack_pop_front(&stack));
		}
		printf("\n");
		stack_state(&stack);
	}
	else if(ch==2)
	{
		printf("==================\n");
		for(i=MAX-1; i>-1; i--,n++)
		{
			Downstack_push_front(&stack,n+1);
		}
		stack_state(&stack);
		for(i=0; i<MAX; i++)
		{
			printf("%d\t",Downstack_pop_front(&stack));
		}
		printf("\n");
		stack_state(&stack);
	}	
	
}
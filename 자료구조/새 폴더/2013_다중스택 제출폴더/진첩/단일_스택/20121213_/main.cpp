#include"std.h"
void main()
{
	stack Stack;
	int i;int m;int n;
	init_stack(&Stack);
	for(i=0;i<MAX;i++)
	{
		n=push(&Stack,i);
		printf("push num :%4d\n",n);
	}
	print_stack(&Stack);
	push(&Stack,6);												//overflow
	m=pop(&Stack);
	printf("pop num:%4d\n",m);
	pop(&Stack);pop(&Stack);pop(&Stack);pop(&Stack);pop(&Stack);//underflow
}
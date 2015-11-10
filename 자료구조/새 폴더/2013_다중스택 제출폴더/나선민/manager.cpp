#include "manager.h"
STACK stack;

void manager_init()
{
	init_stack(&stack);
}
void manager_frontpush()
{
	int num;
	printf("숫자를 입력하시오");		scanf("%d" , &num);
	frontpush_stack(&stack, num);
	printall();
}
void manager_toppush()
{
	int num;
	printf("숫자를 입력하시오");		scanf("%d" , &num);
	toppush_stack(&stack, num);
	printall();
}
void manager_frontpop()
{
	frontpop_stack(&stack);
	printall();
}
void manager_toppop()
{
	toppop_stack(&stack);
	printall();
}
void manager_printstack1()
{
	char ch;
	printf("[1]FRONTPUSH	[2]FRONTPOP		: ");	scanf("%d" , &ch);
	switch(ch)
	{
	case 1:	manager_frontpush();	break;
	case 2:	manager_frontpop();		break;

	}
}
void manager_printstack2()
{
	char ch;
	printf("[1]TOPPUSH	[2]TOPPOP		: ");	scanf("%d" , &ch);
	switch(ch)
	{
	case 1:	manager_toppush();		break;
	case 2:	manager_toppop();		break;
	}
}
void printall()
{
	if(stack.top == -1) 
		printf("[Stack empty]\n");
	for(int i=0; i<MAX; i++)
	{	
		printf("%d\t" , stack.stack[i]);
	}
}
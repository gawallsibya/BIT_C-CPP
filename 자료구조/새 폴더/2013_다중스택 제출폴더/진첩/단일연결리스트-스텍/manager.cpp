#include "std.h"
#include "mystack.h"
MYSTACK g_stack;

void Manager_Init()
{
	stack_init(&g_stack);
}


void Manager_Insert()
{
	char ch[256];
	printf("���� �Է�: ");
	gets(ch);
	int num=strlen(ch);
	
	for(int i=0;i<num;i++)
	{
		push(&g_stack, ch[i]);
	}
	
}

void Manager_Printall()
{
	char data;
	pop(&g_stack, &data);  //&
	printf("%c\n", data);

}


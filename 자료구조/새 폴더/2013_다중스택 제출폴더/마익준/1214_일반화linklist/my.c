#include "std.h"
#include "my.h"

void MyPrint(NODE *cur)
{
	printf("%c",*((char*)cur->data));
}
char MySChar()
{
	char ch;
	printf("���� �Է�:");
	fflush(stdin);
	scanf("%c",&ch);
	return ch;
}

int MyIsEqual(NODE *cur,char* data)
{
	if(*((char*)cur->data) == *data)
		return 1;
	else 
		return 0;
}
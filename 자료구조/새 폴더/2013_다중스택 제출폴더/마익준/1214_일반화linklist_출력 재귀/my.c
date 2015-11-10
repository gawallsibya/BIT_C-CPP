#include "std.h"
#include "my.h"

void MyPrint(NODE *cur)
{
	printf("%c",*((char*)cur->data));
}
char MySChar()
{
	char ch;
	printf("문자 입력:");
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
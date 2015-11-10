#include <stdio.h>

void main(int argc, int *argv[])
{
	int num1, num2;
	char op;
	if( argc != 4 )
	{
		printf("[오류]전달인자 형식 2 + 3\n");
		return;
	}
	
	num1 = atoi(argv[1]);	// "2"
	op = argv[2][0];		// "+" ==> '+' '\0'
	num2 = atoi(argv[3]);    // "3"
	switch(op)
	{
	case '+':		printf("%d\n", num1 + num2); break;
	case '-':		printf("%d\n", num1 - num2); break;
	}

	
	/*
	int i;
	printf("%d\n", argc);

	for(i=0; i< argc; i++)
	{
		printf("[%d]%s\n", i, argv[i]);
	}
	*/

	getch();
}
#include <iostream>
using namespace std;
/*
#define MAX 10
int arr[10];
int top=0;
void Stack1()
{
	for(int i=0; i<MAX; i++)
	{
		int num;
		printf("숫자 입력 : ");		scanf("%d" , &arr[i]);
		printf("숫자를 더입력하시겠습니까?[1]YES [2]NO");		scanf("%d" , &num);
		if(num == 2)
		{
			top++;
			return;
		}
		top++;
	
	}
	if(top == MAX)
	{
		printf("UnderFlow....\n");
	}

}
void Stack2()
{

}
void main()
{
	int ch;
	printf("몇번스택? [1]		[2]\n");
	scanf("%d" , &ch);
	switch(ch)
	{
	case 1 : Stack1();		break;
	case 2 : Stack2();		break;
	}

	for(int i=0; i<top; i++)
	{
		printf("%d\n" , arr[i]);
	}
}
*/
/*STACK : array version */

#include "app.h"
void main()
{
	app_init();	

	app_run();

	app_Exit();
}
/*
	push(3);
	print_stack();

	printf("\nInitailize stack\n");
	init_stack();
	print_stack();

	printf("\nNow stack is empty, pop\n");
	i = pop();
	printf("popping value is %d\n", i);

	print_stack();

*/
#include "std.h"
#include "manager.h"
#include "stack.h"
STACK  Stack;
void manager_init()
{
	Stack.top1=-1;
	Stack.top2=5;
}
int manager_front_push()
{
	int num;
	printf("input num:\n");
	scanf("%d",&num);
	if(Stack.top1+1==Stack.top2)
	{
		printf("overflow\n");
		return -1;
	}
	Stack.arr[++Stack.top1]=num;
	printf("push success\n");
	return num;
}
int manager_back_push()
{
	int num;
	printf("input num:\n");
	scanf("%d",&num);
	if(Stack.top1-1==Stack.top2)
	{
		printf("overflow\n");
		return -1;
	}
	Stack.arr[--Stack.top2]=num;
	printf("push success\n");
	return num;
}
int manager_front_pop()
{
	if(Stack.top1<0)
	{
		printf("underflow\n");
		return -1;
	}
	printf("pop num:%d\n",Stack.arr[Stack.top1--]);
	return Stack.arr[Stack.top1];
}
int manager_back_pop()
{
	if(Stack.top2>4)
	{
		printf("underflow\n");
		return -1;
	}
	printf("pop num:%d\n",Stack.arr[Stack.top2++]);
	return Stack.arr[Stack.top2];
}
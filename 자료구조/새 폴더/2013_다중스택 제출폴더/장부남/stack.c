#include "std.h"
#include "stack.h"

stack front;

void stack_init()
{
	front.count = -1;
	front.a_count = MAX;
}

void a_push()
{
	int data;
	printf("�� �Է� : ");  scanf("%d",&data);
	if(front.count +1 ==front.a_count)
	{
		printf("Overflow\n");
		return;
	}
	front.stack[++front.count] = data;
}


void a_pop()
{
	if(front.count < 0)
	{
		printf("Underflow\n");
		return;
	}
	printf("%d ��° ����Ÿ: %d\n",front.count+1,front.stack[front.count]);
	front.count--;
}
void b_push()
{
	int data;
	printf("�� �Է� : "); scanf("%d", &data);
	if(front.a_count  == front.count+1)
	{
		printf("Overflow\n");
		return;
	}
	front.stack[--front.a_count] = data;
}
void b_pop()
{
	if(front.a_count >= MAX)
	{
		printf("Underflow\n");
		return;
	}
	printf("%d ��° ����Ÿ: %d\n",front.a_count+1,front.stack[front.a_count]);
	front.a_count++;
}

void printall()
{
	int i;
	printf("��� ��� : ");
	
	for(i=0; i<MAX; i++)
	{
		printf("%d\n", front.stack[i]);
	}
}
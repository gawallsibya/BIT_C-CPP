#include "std.h"
#include "Manager.h"

STACK k;

void init_stack()	//초기화..
{
	k.top1 = -1;
	k.top2 = MAX;
}

void top1_push_stack()
{
	int data;
	printf("숫자를 입력하세요 : ");  
	scanf("%d",&data);
	if(k.top2 == k.top1+1)
	{
		printf("Overflow.....\n");
		return;
	}
	k.stack[++k.top1] = data;
}
void top1_pop_stack()
{
	if(k.top1 < 0)
	{
		printf("Underflow.....\n");
		return;
	}
	printf("%d 번째 데이터 : %d\n",k.top1+1,k.stack[k.top1]);
	k.stack[k.top1] = 0; //	????????
	k.top1--;
}
void top2_push_stack()
{
	int data;
	printf("숫자를 입력하세요 : ");  
	scanf("%d",&data);

	if(k.top2 == k.top1+1)
	{
		printf("Overflow.....\n");
		return;
	}
	k.stack[--k.top2] = data;	
}
void top2_pop_stack()
{
	if(k.top2 >= MAX)
	{
		printf("Underflow.....\n");
		return;
	}
	printf("%d 번째 데이타 : %d\n",k.top2+1,k.stack[k.top2]);
	k.stack[k.top2] = 0;	//	????????
	k.top2++;
}
void stack_printall()
{
	int i;
	printf("입력된 데이타는...\n");
	
	for(i=0; i<MAX; i++)
	{
		printf("%d\n", k.stack[i]);
	}
}

#include "std.h"
#include "manager.h"


DATA s;

void manager_init()
{
	stack_init(&s);
}
void manager_up_insert()
{
	int a;

	printf("숫자 입력 : ");

	scanf("%d", &a);

	stack_push_up(&s, a);
}

void manager_down_insert()
{
	int a;

	printf("숫자 입력 : ");

	scanf("%d", &a);

	stack_push_down(&s, a);
}

void manager_up_delete()
{
	int i = s.top1;
	int j;
	j = stack_pop_up(&s);
	if(j)
	{
		printf("%d번째 입력한 데이터 : %d \n",s.top1+2,s.arr[s.top1]);
	}
}

void manager_down_delete()
{
	int i = s.top2;
	int j;
	j = stack_pop_down(&s);
	if(j)
	{
		printf("%d번째 입력한 데이터 : %d \n",s.top2+2,s.arr[s.top2]);
	}
}
#include "a.h"



void init()
{
	mul.front = -1;
	mul.back = MAX;
}
void insert()
{
	int data;
	printf("수치를 입력하세요 : ");  scanf("%d",&data);
	if(mul.front +1 == mul.back)
	{
		printf("Overflow.....\n");
		return;
	}
	mul.sta[++mul.front] = data;
}
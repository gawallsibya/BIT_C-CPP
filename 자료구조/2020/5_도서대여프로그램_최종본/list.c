// list.c
#include "std.h"


//------------- INPUT ------------------------------
void InputData(PERSON_NODE *node)
{
	int i;
	fflush(stdin);
	printf("이    름 : ");
	scanf("%s", node->name);
	printf("전화번호 : ");
	scanf("%d", &node->number);
	node->rentcount	= 0;
	for( i=0; i< RENTALNUM; i++)
	{
		node->rentbook[i] = NULL;
	}
	node->next = NULL;

}

void fnPersonInput()
{
	PERSON_NODE *node;
	node = (PERSON_NODE*)malloc(sizeof(PERSON_NODE));

	printf("**사용자 입력**\n");
			
	InputData(node);
	
	Insert(node);

	
}
void Insert(PERSON_NODE *node)
{
	PERSON_NODE *cur;
	
	if(list.head != NULL)
	{
		for(cur = list.head; cur->next != NULL; cur = cur->next)
			;

		cur->next = node;
	}
	else
		list.head  = node;
}



void DataPrint(PERSON_NODE *node)
{
	int i;
	printf("● 이    름 : %s\n", node->name);
	printf("   I     D  : %d\n", node->number);
	printf("   대여 개수: %d\n", node->rentcount);
	
	if( node->rentcount )
	{
		printf("   도서 이름: %d\n", node->rentcount);
	}
	for(i=0; i< RENTALNUM; i++)
	{
		if( node->rentbook[i] )
			printf("   ▶%s\n", node->rentbook[i]->name);
	}
	printf("\n");
}

void fnPersonPrint()
{
	PERSON_NODE *cur;
	cur = list.head;
	if(list.head != NULL)
	{
		for(cur = list.head; cur; cur=cur->next)
			DataPrint(cur);
	}
	else
		printf("데이터가 존재 하지 않습니다\n");
}



void fnPersonSearch()
{
	PERSON_NODE *cur;
	char name[20];
	
	if(list.head != NULL)
	{	
		printf("찾을 이름 입력 : ");
		fflush(stdin);
		scanf("%s", name);

		for(cur = list.head; cur; cur=cur->next)
		{
			if( !strcmp(cur->name, name) )
			{
				DataPrint(cur);
				return;
			}
		}
		printf("동일한 이름이 존재 하지 않습니다.\n");
	}
	else
		printf("데이터가 존재 하지 않습니다\n");
}
// list.c
#include "std.h"


//------------- INPUT ------------------------------
void InputData(PERSON_NODE *node)
{
	int i;
	fflush(stdin);
	printf("��    �� : ");
	scanf("%s", node->name);
	printf("��ȭ��ȣ : ");
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

	printf("**����� �Է�**\n");
			
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
	printf("�� ��    �� : %s\n", node->name);
	printf("   I     D  : %d\n", node->number);
	printf("   �뿩 ����: %d\n", node->rentcount);
	
	if( node->rentcount )
	{
		printf("   ���� �̸�: %d\n", node->rentcount);
	}
	for(i=0; i< RENTALNUM; i++)
	{
		if( node->rentbook[i] )
			printf("   ��%s\n", node->rentbook[i]->name);
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
		printf("�����Ͱ� ���� ���� �ʽ��ϴ�\n");
}



void fnPersonSearch()
{
	PERSON_NODE *cur;
	char name[20];
	
	if(list.head != NULL)
	{	
		printf("ã�� �̸� �Է� : ");
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
		printf("������ �̸��� ���� ���� �ʽ��ϴ�.\n");
	}
	else
		printf("�����Ͱ� ���� ���� �ʽ��ϴ�\n");
}
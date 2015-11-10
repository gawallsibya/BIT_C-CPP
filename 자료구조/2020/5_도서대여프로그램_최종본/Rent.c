#include "std.h"

// ���� ��Ʈ
void fnInputName(char* name)
{
	fflush(stdin);
	printf("ȸ�� �̸� �Է� : ");
	gets(name);
}

void fnBookRent()
{
	char name[20];
	PERSON_NODE *cur;
	fnInputName(name);
	
	if(list.head != NULL)
	{	
		for(cur = list.head; cur; cur=cur->next)
		{
			if( !strcmp(cur->name, name) )
			{
				DataPrint(cur);
				Rent(cur);
				return;
			}
		}
		printf("������ �̸��� ���� ���� �ʽ��ϴ�.\n");
	}
	else
		printf("�����Ͱ� ���� ���� �ʽ��ϴ�\n");
}

void Rent(PERSON_NODE *cur)
{
	char name[20];
	treeNode* book;
	int i;
	// �뿩 ���� ���� �Ǵ�
	if( cur->rentcount	== 3 )
	{
		printf("�뿩 ���� Ƚ���� �ʰ��Ͽ����ϴ�.\n");
		return;
	}
	
	// �뿩 ���� ��� ���
	fnBookPrint1();

	// �뿩 ����
	fflush(stdin);
	printf("�뿩�� å ������ �Է��ϼ��� : ");
	gets(name);

	book = searchBST(root,name) ;

	for( i=0; i<RENTALNUM; i++)
	{
		if(cur->rentbook[i] == NULL )
		{
			cur->rentbook[i] = &book->key;
			cur->rentcount++;
			break;
		}
	}
	book->key.rentperson = cur;
	printf("�뿩 �Ǿ����ϴ�.\n");


}


void fnBookReturn()
{
	char name[20];
	PERSON_NODE *cur;
	fnInputName(name);
	if(list.head != NULL)
	{	
		for(cur = list.head; cur; cur=cur->next)
		{
			if( !strcmp(cur->name, name) )
			{
				DataPrint(cur);
				Return(cur);
				return;
			}
		}
		printf("������ �̸��� ���� ���� �ʽ��ϴ�.\n");
	}
	else
		printf("�����Ͱ� ���� ���� �ʽ��ϴ�\n");
}


void Return(PERSON_NODE *cur)
{
	treeNode* book;
	char name[20];
	int i;
	printf("�ݳ��� å ������ �Է��ϼ��� : ");
	gets(name);

	book = searchBST(root,name) ;
	book->key.rentperson = NULL;

	for( i=0; i<RENTALNUM; i++)
	{
		if(!strcmp(cur->rentbook[i]->name, name) )
		{
			cur->rentbook[i] = NULL;
			cur->rentcount--;
			break;
		}
	}
	book->key.rentperson = cur;
	printf("�ݳ� �Ǿ����ϴ�.\n");

}

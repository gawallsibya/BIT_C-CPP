#include "manager.h"
#include "std.h"
Manager mm;
void Manager_Insert()
{
	char ch[256];
	printf("���� �Է�: ");
	gets(ch);
	int num=strlen(ch);
	
	for(int i=0;i<num;i++)
	{
		List_push_back(&mm.li,ch[i]);
	}
	printf("�Է°��: �� %d���� ���ڸ� �Է��ϼ̽��ϴ�.\n",mm.li.count);
}

void Manager_Printall()
{
	printf("������ ����: %d\n",mm.li.count);
	Node *cur = mm.li.head;
	while(cur != NULL)
	{
		printf("%c",cur->data);
		cur = cur->next;
	}
	printf("\n");

}

void Manager_Search()
{
	
	char ch;
	Node *cur;
	Manager_Printall();
	printf("�˻� ����: ");
	scanf("%c",&ch);
	fflush(stdin);
	cur =List_find(&mm.li,ch);
	
	printf("�˻����: �ּҰ�: %p, ������:%c, ���� �ּҰ�: %p\n",cur,cur->data,cur->next);
}

void Manager_Update()
{
	Manager_Printall();
	char ch;
	printf("���� ����: ");
	scanf("%c",&ch);
	fflush(stdin);
	List_modify(&mm.li,ch);
	Manager_Printall();
}

void Manager_Delete()
{
	Manager_Printall();
	char ch;
	printf("���� ����: ");
	scanf("%c",&ch);
	fflush(stdin);
	List_del(&mm.li,ch);
	Manager_Printall();
}

#include "Manager.h"
#include "std.h"

LIST list;	//������ �ʱ�ȭ�� �׻� �ҽ����Ͽ��� �ؾ� �Ѵ�.

void Manager_Insert()	//push_back
{
/*
���1 : ����ڰ� ���ڸ� �Է��ϸ� ���� �ϳ��� �ϳ��� ��忡 ��Ƽ� ����Ʈ ����
��) push_front, push_back 2���� ����� �ۼ�
*/
	int i;
	printf("���ڸ� �Է� �Ͻʽÿ� : ");
	fflush(stdin);
	gets(arr);
	for(i=0;arr[i] != '\0';i++)
	{
		//1. NODE ���� �ʱ�ȭ
		NODE* newnode	= (NODE*)malloc(sizeof(NODE));	//��� ����
		newnode->data	= arr[i];						//��忡 ������ �־��ֱ�
		newnode->next	= NULL;							//����� ���� �༮�� NULL!!!!

		if(list.head == NULL)
		{
			list.head = (NODE*)malloc(sizeof(NODE));
			list.head = newnode;
			list.count++;
		}
		else
		{
			NODE* next = list.head;
			while(next -> next != NULL)
			{
				next = next->next;				
			}

			next->next = newnode;
			list.count++;
		}	

		//if(list.head == NULL)
		//{
		//	list.head = newnode;
		//	list.count++;
		//}
		//else
		//{			
		//	newnode->next = list.head;
		//	list.head = newnode;
		//	list.count++;
		//}
	}
}
void Manager_PrintAll()
{
/*
���2 : ��� ��ȸ ���
����Ʈ�� ù��° ������ ��ȸ�ϸ� ���� ���
*/
	NODE *cur;
	cur = list.head;
	while (cur != NULL)
	{
		printf("%c",cur->data);
		cur = cur->next;
	}
	printf("������ ���� :%d\n",list.count);
	system("pause");	
}
void Manager_Search()
{
/*
���3 : ��� �˻�
��µ� ���ڿ� �� �ϳ��� ���ڸ� �����ϸ� �� ���ڰ� ����� ����� �ּҰ��� ����
��, ���Ϲ��ڰ� ������ �ԷµǾ��� ��� ù��° ���� ���� ����� �ּҰ� ����
*/
	NODE *cur;
	char ch;
	Manager_PrintAll();
	printf("�˻� ����:");
	fflush(stdin);
	scanf("%c",&ch);
	cur = find(ch);
	if (cur == NULL)
	{
		printf("��ã�Ҵ�..\n");
	}
	else
	{
		printf("ã�Ҵ�..:%c\n",cur->data);
	}
	system("pause");
}
void Manager_Modify()
{
/*
���4 : ����
��µ� ���ڿ� �� �ϳ��� ���ڸ� �����Ͽ� 
�ش繮�ڰ� �ҹ��ڶ�� �빮�ڷ�, �빮�ڶ�� �ҹ��ڷ� ����
*/
	NODE *cur;
	char ch,CH;
	Manager_PrintAll();
	fflush(stdin);
	printf("������ ����:");
	scanf("%c",&ch);//
	cur = find(ch);
	fflush(stdin);
	if (cur == NULL)
	{
		printf("������ ���ڿ��� �������� �ʽ��ϴ�..\n");
	}
	else
	{
		// ������ ���ڿ� �ޱ� 
		//
		printf("���� ���� : ");
		scanf("%c",&CH);
		cur -> data = CH;
		printf("���� �Ϸ� �߽��ϴ�");
	}
	
	/*
	fflush(stdin);
	scanf("%c%c",&ch,&CH);//����
	cur = find(ch);
	fflush(stdin);
	if (cur != NULL)
	{
		cur->data = CH;
	}
	else
	{
		printf("�d�� ���� �� �����ϴ�...\n");
	}
	*/
	system("pause");
}
void Manager_Erase()
{
/*
���5 : ����
��µ� ���ڿ� �� �ϳ��� ���ڸ� �����Ͽ� �ش� ���ڰ� ����� ��带 ����
*/
	NODE* prev, *cur;
	char ch;
	prev = cur = list.head;
	
	Manager_PrintAll();
	printf("���� ����:");
	fflush(stdin);
	scanf("%c",&ch);

	if( cur->data == ch) // ù��° ��带 ���.
	{
		list.head = cur->next;
		list.count--;
		free(cur);
	}
	else // �߰��� ���
	{
		cur = cur->next;
		while( cur != NULL)
		{
			if( cur->data == ch)
			{
				prev->next	= cur->next;
				list.count--;
				free(cur);
				return;
			}
			else
			{
				//prev = cur;
				//cur = cur -> next;
				cur = cur->next;
				prev = prev->next;
			}
		}
	}
}
NODE* find(char ch)
{
	NODE *cur;
	cur = list.head;
	while(cur->next != NULL )
	{
		if (cur->data == ch)
		{
			return cur; //���� 
		}
		cur = cur->next;
	}
	return NULL;
}
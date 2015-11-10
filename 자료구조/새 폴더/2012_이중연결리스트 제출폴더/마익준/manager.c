#include "std.h"
#include "manager.h"
void manager_init()
{
	list.head = NULL;
	list.count = 0;
}
void manager_push_front()
{
	int i;
	printf("���ڸ� �Է� �ּ���:");
	fflush(stdin);
	gets(arr);
	for(i = 0;arr[i] != '\0'; i++)
	{
		NODE *newnode = (NODE*)malloc(sizeof(NODE)); 

		newnode->data = arr[i];
		newnode->next = NULL;
		newnode->prev = NULL;

		if(list.head == NULL)
		{
			list.head = newnode;
			list.count++;
		}
		else
		{
			list.head->prev = newnode;
			newnode->next = list.head;
			list.head = newnode;
			list.count++;
		}
	}
}
void manager_printall()
{
	NODE *cur;
	cur = list.head;
	while (cur != NULL)
	{
		printf("%c",cur->data);
		cur = cur->next;
	}
	printf("\n");
	printf("����:%d",list.count);
	printf("\n");
}

void manager_search()
{
	if(list.count == 0)
	{
		printf("����:0\n");
		printf("���� �� �ּ���...\n");
		return;
	}
	else
		{
		NODE *cur;
		char ch;
		manager_printall();
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
			printf("ã�Ҵ�..:%c�ּ� ��:%p\n ",cur->data,&cur->data);
		}
	}
	//system("pause");
}
void manager_change()
{
	if(list.count == 0)
	{
		printf("����:0\n");
		printf("���� �� �ּ���...\n");
		return;
	}
	else
	{
		NODE *cur;
		char ch,CH;
		manager_printall();
		printf("���� & ���� ����:");
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
			printf("�ش� ���� �� �����ϴ�...\n");
		}
		system("pause");
	}
}
void manager_dele()
{
	if(list.count == 0)
	{
		printf("����:0\n");
		printf("���� �� �ּ���...\n");
		return;
	}
	else
	{
		NODE *cur;
		char ch;
		cur = list.head;
		
		manager_printall();
		printf("���� ����:");
		fflush(stdin);
		scanf("%c",&ch);
		
		while(cur != NULL)
		{
			
			if(cur->data == ch)
			{
				if(cur->prev == NULL)
				{	
					if(list.count == 1)
					{
						list.head = cur->next;
						free(cur);
						list.count--;
					}
					else
					{
						list.head = cur->next;
						list.head->prev = NULL;
						free(cur);
						list.count--;
					}
				}
				else
				{
					cur->prev->next = cur->next;
					if (cur->next == NULL)
					{
						cur->prev->prev = NULL;
					}
					else
					{
						cur->next->prev = cur->prev;
					}
					free(cur);
					list.count--;
				}
				return;//����
			}
			else 
				cur = cur->next;
		}
		manager_printall();
	}
}

NODE* find(char ch)
{
	NODE *cur;
	cur = list.head;
	while(cur != NULL )
	{
		if (cur->data == ch)
		{
			return cur; //���� 
		}
		cur = cur->next;
	}
	return NULL;
}
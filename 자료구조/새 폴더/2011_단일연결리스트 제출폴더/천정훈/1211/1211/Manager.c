#include"Manager.h"
#include"std.h"

LIST list;		//������ ������ �ҽ� �ڵ忡 �Ұ�.

void insert(LIST _list)
{
	int i,count=0;
	char arr[256]={NULL};
	NODE *newnode;
	printf("���ڸ� �Է��ϼ��� :");
	gets(arr);
	for(i=0;i<256;i++)
	{
		if(arr[i]!=NULL)
		{
			count++;
		}
	
	}
	for(i=0;i<count;i++)
	{
		newnode=(NODE*)malloc(sizeof(NODE));
		newnode->data = *(arr+i);
		newnode->next=NULL;
			
	mylist_init(&list);		//list�� manager�� �ű��.
	 
	//���� front 
	mylist_push_front(&list,newnode);

	//���� back;
//	mylist_push_back(&list,newnode);
	}

	
}
void printall(LIST list)
{
	NODE *cur = list.head;

	printf("������ ���� :%d��\n",list.count);
		while(cur != NULL)
		{			
			printf("%c\t", cur->data);
			cur = cur->next;
		}
	
}
NODE* search(char ch)
{
	
	NODE *cur;

	cur = list.head;
		while( cur != NULL)
		{
			if( cur->data == ch)
			{
				printf("\n�˻����:�ּҰ�:%p",cur);
				return cur;
			}
			cur = cur->next;
		}
		printf("����Ʈ���� ��ã�Ҵ�..\n");
		return NULL;
}
void updata()
{
	char ch;
		printf("\n�������� :");
		fflush(stdin);
		scanf("%c",&ch);
		{
		NODE *cur = search(ch);
		

			if( cur == NULL)
			{
				printf("�׷��� ����");
			}
			else
			{
				if(ch>64 && ch<97)
				{
					cur->data = cur->data+32;
				}
				else
				{
					cur->data	= cur->data-32;
				}
					
			}
		}
}
/*
if(ch>64 && ch<97)
				{
					printf("\n�˻�����:%c\n�˻����� �ּҰ�:%x",cur->data+32,cur);
				}
				else
					printf("\n�˻�����:%c\n�˻����� �ּҰ�:%x",cur->data-32,cur);
				

*/

void del()
{
	NODE *pre;
	NODE *cur;
	char ch;
	pre=list.head;
	cur=list.head;
	printf("\n��������:");
	scanf("%c",&ch);
	fflush(stdin);
	if( cur->data == ch)
	{
		list.head = cur->next;
		free(cur);
	}
	else
	{
		cur = cur->next;
		while( cur != NULL)
		{
			if( cur->data == ch)
			{
				pre->next	= cur->next;
				free(cur);
				return;
			}
			else
			{
				cur = cur->next;
				pre = pre->next;
			}
		}
	}

}
#include "manager.h"
#include "mylist.h"
#include "std.h"
#include "string.h"

LIST list; 

void manager_Init()
{
	_init(&list);
}

void Insert()
{
	int i;
	int num;
	char arr[256];
	

	printf("���ڸ� �Է��ϼ��� : ");  gets(arr);
	num=strlen(arr);

	for(i=0; i < num; i++)
	{
		_push_front(&list, arr[i]);
		list.count++;
	}
}

void Print()
{	
	NODE *cur = list.head;
	printf("�Էµ� ������ ������ : %d\n", list.count);
	printf("�Էµ� ���ڴ� :");
	while(cur!=NULL)
	{
		printf("%c", cur->data);
		cur=cur->next;
	}
	printf("\n");
	
}

NODE *CharToNode(char ch)
{
	NODE *cur = list.head;
	while(cur!=NULL)
	{
		if(cur->data==ch)
		{
			return cur;		
		}	
		cur = cur->next;
	}
	return NULL;
}

void search()
{	
	char ch;
	NODE *cur;
	printf("�˻��� ���ڸ� �Է��ϼ��� : ");  scanf("%c", &ch); 	
	fflush(stdin);
	cur = CharToNode(ch);
	if(cur->data==ch)
	{
		printf("ã�Ҵ�!!! ���ڴ� :%c, �ּҴ� :%p, ���� �ּҴ� :%p", cur->data, cur, cur->next);  
	}
}


void modify()
{
	char ch;
	NODE *cur;
	printf("�ٲٰ� ���� ���ڸ� �Է��ϼ��� : "); scanf("%c", &ch); 
	fflush(stdin);
	cur = CharToNode(ch);
		if(cur->data == ch)
		{
			if('a'<= cur->data && cur->data <= 'z')
			{
				cur->data -= 32; 
			}

			else
			{
				cur->data += 32;
			}
		}	
}

void del()
{
	NODE *cur;
	char ch;	
	printf("���� ���� : ");  scanf("%c",&ch);
	fflush(stdin);
	cur = CharToNode(ch);
	if(cur->data == ch)
	{
		NODE *del, *prev;
		del = cur;
		prev = cur->prev;

		if(cur==list.head)
		{
			list.head = cur->next;
		}
		else if(cur==list.tail)
		{
			list.tail = cur->prev;
			list.tail->next = NULL;
		}
		else
		{
			prev->next = cur->next;
			cur->next = prev;
		}
		free(cur);
		list.count--;
	}

}
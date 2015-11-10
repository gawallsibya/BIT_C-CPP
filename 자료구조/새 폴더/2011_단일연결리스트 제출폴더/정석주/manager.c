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
	

	printf("문자를 입력하세요 : ");  gets(arr);
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
	printf("입력된 문자의 개수는 : %d\n", list.count);
	printf("입력된 문자는 :");
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
	printf("검색할 문자를 입력하세요 : ");  scanf("%c", &ch); 	
	fflush(stdin);
	cur = CharToNode(ch);
	if(cur->data==ch)
	{
		printf("찾았다!!! 문자는 :%c, 주소는 :%p, 다음 주소는 :%p", cur->data, cur, cur->next);  
	}
	

}

void modify()
{
	char ch;
	NODE *cur;
	printf("바꾸고 싶은 문자를 입력하세요 : "); scanf("%c", &ch); 
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
	LIST prev, cur;
	char data;	
	printf("삭제 문자 : ");  scanf("%c",&data);
	fflush(stdin);
	prev = cur = list;
	if(cur.head->data == data)
	{
		list.head = cur.head->next;
		free(cur.head);
		list.count--;
	}
	else
	{
		cur.head = cur.head->next;
		while(cur.head->data)
		{
			if(cur.head->data == data)
			{
				prev.head->next = cur.head->next;
				free(cur.head);
				list.count--;
				return;
			}
			prev.head = prev.head->next;
			cur.head = cur.head->next;
		}
	}

}
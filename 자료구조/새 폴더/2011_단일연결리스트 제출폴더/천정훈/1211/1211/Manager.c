#include"Manager.h"
#include"std.h"

LIST list;		//변수의 선언은 소스 코드에 할것.

void insert(LIST _list)
{
	int i,count=0;
	char arr[256]={NULL};
	NODE *newnode;
	printf("문자를 입력하세요 :");
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
			
	mylist_init(&list);		//list를 manager로 옮길것.
	 
	//연결 front 
	mylist_push_front(&list,newnode);

	//연결 back;
//	mylist_push_back(&list,newnode);
	}

	
}
void printall(LIST list)
{
	NODE *cur = list.head;

	printf("문자의 개수 :%d개\n",list.count);
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
				printf("\n검색결과:주소값:%p",cur);
				return cur;
			}
			cur = cur->next;
		}
		printf("리스트에서 못찾았다..\n");
		return NULL;
}
void updata()
{
	char ch;
		printf("\n수정문자 :");
		fflush(stdin);
		scanf("%c",&ch);
		{
		NODE *cur = search(ch);
		

			if( cur == NULL)
			{
				printf("그런거 읎음");
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
					printf("\n검색문자:%c\n검색문자 주소값:%x",cur->data+32,cur);
				}
				else
					printf("\n검색문자:%c\n검색문자 주소값:%x",cur->data-32,cur);
				

*/

void del()
{
	NODE *pre;
	NODE *cur;
	char ch;
	pre=list.head;
	cur=list.head;
	printf("\n삭제문자:");
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
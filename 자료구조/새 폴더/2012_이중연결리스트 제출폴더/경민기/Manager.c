#include "std.h"
#include "manager.h"

void init()
{
	List *list = (List*)malloc(sizeof(List));
	list->head=NULL;
	list->tail=NULL;
	list->count =0;
}
void insert()
{
	int i;
	printf("문자를 입력 주세요:");
	fflush(stdin);
	gets(arr);
	for(i = 0;arr[i] != '\0'; i++)
	{
		NODE *newnode = (NODE*)malloc(sizeof(NODE)); 

		newnode->data = arr[i];
		newnode->next = NULL;
		if(list.head == NULL)
		{
			list.head = newnode;
			list.tail = newnode;
			list.count++;
		}
		else
		{
			newnode->next = list.head;
			list.head->prev = newnode;
			list.head=newnode;
			list.count++;
		}
	}
}

void printall()
{
	NODE *cur;
	cur = list.head;
	while (cur != NULL)
	{
		printf("%c",cur->data);
		cur = cur->next;
	}
	printf("\n갯수는? %d",list.count);
	printf("\n");
	system("pause");
}

void search()
{
	NODE *cur;
	char ch;	
	printall();
	printf("검색 문자:");
	fflush(stdin);
	scanf("%c",&ch);
	cur = find(list.head, ch);


	if (cur == NULL)
	{
		printf("데이터가 없습니다..\n");
	}
	else
	{
		printf("찾은 문자:%c, 주소 : %d\n",cur->data, &cur->data);
	}
	system("pause");
}

void modify()
{
	NODE *cur;
	char ch;

	printall();

	printf("수정할 문자:");
	fflush(stdin);
	scanf("%c",&ch);

	cur = find(list.head, ch);
	fflush(stdin);

	if ('a'<=ch&&ch<='z')
	{
		cur->data = ch-32;
	}

	else if('A'<=ch&&ch<='Z')
	{
		cur->data = ch+32;
	}

	else
	{
		printf("해당 문자가 없습니다...\n");
	}system("pause");
		printall();

}
void dele()
{
	
	NODE *cur;

	char ch;
	printall();
	printf("삭제 문자:");
	fflush(stdin);
	scanf("%c", &ch);

	cur = find(list.head, ch);
	if( cur == NULL)
	{
		printf("못찾았어요~...\n");
	}
	else
	{
		NODE *del, *prev;
		del		= cur;
		prev	= cur->prev;

		if( cur == list.head)
		{
			list.head = cur->next;
		}
		else if( cur == list.tail)
		{
			prev->next		= NULL;
			list.tail	= prev;
		}
		else
		{
		prev->next		= del->next;
		del->next->prev	= prev;
		}

		free(del);
		list.count--;
	}

		printall();

}

NODE* find(NODE *start, char ch)
{
	NODE *cur;
	cur = list.head;

	while(cur != NULL )
	{
		if (cur->data == ch)
		{
			return cur;
		}
		
		cur = cur->next;
	}
	
	return NULL;
}
#include "std.h"
#include "manager.h"

void init()
{
	List *list = (List*)malloc(sizeof(List));
	list->head=NULL;
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
			list.count++;
		}
		else
		{
			newnode->next = list.head;
			list.head = newnode;
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
	cur = find(ch);


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

	cur = find(ch);
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
	NODE *prev, *cur;
	char ch;
	prev = cur = list.head;
	
	printall();
	printf("삭제할 문자:");
	fflush(stdin);
	scanf("%c",&ch);

	if( cur->data == ch)
	{
		list.head = cur->next;
		list.count--;
		free(cur);
	}

	else
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
				cur = cur->next;
				prev = prev->next;
			}
		}
	}
		printall();

}

NODE* find(char ch)
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
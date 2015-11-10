#include "std.h"
#include "mylist.h"
//char arr[MAX_SIZE];
void insert(int n)
{
	int i;
	char temp;
	NODE *newnode;
	//NODE *cur = list.head;
	//NODE **start =&list.head;
	printf("default string length:14\n");
	printf ("please input your string  and enter [enter]:\n");	
	for (i = 0;i < n;i++){
		while ((temp = getchar()) == '\n')
				  continue;
		newnode= (NODE*)malloc (sizeof(NODE));
		newnode->data = temp;
		newnode->next = list.head;
		list.head = newnode;

	/*	NODE *cur = list.head;
		if( *start == NULL)
	{
		*start		= newnode;
	}
	else
	{
		while( cur->next != NULL)
		{
			cur = cur->next;
		}
		cur->next = newnode;
	}
	*/

	}
	list.count = n;
	printf ("create over\n");
}
void printall()
{
	//puts(arr);
	//fflush(stdin);
	NODE* start=list.head;
	NODE* cur=start;
	while(cur!=NULL)
	{
		printf("%c\t",cur->data);
		cur=cur->next;
	}
}
NODE* search( char c)
{
	
	{
		NODE *cur = list.head;
		while( cur != NULL)
		{
			if( cur->data == c)
			{
				printf("searched...:%c\n", cur->data);
				printf("cur adress:%d\n",cur);
				printf("next adress:%d\n",cur->next);
				return cur;
			}
			cur = cur->next;
		}
		printf("can't searched..\n");
		return NULL;
	}
}

void update(char c )
{
	
	char C;
	NODE *cur = search(c);
	
	if( cur == NULL)
	{
		printf("error");
	}
	else
	{
		if(c>=97)
		C=c-32;
		else 
		C=c+32;
		cur->data	= C;
		printf("after update:%c",cur->data);
	}
}

void dele( )
{
	char c;
	NODE *prev, *cur;
	printf("the char you want to del:\n");
	fflush(stdin);
	c=getchar();

	
	prev = cur = list.head;
	if( cur->data == c)
	{
		list.head = cur->next;
		free(cur);
	}
	else
	{
		cur = cur->next;
		while( cur != NULL)
		{
			if( cur->data == c)
			{
				prev->next	= cur->next;
				printf("del success\n");
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
}

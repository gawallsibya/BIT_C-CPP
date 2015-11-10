#include "std.h"
#include "manager.h"

void manager_slist_init()
{
	slist.count = 0;
	slist.head = NULL;
}

void manager_push_front()
{
	int i;
	printf("문자를 입력 주세요:");
	fflush(stdin);
	gets(arr);
	for(i = 0;arr[i] != '\0'; i++)
	{
		NODE *newnode = (NODE*)malloc(sizeof(NODE)); 
		if(newnode == NULL)
			return;
		newnode->data = &arr[i];
		newnode->next = NULL;
		newnode->prev = NULL; 

		if(slist.head == NULL)
		{
			slist.head = newnode;
			slist.count++;
		}
		else
		{
			slist.head->prev = newnode;
			newnode->next = slist.head;
			slist.head = newnode;
			slist.count++;
		}
	}
}

void manager_pop()
{
	NODE *cur;
	cur = slist.head;
	while (cur != NULL)
	{
		printf("%c",*((char*)cur->data));
		cur = cur->next;
	}
	printf("\n");
}
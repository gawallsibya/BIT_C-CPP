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
		newnode->data = &arr[i]; //주의
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

void manager_printall(NODE *cur,void (*f)(void*))
{
	if (cur != NULL)
	{
		manager_printall(cur->next,MyPrint);
		f(cur);
		cur = cur->next;	
	}
}

NODE* find(int (*f)(void*,void*))
{
	NODE *cur = slist.head;
	void *p; char ch = MySChar();
	p = &ch;
	while (cur != NULL)
	{
		if (f(cur,p))
			return cur;
		cur = cur->next;
	}
	return NULL;
}

NODE* manager_Search()
{
	
	NODE *cur;
	
	manager_printall(slist.head,MyPrint);
	cur = find(MyIsEqual);
	if (cur != NULL)
	{
		printf("찾았다...\n");
	}
	else 
		printf("없다...\n");
	return cur;
}

void manager_ChangeData()
{
	NODE *cur;
	cur = manager_Search();
	if (cur != NULL)
	{
		char ch;
		printf("수정......\n");
		ch = MySChar();
		*(char*)cur->data = ch;  //주의 
		printf("OK\n");
		manager_printall(slist.head,MyPrint);
	}
}

void manager_delete()
{
	NODE *cur;
	cur = manager_Search();
	if (cur != NULL)
	{
		if(cur->prev == NULL)
		{	
				if(slist.count == 1)
				{
					slist.head = cur->next;
					free(cur);
					slist.count--;
				}
				else
				{
					slist.head = cur->next;
					slist.head->prev = NULL;
					free(cur);
					slist.count--;
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
			slist.count--;
		}
		printf("OK\n");
		manager_printall(slist.head,MyPrint);
	}
}

void manager_update()
{
	NODE *cur;
	cur = manager_Search();
	if (cur != NULL)
	{
		char ch;
		NODE *cur_next;
		NODE *newnode = (NODE*)malloc(sizeof(NODE));
		if(newnode == NULL)
			return;
		cur_next = cur->next;
		printf("뒤에 삽입 하고 싶은 문자:...");
		ch = MySChar();
		
		newnode->data = &ch; //주의
		newnode->next = NULL;
		newnode->prev = NULL; 

		cur->next = newnode;
		newnode->next = cur_next;
		newnode->prev = cur; 
		if (cur_next != NULL)
					cur_next->prev = newnode;

		printf("OK\n");
		manager_printall(slist.head,MyPrint);
	}


}




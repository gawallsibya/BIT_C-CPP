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
	printf("문자를 입력 주세요:");
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
	printf("개수:%d",list.count);
	printf("\n");
}

void manager_search()
{
	if(list.count == 0)
	{
		printf("개수:0\n");
		printf("삽입 해 주세요...\n");
		return;
	}
	else
		{
		NODE *cur;
		char ch;
		manager_printall();
		printf("검색 문자:");
		fflush(stdin);
		scanf("%c",&ch);
		cur = find(ch);
		if (cur == NULL)
		{
			printf("못찾았다..\n");
		}
		else
		{
			printf("찾았다..:%c주소 값:%p\n ",cur->data,&cur->data);
		}
	}
	//system("pause");
}
void manager_change()
{
	if(list.count == 0)
	{
		printf("개수:0\n");
		printf("삽입 해 주세요...\n");
		return;
	}
	else
	{
		NODE *cur;
		char ch,CH;
		manager_printall();
		printf("문자 & 수정 문자:");
		fflush(stdin);
		scanf("%c%c",&ch,&CH);//주의
		cur = find(ch);
		fflush(stdin);
		if (cur != NULL)
		{
			cur->data = CH;
		}
		else
		{
			printf("해당 파일 중 없습니다...\n");
		}
		system("pause");
	}
}
void manager_dele()
{
	if(list.count == 0)
	{
		printf("개수:0\n");
		printf("삽입 해 주세요...\n");
		return;
	}
	else
	{
		NODE *cur;
		char ch;
		cur = list.head;
		
		manager_printall();
		printf("삭제 문자:");
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
				return;//주의
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
			return cur; //주의 
		}
		cur = cur->next;
	}
	return NULL;
}
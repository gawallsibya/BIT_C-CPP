#include "std.h"
#include "Manager.h"
#include "Mylist.h"

LIST list;

void manager_init()
{
	Mylist_init(&list);
}

void Insert()
{
	int i, num;
	char arr[256];

	printf("문자열 입력 : "); fflush(stdin);	gets(arr);
	
	num = strlen(arr);

	for(i = 0; i < num; i++)
	{
		mylist_push_back(&list, arr[i]);
	}

	printf("저장 갯수 : %d\n", list.count);
}

void Printall()
{
	NODE * cur;
	cur = list.head;

	printf("저장 갯수 : %d\n", list.count);
	printf("문자 출력 : ");

	while(cur != NULL)
	{
		printf("%c", cur->data);
		cur = cur->next;
	}
	printf("\n");
}

NODE * _Search(char ch)
{
	NODE * cur = list.head;
	while( cur != NULL )
	{
		if( cur->data == ch)
		{
			return cur;
		}
		cur = cur->next;
	}
	return cur;
}

void Search()
{
	NODE * cur;
	char ch;

	Printall();
	
	fflush(stdin);
	printf("검색문자 : ");
	scanf("%c", &ch);

	cur = _Search(ch);
	
	if( cur == NULL)
	{
		printf("못 찾았습니다.\n");
	}
	else
	{
		printf("검색결과 = 주소값 : %p, 데이터 : %c, : 다음 주소값 : %p\n", 
			cur, cur->data, cur->next);
	}
}

void Modify()
{
	NODE * cur;
	char ch;

	Printall();
	printf("대문자 또는 소문자를 변경할 문자 : ");
	fflush(stdin);
	scanf("%c", &ch);
	cur = _Search(ch);

	if(cur == NULL)
	{
		printf("해당 문자를 찾지 못했습니다.\n");
		return;
	}
	else
	{
		if(cur->data >= 'a' && cur->data <= 'z')
			cur->data -= 32;
		else if(cur->data >= 'A' && cur->data <= 'Z')
			cur->data += 32;
	}
	printf("\n");
	Printall();
}

void Del()
{
	NODE * prev, * cur;
	char ch;
	prev = cur = list.head;

	Printall();
	printf("삭제하고 싶은 문자 : ");
	fflush(stdin);
	scanf("%c", &ch);

	if( cur->data == ch)
	{
		list.head = cur->next;
		list.count--;
		free(cur);
	}
	else
	{
		cur = cur->next;
		while(cur != NULL)
		{
			if( cur->data == ch)
			{
				prev->next = cur->next;
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
}
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

	printf("문자열 입력하시오. : "); fflush(stdin);	gets(arr);
	
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

NODE * _Search(NODE * start, char ch)
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
	printf("검색을 원하는 문자를 입력하시오. : ");
	scanf("%c", &ch);

	cur = _Search(list.head, ch);
	
	if( cur == NULL)
	{
		printf("해당 문자를 찾지 못했습니다.\n");
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
	printf("대문자 또는 소문자를 변경할 문자를 입력하시오. : ");
	fflush(stdin);
	scanf("%c", &ch);
	cur = _Search(list.head, ch);

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
	char ch;
	NODE * cur;

	fflush(stdin);
	Printall();
	printf("삭제를 원하는 문자를 입력하시오. : ");
	scanf("%c", &ch);

	cur = _Search(list.head, ch);
	if( cur == NULL)
	{
		printf("해당 문자를 찾지 못했습니다.\n");
	}
	else
	{
		NODE *_cur, *prev;
		_cur	= cur;
		prev	= cur->prev;

		if(cur == list.head)
		{
			list.head = cur->next;
		}
		else if(cur == list.tail)
		{
			prev->next	= NULL;
			list.tail	= prev;
		}
		else
		{
			prev->next		= _cur->next;
			_cur->next->prev	= prev;
		}

		free(_cur);
		list.count--;
	}
}
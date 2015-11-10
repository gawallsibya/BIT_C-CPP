#include "manager.h"

LIST list;
void manager_myinit()
{
	mylist_init(&list);
}
void manager_insert()
{
	int i = 0;
	char a[MAX];

	printf("문자 입력 : ");		gets(a);
	while(a[i] != 0)
	{
		push_back(&list,a[i]);
//		push_front(&list,a[i]);
		i++;
	}

	printf("입력 결과 : 총 %d개의 데이터가 저장되었습니다.\n",list.count);		
}

void manager_printall()
{
	NODE * cur = list.head;
	printf("문자의 개수 : %d\n",list.count);
	printf("문자 출력 : ");
	while(cur != NULL)
	{
		printf("%c",cur->data);
		cur = cur->next;
	}
	printf("\n");
}

NODE* charToNODE(LIST list, char data)
{
	NODE * cur = list.head;
	while(cur != NULL)
	{
		if(cur->data == data)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}

void manager_search()
{
	char data;
	NODE * cur;
	manager_printall();
	printf("검색 문자 : ");		scanf("%c",&data);

	fflush(stdin);
	cur = charToNODE(list, data);

	if(cur != NULL)
	{
		printf("검색 결과 : 주소값 : %p, 데이터 : %c, 다음 주소값 : %p\n",cur, cur->data, cur->next);
	}
	else
	{
		printf("데이터를 찾지 못했습니다...\n");
	}
	
}

void manager_dele()
{
	NODE * prev;
	NODE * cur;
	char data;
	manager_printall();
	printf("삭제 문자 : ");  scanf("%c",&data);
	fflush(stdin);
	prev = cur = list.head;
	if(cur->data == data)
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
			if(cur->data == data)
			{
				prev->next = cur->next;
				free(cur);
				list.count--;
				return;
			}
			prev = prev->next;
			cur = cur->next;
		}
		printf("데이터가 없습니다...\n");
	}

}

void manager_modify()
{
	char data;
	NODE * cur;
	manager_printall();
	printf("수정문자 : ");		scanf("%c",&data);
	fflush(stdin);
	cur = charToNODE(list, data);
	if(cur != NULL)
	{
		if('a'<= cur->data && cur->data <= 'z')
		{
			cur->data -= 32; 
		}

		else //if('A'<= p.head->data && p.head->data <= 'Z')
		{
			cur->data += 32;
		}
	}
	else
	{
		printf("데이터를 찾지 못했습니다...\n");
	}

	printf("\n");
	manager_printall();

}
 
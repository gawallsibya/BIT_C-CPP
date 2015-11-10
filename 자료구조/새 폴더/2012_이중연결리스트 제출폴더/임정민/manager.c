#include "manager.h"

DLIST list;

void insert()
{
	int i = 0;
	char a[MAX];
	mylist_init(&list);
	fflush(stdin);
	printf("문자를 입력하시오 : ");	gets(a);
	while(a[i] != 0)
	{
		push_back(&list,a[i]);
		//push_front(&list,a[i]);
		i++;
	}
	printf("입력 결과 : 총 %d 개의 데이터가 저장되었습니다.\n",list.count);
}

void printall()
{
	DLIST p = list;
	printf("문자의 개수 : %d\n",list.count);
	printf("문자 출력 : ");
	while(p.head != NULL)
	{
		printf("%c",p.head->data);
		p.head = p.head->next;
	}
	printf("\n");
}
void search()
{
	DLIST p = list;
	char data;
	printall();
	fflush(stdin);
	printf("검색 문자 : ");		scanf("%c",&data);
	while(p.head !=NULL)
	{
		if(p.head->data == data)
		{
			printf("찾는 데이터 : %c, 주소 : %d\n",p.head->data, &p.head->data);
			return;
		}
		p.head = p.head->next;
	}
	printf("데이터를 찾지 못했습니다...\n");
}

void dele()
{
	DLIST prev, cur;
	char data;
	printall();
	fflush(stdin);
	printf("삭제 문자 : ");  scanf("%c",&data);
	prev = cur = list;
	if(cur.head->data == data)
	{
		list.head = cur.head->next;
		free(cur.head);
	}
	else
	{
		cur.head = cur.head->next;
		while(cur.head->data)
		{
			if(cur.head->data == data)
			{
				prev.head->next = cur.head->next;
				free(cur.head);
				return;
			}
			prev.head = prev.head->next;
			cur.head = cur.head->next;
		}
	}
}

void modify()
{
	DLIST p = list;
	char data;
	printall();
	fflush(stdin);
	printf("수정 문자 : ");		scanf("%c",&data);
	while(p.head !=NULL)
	{
		if(p.head->data == data)
		{
			p.head->data -= 32;
			printf("수정되었습니다.\n");
			return;
		}
		p.head = p.head->next;
	}
	printf("데이터를 찾지 못했습니다...\n");
}
 
#include "manager.h"
#include "std.h"
Manager mm;
void Manager_Insert()
{
	char ch[256];
	printf("문자 입력: ");
	gets(ch);
	int num=strlen(ch);
	
	for(int i=0;i<num;i++)
	{
		List_push_back(&mm.li,ch[i]);
	}
	printf("입력결과: 총 %d개의 문자를 입력하셨습니다.\n",mm.li.count);
}

void Manager_Printall()
{
	printf("문자의 개수: %d\n",mm.li.count);
	Node *cur = mm.li.head;
	while(cur != NULL)
	{
		printf("%c",cur->data);
		cur = cur->next;
	}
	printf("\n");

}

void Manager_Search()
{
	
	char ch;
	Node *cur;
	Manager_Printall();
	printf("검색 문자: ");
	scanf("%c",&ch);
	fflush(stdin);
	cur =List_find(&mm.li,ch);
	
	printf("검색결과: 주소값: %p, 데이터:%c, 다음 주소값: %p\n",cur,cur->data,cur->next);
}

void Manager_Update()
{
	Manager_Printall();
	char ch;
	printf("수정 문자: ");
	scanf("%c",&ch);
	fflush(stdin);
	List_modify(&mm.li,ch);
	Manager_Printall();
}

void Manager_Delete()
{
	Manager_Printall();
	char ch;
	printf("삭제 문자: ");
	scanf("%c",&ch);
	fflush(stdin);
	List_del(&mm.li,ch);
	Manager_Printall();
}

#include "Manager.h"
#include "std.h"

LIST list;	//변수의 초기화는 항상 소스파일에서 해야 한다.

void Manager_Insert()	//push_back
{
/*
기능1 : 사용자가 문자를 입력하면 문자 하나를 하나의 노드에 담아서 리스트 구성
단) push_front, push_back 2가지 기능을 작성
*/
	int i;
	printf("문자를 입력 하십시오 : ");
	fflush(stdin);
	gets(arr);
	for(i=0;arr[i] != '\0';i++)
	{
		//1. NODE 생성 초기화
		NODE* newnode	= (NODE*)malloc(sizeof(NODE));	//노드 생성
		newnode->data	= arr[i];						//노드에 데이터 넣어주기
		newnode->next	= NULL;							//노드의 다음 녀석은 NULL!!!!

		if(list.head == NULL)
		{
			list.head = (NODE*)malloc(sizeof(NODE));
			list.head = newnode;
			list.count++;
		}
		else
		{
			NODE* next = list.head;
			while(next -> next != NULL)
			{
				next = next->next;				
			}

			next->next = newnode;
			list.count++;
		}	

		//if(list.head == NULL)
		//{
		//	list.head = newnode;
		//	list.count++;
		//}
		//else
		//{			
		//	newnode->next = list.head;
		//	list.head = newnode;
		//	list.count++;
		//}
	}
}
void Manager_PrintAll()
{
/*
기능2 : 노드 순회 출력
리스트의 첫번째 노드부터 순회하며 문자 출력
*/
	NODE *cur;
	cur = list.head;
	while (cur != NULL)
	{
		printf("%c",cur->data);
		cur = cur->next;
	}
	printf("문자의 개수 :%d\n",list.count);
	system("pause");	
}
void Manager_Search()
{
/*
기능3 : 노드 검색
출력된 문자열 중 하나의 문자를 선택하면 그 문자가 저장된 노드의 주소값을 리턴
단, 동일문자가 여러개 입력되었을 경우 첫번째 저장 문자 노드의 주소값 리턴
*/
	NODE *cur;
	char ch;
	Manager_PrintAll();
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
		printf("찾았다..:%c\n",cur->data);
	}
	system("pause");
}
void Manager_Modify()
{
/*
기능4 : 수정
출력된 문자열 중 하나의 문자를 선택하여 
해당문자가 소문자라면 대문자로, 대문자라면 소문자로 변경
*/
	NODE *cur;
	char ch,CH;
	Manager_PrintAll();
	fflush(stdin);
	printf("수정할 문자:");
	scanf("%c",&ch);//
	cur = find(ch);
	fflush(stdin);
	if (cur == NULL)
	{
		printf("수정할 문자열이 존재하지 않습니다..\n");
	}
	else
	{
		// 수정할 문자열 받기 
		//
		printf("수정 문자 : ");
		scanf("%c",&CH);
		cur -> data = CH;
		printf("수정 완료 했습니다");
	}
	
	/*
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
		printf("햏당 파일 중 없습니다...\n");
	}
	*/
	system("pause");
}
void Manager_Erase()
{
/*
기능5 : 삭제
출력된 문자열 중 하나의 문자를 선택하여 해당 문자가 저장된 노드를 삭제
*/
	NODE* prev, *cur;
	char ch;
	prev = cur = list.head;
	
	Manager_PrintAll();
	printf("삭제 문자:");
	fflush(stdin);
	scanf("%c",&ch);

	if( cur->data == ch) // 첫번째 노드를 지울떄.
	{
		list.head = cur->next;
		list.count--;
		free(cur);
	}
	else // 중간꺼 지울떄
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
				//prev = cur;
				//cur = cur -> next;
				cur = cur->next;
				prev = prev->next;
			}
		}
	}
}
NODE* find(char ch)
{
	NODE *cur;
	cur = list.head;
	while(cur->next != NULL )
	{
		if (cur->data == ch)
		{
			return cur; //주의 
		}
		cur = cur->next;
	}
	return NULL;
}
#include "std.h"

// 도서 랜트
void fnInputName(char* name)
{
	fflush(stdin);
	printf("회원 이름 입력 : ");
	gets(name);
}

void fnBookRent()
{
	char name[20];
	PERSON_NODE *cur;
	fnInputName(name);
	
	if(list.head != NULL)
	{	
		for(cur = list.head; cur; cur=cur->next)
		{
			if( !strcmp(cur->name, name) )
			{
				DataPrint(cur);
				Rent(cur);
				return;
			}
		}
		printf("동일한 이름이 존재 하지 않습니다.\n");
	}
	else
		printf("데이터가 존재 하지 않습니다\n");
}

void Rent(PERSON_NODE *cur)
{
	char name[20];
	treeNode* book;
	int i;
	// 대여 가능 여부 판단
	if( cur->rentcount	== 3 )
	{
		printf("대여 가능 횟수를 초과하였습니다.\n");
		return;
	}
	
	// 대여 가능 목록 출력
	fnBookPrint1();

	// 대여 시작
	fflush(stdin);
	printf("대여할 책 제목을 입력하세요 : ");
	gets(name);

	book = searchBST(root,name) ;

	for( i=0; i<RENTALNUM; i++)
	{
		if(cur->rentbook[i] == NULL )
		{
			cur->rentbook[i] = &book->key;
			cur->rentcount++;
			break;
		}
	}
	book->key.rentperson = cur;
	printf("대여 되었습니다.\n");


}


void fnBookReturn()
{
	char name[20];
	PERSON_NODE *cur;
	fnInputName(name);
	if(list.head != NULL)
	{	
		for(cur = list.head; cur; cur=cur->next)
		{
			if( !strcmp(cur->name, name) )
			{
				DataPrint(cur);
				Return(cur);
				return;
			}
		}
		printf("동일한 이름이 존재 하지 않습니다.\n");
	}
	else
		printf("데이터가 존재 하지 않습니다\n");
}


void Return(PERSON_NODE *cur)
{
	treeNode* book;
	char name[20];
	int i;
	printf("반납할 책 제목을 입력하세요 : ");
	gets(name);

	book = searchBST(root,name) ;
	book->key.rentperson = NULL;

	for( i=0; i<RENTALNUM; i++)
	{
		if(!strcmp(cur->rentbook[i]->name, name) )
		{
			cur->rentbook[i] = NULL;
			cur->rentcount--;
			break;
		}
	}
	book->key.rentperson = cur;
	printf("반납 되었습니다.\n");

}

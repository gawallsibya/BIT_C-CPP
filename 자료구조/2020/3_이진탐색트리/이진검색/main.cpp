#include "std.h"

void menu()
{
	printf("\n*---------------------------*");
	printf("\n\t1 : 입력");
	printf("\n\t2 : 삭제");
	printf("\n\t3 : 검색");
	printf("\n\t4 : 출력");
	printf("\n\t5 : 종료");
	printf("\n*---------------------------*\n");
}

void main()
{
	char choice;
	element e;
	treeNode *root=NULL, *temp;

	do{
		menu();
		choice = getchar();  getchar();

		switch(choice-'0')
		{
		case 1 :		
			printf("\n[단어 입력] 단어를 입력하세요 : ");		gets(e.word);
			printf("\n[단어 입력] 단어 뜻을 입력하세요 : ");	gets(e.mean);
			insert(&root, e);
			break;
		case 2 :		
			printf("\n[단어 삭제] 삭제할 단어 : ");  gets(e.word);
			deleteNode(root, e);
			break;
		case 3 :			
			printf("\n[단어 검색] 검색할 단어 : ");  gets(e.word);
			
			temp=searchBST(root, e);
			if(temp != NULL)
				printf("\n단어 뜻 : %s", temp->key.mean);
			else printf("\n사전에 없는 단어입니다.");
			break;
		case 4 :
			printf("\t[사전 출력]");
			inorderDisplay(root); printf("\n\t[사전 끝]\n");
			break;
		}
	}while((choice-'0') != 5);
}
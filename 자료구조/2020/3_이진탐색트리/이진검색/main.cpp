#include "std.h"

void menu()
{
	printf("\n*---------------------------*");
	printf("\n\t1 : �Է�");
	printf("\n\t2 : ����");
	printf("\n\t3 : �˻�");
	printf("\n\t4 : ���");
	printf("\n\t5 : ����");
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
			printf("\n[�ܾ� �Է�] �ܾ �Է��ϼ��� : ");		gets(e.word);
			printf("\n[�ܾ� �Է�] �ܾ� ���� �Է��ϼ��� : ");	gets(e.mean);
			insert(&root, e);
			break;
		case 2 :		
			printf("\n[�ܾ� ����] ������ �ܾ� : ");  gets(e.word);
			deleteNode(root, e);
			break;
		case 3 :			
			printf("\n[�ܾ� �˻�] �˻��� �ܾ� : ");  gets(e.word);
			
			temp=searchBST(root, e);
			if(temp != NULL)
				printf("\n�ܾ� �� : %s", temp->key.mean);
			else printf("\n������ ���� �ܾ��Դϴ�.");
			break;
		case 4 :
			printf("\t[���� ���]");
			inorderDisplay(root); printf("\n\t[���� ��]\n");
			break;
		}
	}while((choice-'0') != 5);
}
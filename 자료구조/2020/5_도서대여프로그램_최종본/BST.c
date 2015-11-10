#include "std.h"


void fnBookInput()
{
	BOOK	book;
	fflush(stdin);
	printf("å�̸� : ");
	gets(book.name);
	book.rentperson	= NULL;

	insert(&root, book);
}

void insert(treeNode** root, BOOK key) 
{ 
	*root = insertKey(*root, key); 
} 


treeNode* insertKey(treeNode *p, BOOK key) 
{ 
	treeNode *newNode;   
	int compare;	
	if (p == NULL) 
	{ 
        	newNode = (treeNode*)malloc(sizeof(treeNode)); 
			newNode->key = key; 
			newNode->left = NULL; 
			newNode->right = NULL; 
			return newNode; 
	} 
	else 
	{ 
		compare = strcmp(key.name, p->key.name);
		if(compare < 0) {
			p->left = insertKey(p->left, key);
			return p; 
		}
		else if(compare > 0){
			p->right = insertKey(p->right, key); 
			return p; 
		}
		else {
			printf("\n �̹� ���� �ܾ �ֽ��ϴ�! \n"); 
			return p; 
		} 
	}
} 


void fnBookPrint()
{
	if( root == NULL)
	{
		printf("�������� å�� �����ϴ�.\n");
		return;
	}
	printf("�� [å �� ��] \n");
	inorderDisplay(root);
}


void inorderDisplay(treeNode* root)
{
	if(root)
	{		
		inorderDisplay(root->left);
		printf("   ��    �� : %s\n", root->key.name);
		if( root->key.rentperson )
		{
			printf("  �� �� �� : %s\n", 
				root->key.rentperson->name);
		}

		inorderDisplay(root->right);
	}
}

void fnBookPrint1()
{
	if( root == NULL)
	{
		printf("�������� å�� �����ϴ�.\n");
		return;
	}
	printf("�� [å �� ��] \n");
	inorderDisplay1(root);
}

void inorderDisplay1(treeNode* root)
{
	if(root)
	{		
		inorderDisplay1(root->left);
		printf("   ��    �� : %s", root->key.name);
		if( !root->key.rentperson )
		{
			printf(" �뿩����\n");    
		}
		else
		{
			printf(" �뿩�Ұ�\n");
		}

		inorderDisplay1(root->right);
	}
}

treeNode* searchBST(treeNode* root, char*name) 
{    
	treeNode* p;   int compare;
	p = root; 
	while (p != NULL)
	{ 
		compare = strcmp(name, p->key.name);
		if(compare < 0) 
		{
			p = p->left; 
		}
		else if(compare > 0) 
		{
			p = p->right; 
		}
		else 
		{
			return p; 
		}
	}
	return p; 	 
} 

void fnBookSearch()
{
	char name[20];
	treeNode* cur;
	printf("�˻��� ������ �Է� : ");
	gets(name);
	cur = searchBST(root, name);
	if( cur )
	{
		printf("��    �� : %s\n", cur->key.name);
		if( cur->key.rentperson )
		{
			printf("  �� �� �� : %s\n", 
				cur->key.rentperson->name);
		}
		else
		{
			printf("    �뿩 �����մϴ�.\n");
		}
	}
}

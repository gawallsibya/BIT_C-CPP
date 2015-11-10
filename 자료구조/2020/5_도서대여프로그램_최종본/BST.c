#include "std.h"


void fnBookInput()
{
	BOOK	book;
	fflush(stdin);
	printf("책이름 : ");
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
			printf("\n 이미 같은 단어가 있습니다! \n"); 
			return p; 
		} 
	}
} 


void fnBookPrint()
{
	if( root == NULL)
	{
		printf("도서관에 책이 없습니다.\n");
		return;
	}
	printf("● [책 목 록] \n");
	inorderDisplay(root);
}


void inorderDisplay(treeNode* root)
{
	if(root)
	{		
		inorderDisplay(root->left);
		printf("   제    목 : %s\n", root->key.name);
		if( root->key.rentperson )
		{
			printf("  대 여 자 : %s\n", 
				root->key.rentperson->name);
		}

		inorderDisplay(root->right);
	}
}

void fnBookPrint1()
{
	if( root == NULL)
	{
		printf("도서관에 책이 없습니다.\n");
		return;
	}
	printf("● [책 목 록] \n");
	inorderDisplay1(root);
}

void inorderDisplay1(treeNode* root)
{
	if(root)
	{		
		inorderDisplay1(root->left);
		printf("   제    목 : %s", root->key.name);
		if( !root->key.rentperson )
		{
			printf(" 대여가능\n");    
		}
		else
		{
			printf(" 대여불가\n");
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
	printf("검색할 도서명 입력 : ");
	gets(name);
	cur = searchBST(root, name);
	if( cur )
	{
		printf("제    목 : %s\n", cur->key.name);
		if( cur->key.rentperson )
		{
			printf("  대 여 자 : %s\n", 
				cur->key.rentperson->name);
		}
		else
		{
			printf("    대여 가능합니다.\n");
		}
	}
}

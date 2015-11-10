//----------------------------------------------------------------
// [ TREE Sample 작성 ]
//----------------------------------------------------------------
//  삽입기능 + 탐색 기능  
//----------------------------------------------------------------


#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef struct _tree
{
	int key;
	struct _tree *left;
	struct _tree *right;
}TREE;


// 보조 함수 
int   input_num(void);
void  end(void);
void  PressEnter(void);


// 주 함수 
TREE *create_tree(int k);
void insert(int, TREE **);
void preorder(TREE *);
void inorder(TREE *);



void main()
{
	char ch;
	int key;
	TREE *root = NULL;
	while(1)
	{
		system("cls");
		puts("... MENU...");
		puts("1. INPUT");
		puts("2. Preorder");
		puts("3. Inorder");
		puts("4. EXIT");
		printf("choice number : [ ]\b\b");
		switch( ch = getche())
		{
		case '1' : key = input_num();	insert(key, &root); break;
		case '2' : printf("\n\n"); preorder(root); PressEnter();break;
		case '3' : printf("\n\n"); inorder(root); PressEnter();break;
		case '4' : end();
		}
	}
}


TREE *create_tree(int k)
{
	TREE *new1;

	new1 = (TREE*)malloc(sizeof(new1));
	new1->key = k;
	new1->left	= NULL;
	new1->right	= NULL;
	return new1;
}

int input_num(void)
{
	int num  = 0;
	printf("\nINPUT NUMBER : ");
	scanf("%d", &num);
	return num;
}


void insert(int k, TREE **root)
{
	TREE *new1;
	new1 = create_tree(k);
	if( *root == NULL)
	{
		*root = new1;
		return;
	}
	if( (*root)->key > k)
	{
		if( (*root)->left == NULL)
		{
			(*root)->left = new1;
			return;
		}
		else
			insert(k, &(*root)->left);
	}
	else
	{
		if( (*root)->right	== NULL)
		{
			(*root)->right = new1;
			return;
		}
		else
			insert(k, &(*root)->right);
	}
}


void preorder(TREE * cur)
{
	printf("%d " , cur->key);
	if( cur->left != NULL)
		preorder(cur->left);
	if(cur->right != NULL)
		preorder(cur->right);
}

void inorder(TREE * cur)
{
	if( cur->left != NULL)
		inorder(cur->left);
	printf("%d " ,cur->key);
	if(cur->right != NULL)
		inorder(cur->right);
}


void end(void)
{
	system("cls");
	printf("\tThank you...\n");
	printf("\n\tGood bye...\n");
	exit(0);
}

void PressEnter(void)
{
	char cc;
	printf("\n\nContinue Press Enter...");
	cc = getchar();
}


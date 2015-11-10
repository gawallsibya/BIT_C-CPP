// caltree.c
#include "std.h"

void init_stack()
{
	top = -1;
}
void init_tree()
{
	root = (TREE*)malloc(sizeof(TREE));
	root->left	= NULL;
	root->right	= NULL;
}

TREE *make_parse_tree(char *data )
{
	TREE *t;
	while(*data)
	{
		while( *data == ' ')
			data++;
		t = (TREE*)malloc(sizeof(TREE));
		t->key	 = *data;
		t->left	 = NULL;
		t->right = NULL;
		if( is_operator(*data))
		{
			t->right	= pop();
			t->left		= pop();
		}
		push(t);
		data++;
	}
	return pop();
}


int is_operator(int k)
{
	return ( k == '+' || k == '-' || k == '*' || k == '/');
}

TREE *push(TREE *t)
{
	if (top >= MAX-1)
	{
		printf("\nStack Overflow");
		return NULL;
	}
	stack[++top] = t;
	return t;
}

TREE *pop(void)
{
	if(top < 0)
	{
		printf("\n Stack Underflow");
		return NULL;
	}
	return stack[top--];
}

void preorder(TREE *cur)
{
	printf("%3c", cur->key);
	if( cur->left != NULL)
		preorder(cur->left);
	if( cur->right != NULL)
		preorder(cur->right);
}

void inorder(TREE* cur)
{
	if( cur->left != NULL)
		inorder(cur->left);
	printf("%3c", cur->key);
	if( cur->right != NULL)
		inorder(cur->right);
}

void postorder(TREE *cur)
{
	if( cur->left != NULL)
		postorder(cur->left);
	if( cur->right != NULL)
		postorder(cur->right);
	printf("%3c", cur->key);

}
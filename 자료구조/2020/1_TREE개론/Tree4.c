//-------------------------------------------------------
// [ Sample 1 ]
//   이진트리 순회 
//-------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>


typedef struct treeNode
{
	char data;
	struct treeNode *left;
	struct treeNode *right;
} treeNode;


// 1. 노드의 생성 및 연결  
treeNode* makeRootNode(char data, treeNode* leftNode, treeNode* rightNode)
{
	treeNode* root = (treeNode *)malloc(sizeof(treeNode));
	root->data = data;
	root->left = leftNode;
	root->right = rightNode;
	return root;
}


// 2. 전위 
preorder(treeNode* root)
{
	if(root){
		printf("%c", root->data);
		preorder(root->left);
		preorder(root->right);
	}
}


// 3. 중위 
inorder(treeNode* root)
{
	if(root){		
		inorder(root->left);
		printf("%c", root->data);
		inorder(root->right);
	}
}

// 4. 후위 
postorder(treeNode* root)
{
	if(root){		
		postorder(root->left);		
		postorder(root->right);
		printf("%c", root->data);
	}
}



void main()
{
	treeNode* n7 = makeRootNode('D', NULL, NULL);
	treeNode* n6 = makeRootNode('C', NULL, NULL);
	treeNode* n5 = makeRootNode('B', NULL, NULL);
	treeNode* n4 = makeRootNode('A', NULL, NULL);
	treeNode* n3 = makeRootNode('/', n6, n7);
	treeNode* n2 = makeRootNode('*', n4, n5);
	treeNode* n1 = makeRootNode('-', n2, n3);

	printf("\n preorder  : ");
	preorder(n1);
	
	printf("\n inorder   : ");
	inorder(n1);
	
	printf("\n postorder : ");
	postorder(n1);

	getchar();
}
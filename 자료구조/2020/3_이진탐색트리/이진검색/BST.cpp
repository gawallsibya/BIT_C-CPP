#include "std.h"

treeNode* searchBST(treeNode* root, element key) 
{    
	treeNode* p;   int compare;
	p = root; 
	// printf("\nã�� �ܾ� : %s", key.word);
	// printf("\n����ܾ� : %s", p->key.word);
	while (p != NULL)
	{ 
		compare = strcmp(key.word, p->key.word);
		if(compare < 0) 
		{
			p = p->left; 
			// printf("\n�˻� �� ���ʴܾ� : %s", p->key.word);
		}
		else if(compare > 0) 
		{
			p = p->right; 
			// printf("\n�˻� �� ������ �ܾ� : %s", p->key.word);
		}
		else 
		{
			printf("\nã�� �ܾ� : %s", p->key.word); 
			return p; 
		}
	}
	return p; 	 
} 


treeNode* insertKey(treeNode *p, element key) 
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
		compare = strcmp(key.word, p->key.word);
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


void insert(treeNode** root, element key) 
{ 
	*root = insertKey(*root, key); 
} 


void deleteNode(treeNode *root, element key)
{
	treeNode *parent, *p, *succ, *succ_parent;
	treeNode *child;

	parent=NULL;
	p=root; 
	while((p != NULL) && (strcmp(p->key.word, key.word)!=0)){
		parent=p;
		if(strcmp(key.word, p->key.word)<0)
			p=p->left;
		else p=p->right;
	}
	if(p == NULL)
	{
		printf("\n ã�� Ű�� ����Ʈ���� �����ϴ�!!");
		return;
	}

	// �ܸ������ ����
	if((p->left == NULL) && (p->right == NULL)){
		if(parent != NULL){
			if(parent->left == p) parent->left=NULL;
			else parent->right=NULL;
		}
		else root=NULL;
	}

	// �ڽĳ�尡 �� ���� ����� ����
	else if((p->left == NULL) || (p->right == NULL)){
		if(p->left != NULL) child=p->left;
		else child=p->right;
		if(parent != NULL){
			if(parent->left == p) parent->left=child;
			else parent->right=child;
		}
		else root=child;
	}

	// �ڽĳ�尡 �� ���� ����� ����
	else{
		succ_parent=p;
		succ=p->right;
		while(succ->left != NULL){
			succ_parent=succ;
			succ=succ->left;
		}
		if(succ_parent->left == succ) 
			succ_parent->left=succ->right;
		else succ_parent->right=succ->right;
		p->key=succ->key;
		p=succ;
	} 
	free(p);
}




void inorderDisplay(treeNode* root)
{
	if(root){		
		inorderDisplay(root->left);
		printf("\n%s : %s", root->key.word, root->key.mean);
		inorderDisplay(root->right);
	}
}
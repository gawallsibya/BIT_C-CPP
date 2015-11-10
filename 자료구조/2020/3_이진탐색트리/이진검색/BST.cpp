#include "std.h"

treeNode* searchBST(treeNode* root, element key) 
{    
	treeNode* p;   int compare;
	p = root; 
	// printf("\n찾을 단어 : %s", key.word);
	// printf("\n현재단어 : %s", p->key.word);
	while (p != NULL)
	{ 
		compare = strcmp(key.word, p->key.word);
		if(compare < 0) 
		{
			p = p->left; 
			// printf("\n검색 중 왼쪽단어 : %s", p->key.word);
		}
		else if(compare > 0) 
		{
			p = p->right; 
			// printf("\n검색 중 오른쪽 단어 : %s", p->key.word);
		}
		else 
		{
			printf("\n찾은 단어 : %s", p->key.word); 
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
			printf("\n 이미 같은 단어가 있습니다! \n"); 
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
		printf("\n 찾는 키가 이진트리에 없습니다!!");
		return;
	}

	// 단말노드의 삭제
	if((p->left == NULL) && (p->right == NULL)){
		if(parent != NULL){
			if(parent->left == p) parent->left=NULL;
			else parent->right=NULL;
		}
		else root=NULL;
	}

	// 자식노드가 한 개인 노드의 삭제
	else if((p->left == NULL) || (p->right == NULL)){
		if(p->left != NULL) child=p->left;
		else child=p->right;
		if(parent != NULL){
			if(parent->left == p) parent->left=child;
			else parent->right=child;
		}
		else root=child;
	}

	// 자식노드가 두 개인 노드의 삭제
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
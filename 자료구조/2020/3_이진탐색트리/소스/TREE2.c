// ----------------------------------------------------------
// [ Sample 1 ]
//------------------------------------------------------------

#include<stdio.h> 
#include<stdlib.h> 


typedef struct treeNode
{
	char key; 
	struct treeNode* left; 
	struct treeNode* right; 
} treeNode; 


treeNode* insertKey(treeNode *p, char x) 
{ 
	  treeNode *newNode;	
	  if (p == NULL)	 
	  { 
            newNode = (treeNode*)malloc(sizeof(treeNode)); 
			newNode->key = x; 
			newNode->left = NULL; 
			newNode->right = NULL; 
			return newNode; 
	 } 
	 else if (x < p->key) {
			p->left = insertKey(p->left, x);
            		return p;
     }
	 else if (x > p->key) {	
			p->right = insertKey(p->right, x); 
			return p;
	 } 
	 else {		
			printf("\n �̹� ���� Ű�� �ֽ��ϴ�! \n"); 
			return p;	 
	 }
} 


void insert(treeNode** root, char x) 
{ 
	*root = insertKey(*root, x); 
} 


treeNode* searchBST(treeNode* root, char x) 
{    
	 treeNode* p; 
	 p = root; 
	 while (p != NULL)
	 { 
		if (x < p->key) 
		{ 
			p = p->left; 
		} 
		else if (x == p->key)
		{		  
			return p; 
		} 
		else p = p->right; 
	 } 
	printf("\n ã�� Ű�� �����ϴ�! \n");	 
	return p; 
} 



int main() 
{	 
	treeNode* root = NULL;	  
	treeNode* foundedNode = NULL; 
	char key;	       

	// ������ �Է� 
	insert(&root, 'A');			insert(&root, 'B'); 
	insert(&root, 'D');			insert(&root, 'E'); 
	insert(&root, 'G');			insert(&root, 'H'); 
	insert(&root, 'I');			insert(&root, 'J'); 
	insert(&root, 'M');		   	insert(&root, 'N'); 
	insert(&root, 'Q'); 

	
	printf("\nã�� ���ڸ� �Է��ϼ���! : "); 
	scanf("%c", &key);
	while(key != 'z'){
		foundedNode = searchBST(root, key); 
		if (foundedNode != NULL) 
		{ 
			  printf("\n %c Ű�� ã�ҽ��ϴ�! \n", foundedNode->key); 
		} 
		else { 
			  printf("\n Ű�� ã�� ���߽��ϴ�. \n"); 
		}
		scanf("%c", &key);
	
		printf("\n\n\n ã�� ���ڸ� �Է��ϼ���! : "); 
		scanf("%c", &key);
    }	     
	getchar();	
	return 0; 
} 
// BST.h

void fnBookInput();
void insert(treeNode** root, BOOK key);
treeNode* insertKey(treeNode *p, BOOK key) ;

void fnBookPrint();
void fnBookPrint1();
void inorderDisplay(treeNode* root);
void inorderDisplay1(treeNode* root);

treeNode* searchBST(treeNode* root, char *name) ;

void fnBookSearch();

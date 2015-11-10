// caltree.h

// 나무의 노드 
typedef struct _tree
{
	int key;
	struct _tree *left;
	struct _tree *right;
}TREE;


#define MAX 100

// 저장 공간 
TREE *stack[MAX];

// 스택의 위치 
int top;

// TREE 뿌리 
TREE *root;


// 스택의 위치를 -1로 초기화 
void init_stack();

// 나무 구조의 초기화 
// 메모리 할당 및 포인터 NULL로 초기화 
void init_tree();


// 후위표기법 수식에서  수식 나무 구성 
TREE *make_parse_tree(char * data);


// k가 연산자이면 참 비연산자이면 거짓을 리턴 
int is_operator(int k);

// 스택에 푸시 
TREE *push(TREE *t);


// 스택에서 팝 
TREE *pop(void);


void preorder(TREE *cur);

void inorder(TREE* cur);
void postorder(TREE* cur);

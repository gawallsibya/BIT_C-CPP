// caltree.h

// ������ ��� 
typedef struct _tree
{
	int key;
	struct _tree *left;
	struct _tree *right;
}TREE;


#define MAX 100

// ���� ���� 
TREE *stack[MAX];

// ������ ��ġ 
int top;

// TREE �Ѹ� 
TREE *root;


// ������ ��ġ�� -1�� �ʱ�ȭ 
void init_stack();

// ���� ������ �ʱ�ȭ 
// �޸� �Ҵ� �� ������ NULL�� �ʱ�ȭ 
void init_tree();


// ����ǥ��� ���Ŀ���  ���� ���� ���� 
TREE *make_parse_tree(char * data);


// k�� �������̸� �� �񿬻����̸� ������ ���� 
int is_operator(int k);

// ���ÿ� Ǫ�� 
TREE *push(TREE *t);


// ���ÿ��� �� 
TREE *pop(void);


void preorder(TREE *cur);

void inorder(TREE* cur);
void postorder(TREE* cur);

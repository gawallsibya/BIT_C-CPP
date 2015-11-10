// data.h

#define PERSONNAME 20
#define RENTALNUM	3
#define BOOKNAME   30


typedef struct tagPerson PERSON_NODE;
typedef struct tagBook	 BOOK;



// 1. ȸ�� ������ ������ ����ü (���� ���Ḯ��Ʈ )

struct tagPerson
{
	char	name[PERSONNAME];			// ȸ�� �̸�
	int		number;						// ȸ�� ��ȭ��ȣ  

	BOOK	*rentbook[RENTALNUM];		// ���� �뿩 ���
	int		rentcount;					// ���� �뿩 ����( 0 ~ 3 )

	struct tagPerson	*next;			// ���� ��� 
};

typedef struct tagList LIST;
struct tagList
{
	PERSON_NODE	*head;
	int			count;
};




// 2. ���� ������ ������ ����ü 

struct tagBook
{
	char	name[BOOKNAME];			// ���� ���� 

	PERSON_NODE *rentperson;		// �뿩�ذ� ��� 
};

typedef struct treeNode
{
	BOOK key;
	struct treeNode *left;
	struct treeNode *right;
} treeNode;



// ���� IO-----------------------
#define FILE_LENGTH		20
#define FILENAME		"data.txt";
extern char	fileName[FILE_LENGTH];



extern LIST	list;
extern treeNode *root;
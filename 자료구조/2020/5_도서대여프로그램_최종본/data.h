// data.h

#define PERSONNAME 20
#define RENTALNUM	3
#define BOOKNAME   30


typedef struct tagPerson PERSON_NODE;
typedef struct tagBook	 BOOK;



// 1. 회원 정보를 저장할 구조체 (단일 연결리스트 )

struct tagPerson
{
	char	name[PERSONNAME];			// 회원 이름
	int		number;						// 회원 전화번호  

	BOOK	*rentbook[RENTALNUM];		// 도서 대여 목록
	int		rentcount;					// 도서 대여 갯수( 0 ~ 3 )

	struct tagPerson	*next;			// 다음 노드 
};

typedef struct tagList LIST;
struct tagList
{
	PERSON_NODE	*head;
	int			count;
};




// 2. 도서 정보를 저장할 구조체 

struct tagBook
{
	char	name[BOOKNAME];			// 도서 제목 

	PERSON_NODE *rentperson;		// 대여해간 사람 
};

typedef struct treeNode
{
	BOOK key;
	struct treeNode *left;
	struct treeNode *right;
} treeNode;



// 파일 IO-----------------------
#define FILE_LENGTH		20
#define FILENAME		"data.txt";
extern char	fileName[FILE_LENGTH];



extern LIST	list;
extern treeNode *root;
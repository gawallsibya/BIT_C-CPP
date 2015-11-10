// data.h

#define MAX_WORD_LENGTH 20
#define MAX_MEAN_LENGTH 200

typedef struct 
{
	char word[MAX_WORD_LENGTH];
	char mean[MAX_MEAN_LENGTH];
} element;


typedef struct treeNode
{
	element key;
	struct treeNode *left;
	struct treeNode *right;
} treeNode;
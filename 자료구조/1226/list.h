//list.h

typedef struct tagNode Node;
struct tagNode
{
	Member* data;
	Node* next;
};

typedef struct tagList List;
struct tagList
{
	Node* head;
	int ncount;
};

void init_list(List* plist);
void list_insert(List* plist,Member* data);
void list_print(Member* plist);
Member* list_search(List* plist, char* ch);
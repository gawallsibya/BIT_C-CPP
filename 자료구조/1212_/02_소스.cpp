#include <stdio.h>
#include <malloc.h>

//=========================================================
typedef struct tagNODE NODE;
struct tagNODE
{
	int data;
	struct tagNODE *next;
	struct tagNODE *prev;
};

typedef struct tagDLIST DLIST;
struct tagDLIST
{
	NODE *head;
	NODE *tail;
	int  count;	
};
//========================================================


void init(DLIST *pdlist)
{
	pdlist->head	= NULL;
	pdlist->tail	= NULL;
	pdlist->count	= 0;
}


void push_front(DLIST *pdlist, int data)
{

	//1. NODE 생성 초기화
	NODE *newnode	= (NODE*)malloc(sizeof(NODE));
	newnode->data	= data;
	newnode->next	= NULL;
	newnode->prev   = NULL;		//<================

	if( pdlist->head == NULL)
	{
		pdlist->head = newnode;
		pdlist->tail = newnode;
		pdlist->count++;
	}
	else
	{
		//2.1 연결 
		newnode->next		= pdlist->head;
		pdlist->head->prev  = newnode;
		pdlist->head		= newnode;
		pdlist->count++;
	}	
}


void push_back(DLIST *pdlist, int data)
{
	NODE *newnode	= (NODE*)malloc(sizeof(NODE));
	newnode->data	= data;
	newnode->next   = NULL;
	newnode->prev   = NULL;

	if( pdlist->head == NULL)
	{
		pdlist->head = newnode;
		pdlist->tail = newnode;
		pdlist->count++;
	}
	else
	{
		newnode->prev		= pdlist->tail;
		pdlist->tail->next	= newnode;
		pdlist->tail		= newnode;
		pdlist->count++;
	}
}


void printall(const DLIST *plist)
{
	NODE *cur = plist->head;
	while(cur != NULL)
	{
		printf("%d\t", cur->data);
		cur = cur->next;
	}	
}

NODE *IntToNode(NODE* start, int data)
{
	NODE *cur = start;
	while( cur != NULL)
	{
		if( cur->data == data)
			return cur;
		cur = cur->next;
	}
	return NULL;
}


void search(DLIST *pdlist, int data)
{
	NODE *cur = IntToNode(pdlist->head, data);
	if( cur != NULL)
	{
		printf("찾았다. : %d\n", cur->data);
	}
	else
	{
		printf("못찾았다...\n");
	}
}


void update(DLIST *pdlist, int data, int newdata)
{

	NODE *cur = IntToNode(pdlist->head, data);
	if( cur == NULL)
	{
		printf("못찾았따...\n");
	}
	else
	{
		cur->data	= newdata;
	}

}

void dele(DLIST *pdlist, int data)
{
	NODE *cur = IntToNode(pdlist->head, data);
	if( cur == NULL)
	{
		printf("못찾았따...\n");
	}
	else
	{
		NODE *del, *prev;
		del		= cur;
		prev	= cur->prev;

		if( cur == pdlist->head)
		{
			pdlist->head = cur->next;
		}
		else if( cur == pdlist->tail)
		{
			prev->next		= NULL;
			pdlist->tail	= prev;
		}
		else
		{
		prev->next		= del->next;
		del->next->prev	= prev;
		}

		free(del);
		pdlist->count--;
	}
}

// 입력, 출력 
void main()
{
	DLIST dlist;

	init(&dlist);

	int i;
	for(i=0; i<5; i++)
	{
//		push_front(&dlist, i+1);		
		push_back(&dlist, i+1);
	}

	printall(&dlist);


//	search(&dlist, 3);

//	printf("\n");
//	update(&dlist, 1, 11);		printall(&dlist);

	printf("\n");
	dele(&dlist, 5);

	printall(&dlist);
}
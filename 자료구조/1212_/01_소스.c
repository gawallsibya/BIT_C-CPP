#include <stdio.h>
#include <malloc.h>

typedef struct tagNODE NODE;
struct tagNODE
{
	int data;
	struct tagNODE *next;
};

int arr[10];		// 10���� ������ ������ �� �ִ� ���� 
int idx	= 0;

NODE *start;

void insert(int *parr, NODE **start, int data)
{
	arr[idx++] = data;
	
	{
	//1. NODE ���� �ʱ�ȭ
	NODE *newnode	= (NODE*)malloc(sizeof(NODE));
	newnode->data	= data;
	newnode->next	= NULL;

	//2. ���� front-insert,
	/*
	if( *start == NULL)
	{
		*start		= newnode;
	}
	else
	{
		//2.1 ���� 
		newnode->next	= *start;
		*start		= newnode;
	}
	*/
	//3. ���� back-insert
	if( *start == NULL)
	{
		*start		= newnode;
	}
	else
	{
		NODE *cur = *start;
		while( cur->next != NULL)
		{
			cur = cur->next;
		}
		cur->next = newnode;
	}
	}
	
}

void printall(int *arr, NODE *start)
{
	int i;
	for(i=0; i<10; i++)
	{
		printf("%d\t", arr[i]); 
	}
	printf("\n");

	{
		NODE *cur = start;
		while(cur != NULL)
		{
			printf("%d\t", cur->data);
			cur = cur->next;
		}
	}
}

NODE* search(int *arr, NODE *cur, int data)
{
	int i;
	for(i=0; i<10; i++)
	{
		if( arr[i] == data)
		{
			printf("ã�Ҵ�..: %d\n", arr[i]);
			goto ONE;
		}
	}
	printf("��ã�Ҵ�..\n");

ONE:
	{
		NODE *cur = start;
		while( cur != NULL)
		{
			if( cur->data == data)
			{
				printf("ã�Ҵ�...:%d\n", cur->data);
				return cur;
			}
			cur = cur->next;
		}
		printf("����Ʈ���� ��ã�Ҵ�..\n");
		return NULL;
	}
}

void update(int *arr, NODE **start, int data, int newdata)
{
	NODE *cur = search(arr, *start, data);
	if( cur == NULL)
	{
	}
	else
	{
		cur->data	= newdata;
	}
}

void dele(int *arr, NODE **start, int data)
{
	NODE *prev, *cur;
	prev = cur = *start;
	if( cur->data == data)
	{
		*start = cur->next;
		free(cur);
	}
	else
	{
		cur = cur->next;
		while( cur != NULL)
		{
			if( cur->data == data)
			{
				prev->next	= cur->next;
				free(cur);
				return;
			}
			else
			{
				cur = cur->next;
				prev = prev->next;
			}
		}
	}
}

// �Է�, ��� 
void main()
{
	int i;
	for(i=0; i<5; i++)
	{
		insert(arr, &start, i+1);		
	}
	printall(arr, start);

	search(arr, start, 1);
	
	update(arr, &start, 1, 11);

	dele(arr, &start, 3);

	printall(arr, start);
}
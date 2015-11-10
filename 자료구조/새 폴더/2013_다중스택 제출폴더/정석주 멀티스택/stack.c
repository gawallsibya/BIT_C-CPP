#include "stack.h"
#include "std.h"

stac st;

void stinit()
{
	st.dtop = -1;
	st.utop = MAX;
}

void push_down()
{	
	int num;

	printf("���ڸ� �Է��ϼ��� : ");  scanf("%d", &num);	
	if(st.dtop+1 == st.utop) 
	{
		printf("Overflow\n");
	}
	else
	{
		st.arr[st.dtop+1] = num;		
		st.dtop++;
	}
}

void push_up()
{
	int num;

	printf("���ڸ� �Է��ϼ��� : ");  scanf("%d", &num);
	if(st.dtop+1 == st.utop)
	{
		printf("Overflow\n");
	}
	else
	{
		st.arr[--st.utop] = num;
	}	
}

void pop_down()
{
	if(st.dtop < 0)
	{
		printf("Underflow\n");
	}
	else
	{
		st.arr[st.dtop--];
	}
}

void pop_up()
{
	if(st.utop >= MAX)
	{
		printf("Underflow\n");
	}
	else
	{
		st.arr[st.utop++];
	}
}



void printall()
{
	int i;
	printf("�Էµ� ���ڴ� : ");
	
	for(i=0; i<MAX; i++)
	{
		printf("%d\n", st.arr[i]);
	}

}
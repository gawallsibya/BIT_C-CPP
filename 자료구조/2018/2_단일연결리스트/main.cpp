#include "List.h"

typedef struct _DATA DATA;

struct _DATA
{
	char name[20];
	int  number; 
};

void print( DATA data)
{
	cout << data.number << " : " << data.name << endl;
}
void print_all(list<DATA> s)
{
	if( s.get_first_position == 0 )
		cout << "데이터가 없습니다" << endl;
	else
	{
		list<DATA>::Node *cur = s.get_first_position();
		while( s.get_next_position( cur ))
		{
			print( s.get_data(cur) );   
			cur = cur->next;
		}
		print(s.get_data(cur) ); 
	}
}


/*
void main()
{
	list<DATA> s;
}
*/

void main()
{
	list<DATA*> s1;
}
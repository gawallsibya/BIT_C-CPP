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


void main()
{
	list<DATA> s;

	DATA  temp;

	strcpy(temp.name, "1빠");		temp.number = 1;
	s.push_front(temp);

	strcpy(temp.name, "2빠");		temp.number = 2;
	s.push_front(temp);

	strcpy(temp.name, "3빠");		temp.number = 3;
	s.push_front(temp);


	cout << "첫번째 노드 출력 : " ;
	list<DATA>::POSITION first = s.get_first_position();
	print( s.get_data( first ) );
	
	

	cout << "출력 :" << endl; 
	print_all(s);

	cout << "첫번째 노드 삭제 : ";
	print( s.pop_front() ) ;

	cout << "삭제후 출력 : " << endl; 
	print_all(s);

}
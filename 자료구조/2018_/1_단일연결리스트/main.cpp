#include "List.h"


void print_all(list<int> s)
{
	if( s.get_first_position() == 0 )
		cout << "데이터가 없습니다" << endl;
	else
	{
		list<int>::POSITION cur = s.get_first_position();
//		while( s.get_next_position( cur ))
		while(cur)
		{
			cout << s.get_data(cur)  << endl; 
			//cur = cur->next;
			cur = s.get_next_position(cur);
		}
	}
}

list<int>::POSITION search_data(list<int> s, int data)
{
	if( s.get_first_position() == 0 )
		cout << "데이터가 없습니다" << endl;
	else
	{
		list<int>::POSITION cur = s.get_first_position();
//		while( s.get_next_position( cur ))
		while(cur)
		{
			cout << s.get_data(cur)  << endl; 
			//cur = cur->next;
			cur = s.get_next_position(cur);
		}
	}
}



void main()
{
	list<int> s; // 이제 list는 template의 이름이다.
				 // type의 이름은 list<int> 라는 방식으로 사용해야 한다.
	s.push_front(10);		//head ->30 -> 20 ->10
	s.push_front(20);
	s.push_front(30);

	cout << "첫번째 노드 출력 : " ;
	list<int>::POSITION first = s.get_first_position();
	int num =  s.get_data( first );
	cout << num <<endl; 
	
	cout << "출력 :" << endl; 
	print_all(s);

	cout << "데이터 검색" << endl;
	search_data(s, 30);
/*
	cout << "첫번째 노드 삭제 : ";
	cout << s.pop_front() << endl; 

	cout << "삭제후 출력 : " << endl; 
	print_all(s);
*/
}
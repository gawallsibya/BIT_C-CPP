#include "List.h"


void print_all(list<int> s)
{
	if( s.get_first_position() == 0 )
		cout << "�����Ͱ� �����ϴ�" << endl;
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
		cout << "�����Ͱ� �����ϴ�" << endl;
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
	list<int> s; // ���� list�� template�� �̸��̴�.
				 // type�� �̸��� list<int> ��� ������� ����ؾ� �Ѵ�.
	s.push_front(10);		//head ->30 -> 20 ->10
	s.push_front(20);
	s.push_front(30);

	cout << "ù��° ��� ��� : " ;
	list<int>::POSITION first = s.get_first_position();
	int num =  s.get_data( first );
	cout << num <<endl; 
	
	cout << "��� :" << endl; 
	print_all(s);

	cout << "������ �˻�" << endl;
	search_data(s, 30);
/*
	cout << "ù��° ��� ���� : ";
	cout << s.pop_front() << endl; 

	cout << "������ ��� : " << endl; 
	print_all(s);
*/
}
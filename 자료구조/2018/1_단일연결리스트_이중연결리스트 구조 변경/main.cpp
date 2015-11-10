#include "List.h"


void print_all(list<int> s)
{
	if( s.get_first_position() == 0 )
		cout << "데이터가 없습니다" << endl;
	else
	{
		list<int>::POSITION cur = s.get_first_position();
		while(cur)
		{
			cout << s.get_data(cur)  << endl; 
			cur = s.get_next_position(cur);
		}
	}
}


list<int>::POSITION search_data(list<int> s, int data)
{
	if( s.get_first_position() == 0 )
	{
		return NULL;
	}
	else
	{
		list<int>::POSITION cur = s.get_first_position();
		while(cur)
		{
			int num = s.get_data(cur);
			//================================
			if( num == data)
				return cur;

			//================================
			cur = s.get_next_position(cur);
		}
		return NULL;
	}
}


void main()
{
	list<int> s; // 이제 list는 template의 이름이다.
				 // type의 이름은 list<int> 라는 방식으로 사용해야 한다.

	// 데이터 저장,=============================================
	int num;
	cout << "입력 : ";  cin >> num;
	s.push_front(num);		//head ->30 -> 20 ->10


	// 전체 데이터 출력 ========================================
	cout << "출력 :" << endl; 
	print_all(s);

	// 데이터 검색 ==============================================
	cout << "데이터 검색" << endl;
	list<int>::POSITION cur = search_data(s, 30);
	if( cur != NULL)
	{
		int num = s.get_data(cur);
		cout << num << endl; 
	}
	else
	{
		cout << "데이터가 없습니다" << endl;
	}

	// 데이터 삭제===============================================
	cout << "데이터 삭제" << endl; 
	list<int>::POSITION cur1 = search_data(s, 30);
	if( cur1 != NULL)
	{
		int data = s.erase(cur1);
		cout << data <<"를 삭제했습니다."<<endl;
	}
	else
	{
		cout << "데이터가 없습니다" << endl;
	}

	// 데이터 수정=================================
	cout << "데이터 수정" << endl; 
	list<int>::POSITION cur2 = search_data(s, 20);
	if( cur2 != NULL)
	{
		cur2->data	= 111;
		cout << "수정했습니다.."<<endl;
	}
	else
	{
		cout << "데이터가 없습니다" << endl;
	}

//	// 전체 데이터 출력 
	cout << "출력 :" << endl; 
	print_all(s);
}
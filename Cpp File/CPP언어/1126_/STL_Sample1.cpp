#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

struct A
{
	char		name[100];		// 이름
	int			number;			// 인덱스(번호)

	A()		{}
	A(int n) : number(n) {}
	//------------ 연산자 재정의 -----------------
	int operator < ( A & y)
	{
		return this->number < y.number;
	}
	bool operator == ( A * y)
	{
		return this->number == y->number;
	}
	//-----------------------------------------------
};


void main()
{
	// 생성..
	vector<A>		data;

	// 데이터 입력
	A		a1;		a1.number		= 1;		strcpy( a1.name, "이름1");
	data.push_back(a1);
	
	A		a2;		a2.number		= 2;		strcpy( a2.name, "이름2");
	data.push_back(a2);

	// 데이터 출력
	// 전체 출력
	for( int i=0; i < data.size(); i++)
	{
		cout << data[i].number << " : " << data[i].name << endl; 
	}

	// 1. 검색		: find 함수.
	A		bb(1);

	vector<A>::iterator		p	= find( data.begin(), data.end(), &bb);
	if( p == data.end())
		cout << "실패";
	else
		cout << "존재함" << endl; 


	// 3. 수정
	strcpy(p->name		, "바꾸어라");
	p->number		= 1000;

	// 2. 삭제
//	data.erase( p ); 
	// 전체 출력
	for(  i=0; i < data.size(); i++)
	{
		cout << data[i].number << " : " << data[i].name << endl; 
	}


}








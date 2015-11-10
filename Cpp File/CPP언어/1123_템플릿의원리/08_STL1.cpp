//〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓
//  [ 일반화 프로그래밍 ]
//〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓


/*
//─────────────────────────────────
// STL 은 일반화 프로그래밍(generic programming)의 한 예이다.
//─────────────────────────────────

  - 목 적 : 데이터형과 무관한 코드를 작성하는것 
  - 도 구 : 템플릿 

  - STL   : 알고리즘을 일반화된 표현으로 제공
            iterator를 통해 이부분을 가능케 한다.


//─────────────────────────────────
// iterator가 일반화된 STL을 구현하는데 필요한 이유
//─────────────────────────────────

  - iterator를 통해서 다양한 컨테이너를 동일한 알고리즘에 
    적용시킬 수 있게 구현가능해진다.
	=> 일반화의 필수이다.
*/


// 예)
#include <iostream.h>


//─────────────────────────────────
// 1. int type에 특정한 find 함수 구현 (배열)
//─────────────────────────────────
//  배열에서 값을 찾으면 발견된 주소를 리턴.
int *find_ar(int *ar, int n, const int & val)	
{
	for( int i=0; i< n; i++)
	{
		if(ar[i] == val)			
		return &ar[i];
	}
	return 0;
}

//  템플릿화 해보자...
template<typename T>
T *find_ar(T *ar, int n, const T & val)
{
	for( int i=0; i< n; i++)	
	{
		if(ar[i] == val)		
			return &ar[i];
	}
	return 0;
}


//─────────────────────────────────
// 2. int type에 특정한 find 함수 구현 (연결리스트)
//─────────────────────────────────
struct Node
{
	int		item;		
	Node	*next;	
};
Node* find_ll(Node* head, const int & val)
{
	Node *start;
	for( start = head; start != 0; start= start->next)
	{
		if( start->item == val)			
			return start;
	}
	return 0;
}	


//─────────────────────────────────
// 3. 배열과 연결리스트 비교
//─────────────────────────────────
서로 다른 알고리즘을 사용하고 있다. 
   차이점 : 배열은 : ++ 연산으로 증가, 연결리스트는 start->next 로 증가
   공통점 : 컨테이너에 들어있는 값들을 차례대로 이동하면서 비교 
   => 차이점을 공통점으로 변경시키는 과정이 일반화과정이다



//─────────────────────────────────
// 4. 배열 find 알고리즘 변경 I
//─────────────────────────────────
typedef int *iterator;
iterator find_ar1(iterator ar, int n, const int & val)
{
	for ( int i =0; i< n; i++, ar++)
		if( *ar == val)		
			return ar;	
		return 0;
}


//─────────────────────────────────
// 4. 배열 find 알고리즘 변경 II -> 범위 지정 전달인자로 변경
//─────────────────────────────────
typedef int *iterator;
iterator find_ar2(iterator begin, iterator end, const int & val)
{
	iterator ar;
	for ( ar = begin; ar != end; ar++)		
		if( *ar == val)	
			return ar;	
		return 0;
}


//─────────────────────────────────
// 5. 연결리스트  find 알고리즘 변경 I -> *과 ++ 연산자 재정의 필요
//─────────────────────────────────
class iterator1{
	Node *pt;	
public:
	iterator1() : pt(0) {}
	iterator1(Node *pn) : pt(pn) {}
	int operator*() { return pt->item;}
	iterator1 & operator++()			// ++ it를 위해	
	{
		pt = pt->next;		return *this;
	}
	iterator1  operator++(int)			// it++을 위해 //  참조자리턴은 안됨
	{
		iterator1 tmp = *this;	
		pt = pt->next;		
		return tmp;
	}
	iterator1 operator ==( const  iterator1 & rhs)
	{
		if( pt->item == rhs.pt->item)			
			return *this;
	}
	bool operator!=(const iterator1& i)
	{		
		return ( pt != i.pt);	
	}
};

iterator1 find_ll1(iterator1 head, const double & val)
{
	iterator1 start;
	for( start = head; start != 0; ++start)		
		if(*start == val)			
			return start;
	return 0;
}


//─────────────────────────────────
// 6. 연결리스트와 배열을 이용한 find알고리즘이 흡사해 졌다.
//    단 구간 반복적인 개념만 추가하면 된다.
//─────────────────────────────────

void main()
{
	// 배열을 find 알고리즘에 적용
	int vd[10] = { 0, 1,2,3,4,5,6,7,8,9};	
	cout << *find_ar(vd, 10, 3) << endl;

	// 연결리스트를 find 알고리즘에 적용
	Node *head = 0;
	for( int i=0;  i<10; i++)	
	{
		Node *p = new Node;	
		p->item	= i;
		p->next = head;	
		head = p;
	}
	Node *start;
	for( start = head; start != 0; start = start->next)
	{
		cout << start->item ;
	}
	cout << endl;	
	cout << find_ll(head, 3)->item << endl;
}

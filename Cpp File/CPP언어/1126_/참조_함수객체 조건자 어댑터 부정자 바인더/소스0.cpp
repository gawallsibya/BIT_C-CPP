//〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓
//  [  함수 1 ] 
//〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓

/*

//───────────────────────────────────────
    STL에서의 함수들
//───────────────────────────────────────
 STL의 3요소
 contanner class, algorithm function, 
 algorithm function  호출시 매개변수로 함수 포인터를 많이 씀
 파라미터 1개 => 단항함수
 파라미터 2개 => 이항함수
//───────────────────────────────────────
*/

#include <iostream>
#include <vector>			// vector
#include <algorithm>		// 알고리즘 함수
#include <string>			// string(STL)   String(C++), CString(MFC)
using namespace std;

// STL의 알고리즘 함수는 파라미터로 함수를 받는 경우가 많다.

//───────────────────────────────────────
//  ex1) 함수를 이용해 string에 저장된 문자열을 대문자로 출력해보자.
//───────────────────────────────────────
/*
void foo( char c )
{
	cout << (char)toupper(c) << endl; 
}
void main()
{
	string		s = "hello";		//STL 문자열 컨테이너 생성 ( 5byte )

	for_each( s.begin(), s.end(), foo);

}
*/



//───────────────────────────────────────
//  ex2) 단항 이항 함수를 이용한 알고리즘 변경
//───────────────────────────────────────

int gen()
{
	static int c = 0;
	return c++;
}

void printElement( int a)
{
	cout << a << " ";
}

int Add( int a, int b)	{		return a+b;	}
void main()
{
	ostream_iterator<int>  out( cout, "-");		// 


	vector<int> v(20);							// 20개 저장공간..
	generate( v.begin(), v.end(), gen);			// 대입..

	copy( v.begin(), v.end(), out);				// 복사..어따가??(모니터에..)
	cout << endl; 	
	//-------------------------------------------------------------------

	// 단항 함수를 파라미터로 갖는 함수
	// 출력..
	for_each( v.begin(), v.end(), printElement);
	cout << endl; 
	//---------------------------------------------------------------------

	// 이항함수를 파라미터로 갖는 함수
	int c1[] ={ 1,2,3,4,5,6,7,8,9,10};

	int c2[] = { 2,4,6, 2,2,2,2,2,2};

	vector<int> v1(10);

	transform( c1, c1+10, c2, v1.begin(), Add );

	copy(v1.begin(), v1.end(), out);
	//----------------------------------------------------------------------

	

}


















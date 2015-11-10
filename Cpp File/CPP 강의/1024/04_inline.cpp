#include <iostream>
using namespace std;

#define ADD(X,Y) X+Y		// C언어에서 많이 사용 : 매크로 함수
// 1. 함수 호출발생 X			 ==> inline
// 2. 타입에 관계 없다.(일반화)	 ==> overloading , template
// 3. 단점 : 코드 크기를 증가..	==>  inline


inline int ADD(int x, int y)
{
	return x+y;
}


void main()
{
	cout << ADD(10, 20) << endl;	// cout <<10+20 << endl;
	cout << ADD(10.1, 20.1) << endl;	// cout << 10.1 + 20.1 << endl;
}
//〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓
//  [ 함수 5 ] 
//〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓


//───────────────────────────────────────
// FUNCTOR
//───────────────────────────────────────
// 미리 만들어진 다양한 함수 객체
//───────────────────────────────────────

#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <algorithm>
#include <functional> // 미리 만들어진 함수 객체 사용하기 위함
using namespace std;



// ex1)
//void goo( void(*f)() )

template<class T> goo( T f)	{		f();		}
// 함수

void foo( )	{		cout << "foo" << endl;		}

class FOO	{
public:
	void operator()()		{			cout << "foo" <<endl;		}	
};

void main()	{
//	goo( foo);
	FOO f;
	f();
	goo( f ); // 함수 호출됨 
}



// ex2)
int Add( int a, int b)	{		return a + b;	}
// 사용자가 만들지 않아도 -> STL안에 아래 함수객체가 있다.
struct Add	{
public:
	int operator()(int a, int b)		{			return a+b;		}
};
void main()	{
	int x[5] = { 1,2,3,4,5};		int y[5] = { 1,2,3,4,5};		vector<int> v( 5);
//	Add add;
	transform( x, x+5, y, v.begin(), Add);
	copy(v.begin(), v.end(), ostream_iterator<int>(cout, " " ));		cout << endl;
}




// ex3)  사용자가 만들지 않아도 -> STL안에 아래 함수객체가 있다.
void main()	{
	int x[5] = { 1,2,3,4,5};		int y[5] = { 1,2,3,4,5};		vector<int> v( 5);
//	multiplies<int> p; // 더하기가 가능한 함수객체.
//	transform( x, x + 5,  y, v.begin(),  p );
	transform( x, x + 5,  y, v.begin(),  plus<int>() );
	copy( v.begin(), v.end(), ostream_iterator<int>(cout, " "));
}



// ex4)
void main(){
	int a[] = {1,2,3,4,5};	int b[] = {5,4,6,3,4};		vector<int> v(5);
	// 미리 만들어진 함수 객체 사용 Add 기능을 하는 plus
	// 파라미터 5개 plus(int, int) 이항 함수를 갖음
	transform(a, a+5, b, v.begin(), plus<int>() );

	copy(v.begin(), v.end(),	ostream_iterator<int>(cout, " "));

	cout << endl;

	// negate =>  음수로 만들어준다. 
	// 파라미터 4개. negate(int) 단항 함수를 갖음
	transform(v.begin(), v.end(), v.begin(), negate<int>() );
	copy(v.begin(), v.end(),
		ostream_iterator<int>(cout, " "));
}


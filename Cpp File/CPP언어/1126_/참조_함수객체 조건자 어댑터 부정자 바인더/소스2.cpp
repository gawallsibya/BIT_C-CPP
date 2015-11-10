//〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓
//  [ 함수 3 ] 
//〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓


//───────────────────────────────────────
// 함수 객체 
//───────────────────────────────────────

#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
using namespace std;

bool GreateThan5(int a)
{
	return a > 5; 
}

template <class T>
void foo( T func, int number)
{
	func(number);
}
void main()
{
	// 5보다 적은 수인가?
	foo( GreateThan5, 10);


}
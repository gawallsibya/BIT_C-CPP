//〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓
//  [ 함수 4 ] 
//〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓


//───────────────────────────────────────
// 함수를 함수 객체로 
//───────────────────────────────────────
// 함수를 바인더에서 사용하려면?
// 함수를 함수 객체로 바꿔주는 수 밖에 없다.
//───────────────────────────────────────

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;

// 함수를 바인더에서 사용하려면?		// 함수를 함수 객체로 바꿔주는 수 밖에 없다.
int Add(int a, int b){	return a+b;	}

void main()
{
	int a[] = { 1,2,3,4};	
	int b[] = { 1,2,3,4};	
	vector<int> v(4);


//	transform(a, a+4, b, v.begin(), pf); // a~a4까지의 원소를 같은순서의 b의 원소와 더함
//	transform(a, a+4, v.begin(), bind2nd(Add, 2)); // error 함수는 사용할 수 없음
	// 함수를 함수 객체로 바꾼다.방법 1

	pointer_to_binary_function<int, int, int> pf(Add);


	// pf는 함수 객체 이다.
	// 함수객체로 바꾸었으므로 부정자, 바인더 모두 쓸 수 있음

	transform(a, a+4, v.begin(), bind2nd(pf, 2));


	// 방법 2 ptr_fun()함수를 부르면 객체를 만들어서 리턴. 방법 2가 편함.
	// 따라서 ptr_fun()함수 사용법 익혀 둘것

	transform(a, a+4, v.begin(), bind2nd( ptr_fun(Add), 2));
	// 함수 어댑터(function Adaptor)라고도 한다.
	// 바인더 많이 중요

	cout << v[0] << endl; // 2
}


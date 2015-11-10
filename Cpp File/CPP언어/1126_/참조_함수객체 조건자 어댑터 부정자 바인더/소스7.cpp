//〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓
// [  바인더  ]
//〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓

//───────────────────────────────────────
// binder => 어떤 함수의 파라미터 2개짜리를 하나로 바꿈
//───────────────────────────────────────

#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <algorithm>
#include <functional>

using namespace std;


// Binder -> 이항 함수객체를 단항 함수 객체로..
void main(){
	deque<int> s;		s.push_back(10);
	//..... s 를 가지고 상당히 많은 작업을 한다.!!!
	int x[] = { 1,2,3,4,5,6,7,8,9,10};
	modulus<int> m;
	int* p = remove_if( x, x + 10, not1( bind2nd( m, 3) ) );  //
	copy( x, p, ostream_iterator<int>(cout, " ") );
}

void main(){
	int a[] = {1,2,3,4,5,6};
	int b[] = {6,5,4,3,2,1};
	vector<int> v(6);

	// plus() 이항 함수를 단항함수로 바꾸고자 할 때
//	transform(a, a+6, b, v.begin(), plus<int>() );
	transform(a, a+6, v.begin(), bind2nd(plus<int>(), 1) );
	// bind1st() 는 첫번째 파라미터 고정, bind2nd는 두번째 파라미터 고정

	copy(v.begin(), v.end(), ostream_iterator<int>(cout, " ") );

	list<int> li;
	li.push_back(10);
	li.push_back(5);
	li.push_back(6);
	li.push_back(9);
	li.push_back(11);

	// modulus 는 % 연산자임.
	// 3의 배수 제거
	list<int>::iterator p = remove_if(li.begin(), li.end(),
		not1(bind2nd(modulus<int>(), 3)));
	// not1은 부정자, bind2nd는 두번째 파라미터 고정
	// bind2nd(Add, 2) => 이런건 안됨. 함수객체만 된다.
	copy( li.begin(), p, 
		ostream_iterator<int>(cout, " "));
}

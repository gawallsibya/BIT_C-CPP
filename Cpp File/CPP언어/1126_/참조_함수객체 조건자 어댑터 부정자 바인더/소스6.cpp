//〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓
// 부정자 
//〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓



//───────────────────────────────────────
// 부정자 : 조건자 함수 객체의 결과를 부정하는 객체를 생성
//          unary_function, binary_function의 하위 객체에만 
//          사용가능.
//───────────────────────────────────────
// 예) 어떤 함수 객체가 true일때 => 부정자 거친 후에 => false로 됨.
//───────────────────────────────────────


#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;

// 부정자 : 조건자 함수 객체의 결과를 부정하는 객체를 생성

template<int s>
class IsDivide : public unary_function<int, bool>	{
	public: bool operator() (int n) {return n%s == 0; }
};
void main(){
	int a[] = {1,2,3,4,5,6};
	int* p = find_if(a, a+6, IsDivide<3>() ); // 3으로 나누어 떨어지는 수 찾기
	cout << *p << endl;
	// 여기서 함수 객체의 반환값을 부정하고자 할 때
	// not1, not2 함수를 쓴다. 
	// not1 파라미터 갯수 1개짜리, not2 2개짜리를 나타냄

	int* pp = find_if(a, a+6, not1( IsDivide<3>()) );

//	cout << *pp << endl; // 결과값? 
}

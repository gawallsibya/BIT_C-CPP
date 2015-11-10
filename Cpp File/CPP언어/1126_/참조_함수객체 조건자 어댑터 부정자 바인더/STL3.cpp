//〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓
// [ STL ]
//
//   0. 들어가기 
//   1. 함수(function)			
//   2. 조건자(predicate)
//   3. 함수 객체(function object)
//   4. 함수 어댑터(function adaptor)  
//   5. 부정자(negator)와 바인더(binder)
//〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓


//〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓
//  [ 0. 들어가기 ] 
//〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓


// accumulate 제네릭 함수 
// 두 개의 반복자 first, init값을 인자로 받아 
// 반복자 사이에 위치한 모든값과 init 값을 더해 얻어진 총합을 리턴..
/*
template <typename InputInterator, typename T>
T accumulate( InputInterator first, InputInterator last, T init)
{
	while( first != last)
	{
		init = init + *first;
		++first;
	}
	return init;
}
*/
// ==> 만약 accumulate를 호출할 때 다른 연산이 수행되도록 하려면??
//     인자로 이에 해당하는 함수를 넘겨주면 된다.
//     함수 포인터를 필요로 한다.



#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;
//──────────────────────────────────
// 1) 처음으로 확장된 accumulate 정의와 호출.
//──────────────────────────────────
/*
// 함수포인터를 인자로 하는 템플릿 함수 선언.
template <typename Inter, typename T>
T accumulate1( Inter first, Inter last, T init, T (*binary_function)(T x, T y))
{
	while( first != last)
	{
//		init = init + *first;
		init = (*binary_function)(init, *first);
		++first;
	}
	return init;
}

int multifun( int x, int y) { return x * y ; }
void main()
{
	int x[5] = { 2,3,5,7,11};
	vector<int> vector1( x, x+5);

	int product = accumulate1(vector1.begin(), vector1.end(), 1, &multifun);
	cout << product << endl;
}
// >> 위 소스의 문제점 : 범용성이 떨어진다. 함수포인터는 고정될 수 밖에 없다.
//                       제어권이 이동된다.
*/


//──────────────────────────────────
// 2) 함수 객체를 템플릿 인자로 지정하는 것의 장점 
//──────────────────────────────────
/*
#include <numeric>
template <typename Inter, typename T, typename BinaryFunction>
T accumulate1( Inter first, Inter last, T init, BinaryFunction binary_function)
{
	while( first != last)
	{
//		init = init + *first;
		init = binary_function(init, *first);
		++first;
	}
	return init;
}

int multifun( int x, int y) { return x * y ; }
class multiply
{
public:
	int operator() (int x, int y) const { return x * y; }
};

void main()
{
	int x[5] = { 2,3,5,7,11};
	vector<int> vector1( x, x+5);		// 2, 3, 5, 7, 11

	multiply test;	// 함수 객체 
	int product = accumulate(vector1.begin(), vector1.end(), 1, test);
	cout << product << endl;
}
*/
// >> 함수 객체의 프로토타입은 이 함수 객체의 두 인자타입이 함수내부에서 
//    변환 가능하면 가능하다.
//    따라서 고정된 프로토타입이 아닌 범용적인 타입도 가능해진다.
/*






//───────────────────────────────────────
	1 함수(function)
//───────────────────────────────────────
 
- 표준 라이브러리에서 제공하는 알고리듬중에는 함수를 인자로 요구하는 것들이 많다. 
  for_each() 알고리듬은 컨테이너에 담긴 각각의 원소에 인자로 넘겨받은 함수를 적용
*/


//	ex) printElement() 함수를 사용하여 정수 list의 원소들을 출력하는 코드

	void printElement(int value, int temp)		// 1항 함수
	{
		cout << "The list contains " << value << endl;
	}

	void main() 
	{
		vector<int> v(10);		// int값 10개를 저장시키는 공간 + 초기화(0)
		for( int i=0; i<10; i++)
			v[i] = i;			// 0 1 2 3 4 5 6 7 8 9

		for_each(v.begin(), v.end(), printElement );
	}




/*
- 이항 함수(binary function)는 두개의 인자를 취하는데, 
  서로 다른 두 시퀀스에서 값들을 하나씩 가져와 함수에 넘겨준다. 

   ex), 문자열 list와 정수 list를 주어지고, 
   문자열 list에 담긴 각각의 문자열을 정수 list에 적힌 횟수만큼 복사한다고 할 때, 
   표준 라이브러리에서 제공하는 transform() 함수를 사용하면 쉽게 할 수 있다. 
   이를 위해 우선 원하는 기능을 가진 이항 함수를 정의한다. 

	// 'base'를 'number' 갯수만큼 복사한다. 
	string stringRepeat(const string& base, int number)
	{
		string result;   // 'result'는 처음에 비어 있다.
		while (number--)  result += base;
		return result;
	}
	그리고, 다음과 같이 transform()을 호출하면 원하는 결과를 얻을 수 있다. 
	list<string> words;
	list<int> counts;
	...
	transform(words.begin(), words.end(), counts.begin(),
								words.begin(), stringRepeat);
	(one, two, three)를 (3, 2, 3)과 함께 transform()을 호출하면, 
	(oneoneone, twotwo, threethreethree)의 결과를 얻을 수 있다. 



   
//─────────────────────────────────
   2. 조건자(predicate)
//─────────────────────────────────

- 조건자(predicate)는 불값(true/false) 또는 정수값을 리턴하는 함수
- 기존의 C 관행에 따라, 영이 아닌 정수값은 참으로 간주하고, 
  영인 경우에는 거짓으로 간주한다. 
  
  ex) 정수값을 인자로 받아 윤년이면 참을, 아니면 거짓을 리턴하는 함수

	// 'year'가 윤년에 해당하면 참을 리턴한다.
	bool isLeapYear(unsigned int year)	{
		int flag = false;

		if ((year % 4) == 0) {              // 4년마다 윤년이고,
			flag = true;
        if((year % 100) == 0) {         // 그중 100년마다 윤년이 아니고,
            flag = false;
            if((year % 400) == 0) {     // 그중 400년마다 윤년
                flag = true;
            }
        }
    }
    return flag;
	}

- generic 알고리듬의 인자로 조건자를 사용할 수 있다.

  ex) find_if() 알고리듬을 
      이 함수는 조건자를 만족하는 첫번째 원소를 리턴하는데, 
	  만약 이 조건자를 만족하는 원소가 없으면 end-of-range 값을 리턴한다. 
	  이 알고리듬을 사용하여, 
	  다음과 같이 년도들로 구성된 list(aList)에서 
	  첫번째로 발견된 윤년의 위치를 리턴하는 코드를 만들 수 있다. 

	 list<int>::iterator firstLeap = 
				find_if(aList.begin(), aList.end(), isLeapYear);


  
   
//─────────────────────────────────
	3. 함수 객체(function object)
//─────────────────────────────────

- 괄호 연산자를 멤버함수로 가지고 있는 클래스의 객체이다. 
  함수 대신에 함수 객체를 사용하는 것이 더 편리한 경우가 많은데, 
  함수 객체를 함수로 사용하면, 
  함수가 호출될 때마다 함수 객체의 괄호 연산자가 호출된다. 
  
	ex)  
	class biggerThanThree 
	{
		public:
		bool operator()(int val) { return val > 3; }
	};

    ==> biggerThanThree 클래스의 객체를 함수 호출 형태를 사용하여 
	    참조하게 되면, 
		멤버함수로 정의된 괄호 연산자가 호출된다. 
		이번에는 이 클래스를 일반적인 용도에 쓸 수 있도록 다듬어 본다. 

		생성자와 데이터 멤버를 추가하자. 
	class biggerThan {
		public:
		const int testValue;
		biggerThan (int x) : testValue(x) { }

		bool operator()(int val) { return val > testValue; }
	};

	이렇게 함으로써 'X보다크냐?'라는 함수객체를 만들수 있고, 
	여기서 X의 값은 함수 객체를 생성할 때 정할 수 있다. 
	인자로 조건자(predicate)를 요구하는 generic 함수에 함수 객체를 넘길 수 있는데, 

	다음은 list에서 12보다 큰 첫번째 값을 찾아내는 코드이다. 
	list<int>::iterator firstBig =
		find_if(aList.begin(), aList.end(), biggerThan(12));

	일반 함수대신에 함수 객체를 사용하는 가장 큰 이유로 세가지
	1) 새로운 함수를 만들지 않고 표준 라이브러리에서 제공되는 함수객체를 사용
	2) 인라인 함수를 호출함으로써 수행속도를 향상하고자 하는 것
	3) 함수객체로 하여금 자신이 가지고 있는 상태정보를 접근하고, 
	   갱신할 수 있도록 하자는 것 
  
ex1) plus()를 사용하여 정수들로 구성된 두개의 list를 원소별로 더하여, 
     그 결과를 첫번째 list에 배치한다. 

	transform(listOne.begin(), listOne.end(), listTwo.begin(), 
		listOne.begin(), plus<int>());

ex2) 불값으로 이루어진 vector내의 모든 원소를 부정하는 예이다. 
	transform(aVec.begin(), aVec.end(), aVec.begin(),
		logical_not<bool>());

 

  
//─────────────────────────────────
   4. 함수 어댑터(function adaptor)
//─────────────────────────────────

- 함수를 함수객체로 사용할 수 있도록 전역함수 또는 멤버함수를 바꿔주는 
  클래스의 객체이다
  (함수 객체는 함수 또는 함수객체의 행동을 바꾸는데 사용할 수도 있다.) 

  각각의 함수 어댑터는 전역 함수 또는 멤버 함수를 인자로 하는 생성자 존재 

  pointer_to_unary_function과 pointer_to_binary_function 템플릿은 
  하나 또는 두개의 인자를 가지는 전역 함수를 개작하는데 사용된다. 
  이들 어댑터는 
     1) 직접 적용할 수도 있고, 
     2) ptr_fun 함수 템플릿을 사용하여 
  적절한 어댑터를 자동으로 생성할수도 있다. 
  
  ex) 그냥 단순한 times3() 함수를 개작하여, 이를 정수 vector에 적용할 수 있다. 

	int times3(int x)
	{
		return 3 * x;
	}

	int a{} {1,2,3,4,5};
	vector<int> v(a, a+5), v2;

	transform(v.begin(), v.end(), v2.end(), ptr_fun(times3));

	또는, 어댑터를 적용하여 새롭게 개작된 함수 객체를 vector로 넘겨준다. 
	pointer_to_unary_function<int, int> pf(times3);
	transform(v.begin(), v.end(), v2.end(), pf);

	이렇게 하는 경우, 컴파일러가 ptr_fun을 사용하여 
	pointer_to_unary_function이 요구하는 타입을 추론할 수 있다는 장점이 있다.  

	'mem_fun' 부류의 템플릿은 전역함수가 아닌 멤버함수를 개작하는데 사용된다. 
	예를 들어, list의 set을 가지고 있고, set내의 각 list를 정렬하고 싶다면, 
	mem_fun_t나 mem_fun을 사용하여 set내의 각 list에 list 정렬함수를 적용할 수 있다. 

	set<list<int>* > s;

	// set 원소들을 list들로 초기화한다
	...
	// set에 속해있는 list들을 각각 정렬한다
	for_each(s.begin(),s.end(),mem_fun(&list<int>::sort));

	// 이제 set에 속한 각각의 list들이 모두 정렬되었다.

 

 
   
//─────────────────────────────────
	3.5 부정자(negator)와 바인더(binder)
//─────────────────────────────────

- 부정자(negator)와 바인더(binder)는 기존에 있던 함수 객체로부터 
  새로운 함수 객체를 만드는데 사용되는 함수 어댑터이다. 
  이들은 다른 함수나 generic 알고리듬을 호출하기에 앞서 인자 리스트를 
    구성하는 과정의 일부로 사용되는 것이 보통이다. 


- 부정자 not1()와 not2()는 각각 단항과 이항 조건자 객체를 인자로 받아들여,
  원래 값의 반대값을 내뱉는 새로운 함수 객체를 생성한다. 
  예를 들어, 앞절에서 정의한 widget 검사기 함수 객체를 이용하면, 함수객체 

	not2(WidgetTester())
  는 widget 검사기와 같은 인자를 가지고, widget 검사기가 참일때 거짓을, 
  거짓일때 참을 반환하는 이진 조건자를 만들어낸다. 
  
  부정자는 unary_function과 binary_function 클래스의 하위 클래스로 정의된 
  함수 객체하고만 사용된다. 
	A Hot Idea 

- 바인더는 두개의 인자를 가지는 함수를 받아서, 
  첫번째 인자나 두번째 인자를 특정 값으로 바인드시켜 한개의 인자를 가지는 
  함수를 만들어 낸다. 
  이때, 바인더의 인자로 넘어오는 함수는 binary_function 클래스의 하위 클래스에 
  속해야 한다.
  bind1st() 바인더는 첫번째 인자를 바인드하고, bind2nd()는 두번째 인자를 바인드한다. 

  예를 들어, 
  바인더 bind2nd(greater<int>(), 5)는 5보다 큰지를 검사하는 함수객체를 만들어내며, 
  다음과 같이 쓰일 수 있다. 
  
  아래 예는 list에서 가장 먼저 발견되는 5보다 큰 수를 가리키는 반복자를 
    반환하는 코드이다. 

  list<int>::iterator where = find_if(aList.begin(), aList.end(),
	         bind2nd(greater<int>(), 5));
  바인더와 부정자를 결합해서, 다음과 같은 함수객체를 생성할 수 있다. 
  이 함수객체는 인자가 3으로 나눠지면 참을, 그렇지 않으면 거짓을 반환한다. 
    아래 코드는 list로부터 3의 배수를 제거한다. 
  list<int>::iterator where = remove_if(aList.begin(), aList.end(),
           not1(bind2nd(modulus<int>(), 3)));

  아래에서 바인더는 이진 함수 WidgetTester() 함수를 호출할 때 widget 번호를 
  고정시켜서, widget만을 유일한 인자로 취하는 함수를 만들어낸다. 

  list<Widget>::iterator wehave = 
   find_if(on_hand.begin(), on_hand.end(), 
      bind2nd(WidgetTester(), wid));
*/
 

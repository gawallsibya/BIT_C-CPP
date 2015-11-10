/**********************************************************
 [ 정보 은닉 ] 

1. 객체가 불안해(unstable) 지는 것을 막는다.
2. 외부의 변화없이 객체 내부를 변경할수 있다.
3. 맴버 data는 맴버 함수를 통해서만 변경 가능 토록 한다.
**********************************************************/


#include <iostream>		
using namespace std;

// C 기반 stack이 필요한다.
int top = 0;			
int buf[10];
void push( int n )	
{		
	buf[top++] = n;	
}
int pop()		
{	
	return buf[top--];	
}
void main()	
{
	push(10);			
	push(20);
	cout << pop() << endl;
}

/*
// C++ 기반 stack

void main()	{
	Stack s;		s.init( 30 );
	s.push(10);		s.push(20);		s.push(30);
	//	s.top = 100;
	cout << s.pop() << endl; // 30.
}
*/


/*
============================================================
 Sample1  Information Hiding => 불안정성 해결 
============================================================
객체의 데이터를 외부에서 직접 접근하는 것을 막는다. 
멤버 함수를 통해서만 객체를 접근할 수 있게 한다.
  
struct Bike
{
	int gear;
};

void main()
{
	Bike bike;
	
	bike.gear = -10;
}

-------------------------------------------------
[ 정 보 은 닉 ]

  대부분 객체의 data를 외부에서 접근 할 경우 객체가 
  불안정해 질수 있다. 
  위 예제에서 gear를 외부에서 직접 접근 하므로서 
  gear에 -10이라는 잘못된 값을 넣는 실수를 할 수 있게 된다.

  그래서 객체의 data를 외부에서 접근하지 못하도록 
  Private 영역에 놓는다. 
 
  또한 외부에서 값을 바꾸고자 할 때는 멤버 함수를 통해 서만 
  변경 가능 하도록 해야 한다.


class Bike
{
	int gear;
public:
	// 멤버 함수는 private에 접근가능.
	void ChangeGear( int n ) // Modifier(수정자) <-> accessor(접근자)
	{
		// 값의 유효성 여부를 조사할수 있다.
		if ( n >= 1 && n <= 9)
				gear = n;
	}
};

void main()
{
		Bike b;
//		b.gear = 5;
//		b.gear = 100000; // ?
		b.ChangeGear( 5 );
		b.ChangeGear( 100000);
}

*) 접근 지정자(private Vs public)
    private: 객체의 멤버함수 내에서만 접근할 수 있다.
    public : 객체의 외부에서도 접근할 수 있다.

접근 지정자를 생략하면 
struct 는 default로 public, 
class 는 default로 private이 된다


============================================================
 Sample2  Information Hiding => 외부 변화 없이 내부를 수정
                                할 수 있다.
============================================================

#include <iostream>
using std::cout;
using std::endl;

class stack
{
private:
	int buff[10];
	int top;
public:
	void init() 	{ top = 0;}
	void push( int n ) { buff[top++] = n;}
	int  pop( ) 	{ return buff[--top];}
	void cleanup() { top = 0;}
};
void main()
{
	stack s;

	s.init();

	s.push(10);
	s.push(20);

	cout << s.pop() << endl;
	cout << s.pop() << endl;

	s.cleanup();
}

----------------------------------------------
위 stack 은 배열을 사용해서 구현 했기 때문에 
크기가 항상 10개짜리 스택 밖에 만들수 없다. 
이제 stack 을 동적 메모리 할당을 사용해서 다시 만들었다고 하자

class stack
{
private:
	int* buff;
	int top;
public:
	void init(int n = 10) 
	{ 
		top = 0;
		buff = new int[n];
	}
	void cleanup() 
	{ 
		top = 0;
		delete[] buff;
	}

	void push( int n ) { buff[top++] = n;}
	int  pop( ) { return buff[--top];}
};

이제 새롭게 만들어진 stack을 사용하기 위해 이전의 
main() 함수를 수정할 필요가 있을까 ?

Stack 이 노출하는 4가지 인터페이스(함수)의 이름과 형태만을 
변경하지 않는다면 스택은 여러 형태로 변경이 가능해진다.


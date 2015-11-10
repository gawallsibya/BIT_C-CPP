/**********************************************************
 [ 복사 생성자 ] 
**********************************************************/
/*
 복사 생성자란 ?
	동일한 type의 객체를 인자로 받는 생성자.

 형태
	Point(const Point& )

 언제 호출되는가 ?
	자신의 type으로 객체를 생성하는 경우.
	함수 호출시 객체를 값에 의해 전달 하는 경우.
	함수 리턴시 객체를 값에 의해 리턴 하는 경우

class Point
{
public:
	int x, y;
public:
	Point() : x(0), y(0) 
	{
		   cout << "생성자1" << endl;
	}
	Point( int _x, int _y) : x(_x), y(_y)
	{
		   cout << "생성자2" << endl;
	}
	Point(const Point& p)
	{
		   x = p.x;
		   y = p.y;
		   cout << "복사생성자" << endl;
	}
};
void main()
{
	Point p1;
	Point p2(1,2);
	Point p3(p2); // ?
	Point p4 = p2; // ?
}

-------------------------------------------------
[ Deep In C++ - Explicit Initialize ]

  C++에서는 객체를 명시적으로 초기화 할 때 
  아래의 2가지 방법을 사용할 수 있다.

class Int32
{
private:
	int value;
//	Int32(const Int32& n) {}
public:
	Int32( int v = 0) : value(v) {}
};

void main()
{
	Int32 n1(5);	// A
	Int32 n2 = 5;	// B
}

A의 표현은 객체를 생성한 후  
바로 생성자를 호출하는 표현이다.(즉, 함수가 1번 호출된다.)

하지만 B의 표현은 5를 사용해서 
임시 객체가 생성(생성자 호출)된 후 
복사 생성자를 사용해서 n2에 복사 되는 것이다.

그래서 B의 표현은 복사 생성자가 private에 있을 경우에는 
Error 가 나온다.

그러므로 B의 표현보다는 A의 표현을 사용하는 것이 좋다.
(주의 MS의 VC++ 컴파일러는 표준 C++ 문법에 추가한 
여러 가지 언어 확장 기능을 가지고 있기 때문에 
복사생성자가 private에 있다해도 B코드가 에러가 나지 않는다. 
VC++에서 언어 확장 기능을 사용하지 않으려면 컴파일 할때 
‘/Za’ Option을 추가하면 된다.)

*/


/*
=======================================================
 복사 생성자가 호출되는 3가지 경우 
  - 복사 생성자가 호출되는 3가지 경우를 알아야 하는 것이 
    아니라 
	 
	그 시점을 알아서 
    복사 생성자를 호출 시키지 않는 방법을 알아야 한다.
=======================================================
class Point
{
public:
	Point() 	{ 		cout << "생성자" << endl;	}
	~Point()	{ 		cout << "소멸자" << endl;	}
	Point( const Point&) 	{ 		cout << "복사생성자" << endl;	}
};

void main()
{
	Point p1;
	Point p2(p1);
	Point p3 = p1;
}


void foo(const Point& p1) {}

void foo( Point p1) { }

void main()
{
	Point p;
	foo( p );
}


Point goo( )
{
	return Point();
}

Point goo( )
{
	Point p;
	return p;
}
void main()
{
	goo();
}

*/


/*
=======================================================
 디폴트 복사 생성자의 문제점
=======================================================
class Cat
{
private:
	int	  age;
	char* name;

public:
	Cat( int _age = 1, char* _name = "unknown")
	{
		age = _age;
		name = new char[strlen(_name)+1];
		strcpy( name, _name);
	}
	~Cat() { delete[] name;}
};
void main()
{
	Cat c1(3, "Garfield");
	Cat c2 = c1;
}
--------------------------------------------
사용자가 복사 생성자를 제공하지 않을 경우 컴파일러가 제공한다. 이를 디폴트 복사생성자라고 한다.

디폴트 복사 생성자는 기본적으로 멤버 대 멤버 복사를 수행한다.

클래스가 Pointer멤버를 가지고 있고 메모리를 동적할당하는
 코드가 있다면 반드시 복사 생성자는 다시 만들어야 한다.
(디폴트 복사 생성자는 포인터 변수가 가르키는 메모리를 복사
 하지 않고 주소 자체를 복사(앝은 복사)를 수행한다.
 사용자는 반드시 메모리 자체를 복사(깊은복사)를 코드를
 제공해야한다.)

Cat( const Cat& c)
{
	age = c.age;
	name = new char[strlen[c.name] + 1];
	strcpy( name, c.name);
}


디폴트 복사생성자의  문제를 해결하기 위해 아예 복사 
자체를 금지할 수 도 있다. 복사 생성자를 Private 영역에 
선언만 하면 복사 자체를 금지 할 수도 있다.

class Cat
{
private:
	Cat(const Cat&);
	……;
};

=======================================================
 연습 문제 
  - 아래 코드에서 main함수가 실행되었을 때의 메모리 그림
    을 그려 보세요.
=======================================================
#include <iostream>
using namespace std;

class String
{
public:
	String(const char* value = 0);
	inline ~String();

private:
	char* data;
};

String::String( const char* value)
{
	if ( value )
	{
		data = new char[strlen(value)+1];
		strcpy( data, value);
	}
	else
	{
		data = new char[1];
		*data = 0;
	}
}
inline String::~String()
{
	delete[] data;
}
void main()
{
	String s1 = "Hello";
	String s2 = s1;
}

2. 위 코드의 문제점을 지적하고 복사 생성자를 재정의 
   해서 해결해 보세요.( Deep Copy로 구현해 보세요)
3. Deep Copy로 구현된 복사생성자의 문제점을 생각해 보세요. 
   그리고 위 클래스를 참조계수 방법으로 바꾸어 보세요.
*/

/*
=======================================================
 연습 문제 
  - 아래 stack 코드의 빈 칸을 구현해 보세요.
=======================================================
#include <iostream>
using namespace std;

class Stack
{
private:
	int stk[10];
	int top;

public:
	Stack() : top(0){};
	void Push(int n) { stk[top++] = n;}
	int Pop(){ [_____________] };
};
void main()
{
	Stack st;
	st.Push(20);
	st.Push(10);

	cout << st.Pop() << endl;
	cout << st.Pop() << endl;
}

2. 위 코드는 스택의 크기가 10개로 고정되어 있습니다. 
   배열을 사용하지 말고 동적 메모리 할당을 사용해서 
   스택의 크기를 객체생성시에 지정할 수 있도록 만들어 보세요
	void main()
	{
		Stack s(20); // 20개를 보관할수 있는 stack
	}

3. 2번 스택의 문제점을 생각해 보세요.. 
   그리고 동적 메모리 할당 대신에 Single Linked List를 
   사용해서 stack 을 만들어 보세요.
   => SLL ??

*/

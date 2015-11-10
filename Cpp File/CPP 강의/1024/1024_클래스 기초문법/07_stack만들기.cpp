/**********************************************************
 [ 실습 : Stack 만들기 ] 
**********************************************************/

/*
===========================================================
// 1. 아래 코드는 간단히 만들어진 Stack 코드를 보여 준다.
===========================================================

#include <iostream>
using namespace std;

class Stack
{
	int buff[10];
	int top;
public:
	Stack() : top(0) {}
	bool isempty(){ return (top == 0);}
	bool isfull()     { return (top > 10);}

	void push( int n ) 
	{
		if ( isfull() )
		{
			cout << "Stack is full" << endl;
			return ;
		}
		buff[top++] = n;
	}
	int pop() 
	{
		if ( isempty() )
		{
			cout << "Stack is empty" << endl;
			return -1;
		}
		return buff[--top];
	}
};

void main()
{
	Stack stk;

	stk.push( 10 );
	stk.push( 20 );
	stk.push( 30 );
	stk.push( 40 );

	cout << stk.pop() << endl;
	cout << stk.pop() << endl;
	cout << stk.pop() << endl;
	cout << stk.pop() << endl;
}
*/

/*
===========================================================
// 2. 동적 메모리 사용하기
===========================================================
#include <iostream>
#include <iostream>
using namespace std;

class Stack
{
	int* buff;
	int  top;
	int  size;
public:
	Stack(int sz = 10) : top(0), size(sz) 
	{
		buff = new int[size];
	}
	~Stack() 
	{
		delete[] buff;
	}

	bool isempty() { return (top == 0);}
	bool isfull()  { return (top > size);}

	void push( int n ) 
	{
		if ( isfull() )
		{
			cout << "Stack is full" << endl;
			return ;
		}
		buff[top++] = n;
	}

	int pop() 
	{
		if ( isempty() )
		{
			cout << "Stack is empty" << endl;
			return -1;
		}
		return buff[--top];
	}
};

void main()
{
	Stack stk;

	stk.push( 10 );
	stk.push( 20 );
	stk.push( 30 );
	stk.push( 40 );

	cout << stk.pop() << endl;
	cout << stk.pop() << endl;
	cout << stk.pop() << endl;
	cout << stk.pop() << endl;
}

*/

/*
===========================================================
// 3. 선언과 구현의 파일 분할
===========================================================
// stack.h
#ifndef _STACK_H_
#define _STACK_H_

class Stack
{
	int* buff;
	int  top;
	int  size;
public:
	Stack(int sz = 10);
	~Stack();

	bool isfull(); 
	bool isempty();

	int  pop(); 
	void push( int n ); 
};
#endif // _STACK_H_


// Stack.cpp
#include <iostream>
#include "Stack.h"
using namespace std;

Stack::Stack(int sz /*= 10*/ ) : top(0), size(sz) 
{
	buff = new int[size];
}
Stack::~Stack() 
{
	delete[] buff;
}
bool Stack::isempty()
{ 
	return (top == 0);
}
bool Stack::isfull()  
{ 
	return (top > size);
}
void Stack::push( int n ) 
{
	if ( isfull() )
	{
		cout << "Stack is full" << endl;
		return ;
	}
	buff[top++] = n;
}
int Stack::pop() 
{
	if ( isempty() )
	{
		cout << "Stack is empty" << endl;
		return -1;
	}
	return buff[--top];
}


// main.cpp
#include <iostream>
#include "Stack.h"
using namespace std;

void main()
{
	Stack stk;

	stk.push( 10 );
	stk.push( 20 );
	stk.push( 30 );
	stk.push( 40 );

	cout << stk.pop() << endl;
	cout << stk.pop() << endl;
	cout << stk.pop() << endl;
	cout << stk.pop() << endl;
}

/*
===========================================================
// 4. Template
===========================================================
#include <iostream>
using namespace std;

template< typename T> class Stack
{
	T* buff;
	int  top;
	int  size;
public:
	Stack(int sz = 10) : top(0), size(sz) 
	{
		buff = new T[size];
	}
	~Stack() 
	{
		delete[] buff;
	}

	bool isempty() { return (top == 0);}
	bool isfull()  { return (top > size);}

	void push( T n ) 
	{
		if ( isfull() )
		{
			cout << "Stack is full" << endl;
			return ;
		} 
		buff[top++] = n;
	}
	T pop() 
	{
		if ( isempty() )
		{
			cout << "Stack is empty" << endl;
			return -1;
		}
		return buff[--top];
	}
};

void main()
{
	Stack<int> stk;

	stk.push( 10 );
	stk.push( 20 );
	stk.push( 30 );
	stk.push( 40 );

	cout << stk.pop() << endl;
	cout << stk.pop() << endl;
	cout << stk.pop() << endl;
	cout << stk.pop() << endl;
}

----------------------------------------
#include <iostream>
using namespace std;

template< typename T> class Stack
{
	T* buff;
	int  top;
	int  size;
public:
	Stack(int sz = 10);
	~Stack();

	bool isempty();
	bool isfull();

	void push( T n );
	T pop();
};
template< typename T> 
Stack<T>::Stack(int sz = 10) : top(0), size(sz) 
{
	buff = new T[size];
}
template< typename T> 
Stack<T>::~Stack() 
{
	delete[] buff;
}

template< typename T> 
bool Stack<T>::isempty()
{ 
	return (top == 0);
}
template< typename T> 
bool Stack<T>::isfull()  { return (top > size);}

template< typename T> 
void Stack<T>::push( T n ) 
{
	if ( isfull() )
	{
		cout << "Stack is full" << endl;
		return ;
	} 
	buff[top++] = n;
}
template< typename T> 
T Stack<T>::pop() 
{
	if ( isempty() )
	{
		cout << "Stack is empty" << endl;
		return -1;
	}
	return buff[--top];
}

*/
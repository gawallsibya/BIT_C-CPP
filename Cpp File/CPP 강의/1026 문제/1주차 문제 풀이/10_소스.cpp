/************************************************************
 class
 -> �Ʒ� �ڵ带 ��ü �߽��� �ڵ�� �����Ͻÿ�.
*************************************************************/

#include <iostream>
using namespace std;

class A
{
	int stack[100];
	int top;

public:
	A()
	{
		top=0;
	}

	bool isfull()
	{
		return (top >= 100);
	}

	bool isempty()
	{
		return (top <= 0);
	}

	void push(int n)
	{
		if (isfull())
		{
			cout << "Stack is full !" << endl;
			return;
		}
		stack[top++] = n;
	}

	int pop()
	{
		if (isempty())
		{
			cout << "Stack is empty!!" << endl;
			return -1;
		}
		return stack[--top];
	}
};

void main()
{
	A a;
	a.push(10);
	a.push(20);

	cout << a.pop() << endl;
	cout << a.pop() << endl;
}

/*
int stack[100];
int top = 0;

bool isfull()
{
	return ( top >= 100 );
}
bool isempty()
{
	return ( top <= 0 );
}

void push( int n )
{
	if ( isfull() )
	{
		cout << "Stack is full !" << endl;
		return;
	}
	stack[top++] = n;
}
int pop( )
{
	if ( isempty() )
	{
		cout << "Stack is empty!!" << endl;
		return -1;
	}
	return stack[--top];
}*/

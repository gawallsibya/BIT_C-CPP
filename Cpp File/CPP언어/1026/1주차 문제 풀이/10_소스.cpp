/************************************************************
 class
 -> 아래 코드를 객체 중심의 코드로 변경하시오.
*************************************************************/

#include <iostream>
using namespace std;

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
}

void main()
{
	push( 10 );
	push( 20 );

	cout << pop() << endl;
	cout << pop() << endl;
	cout << pop() << endl;
}
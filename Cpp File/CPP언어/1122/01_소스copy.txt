#include <iostream>
using namespace std;

/*
bool foo()
{
	throw 10;
	cout << "출력???" << endl;
	return false;	// 오류 리턴..
}

void main()
{
	try
	{
		bool b =  foo();
	}
	catch(int num)
	{
		cout << "에러발생 : " << num << endl; 
	}
	catch( char ch)
	{
		cout << "에러발생 : " << ch << endl; 

	}
	cout << "main 함수 종료.." << endl;

}
*/

void main()
{
	try
	{
		int num		= 10;
		int num1	= 0;

		int result = num / num1;
	}
	catch( ... )
	{
		cout <<"예외 발생" << endl; 
	}
	cout << "정상 진행" << endl; 
}
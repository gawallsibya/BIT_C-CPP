#include <iostream>
using namespace std;

class MyString
{
	char* buf;
	int   size;
};

void main()
{
	string str;		// STL ���� ������ �ִ� ���ڿ� ���� ��ü

	str	= "TEST";	// str.operator=( "TEST" )
	str += " AAA";

	string str1;

	str1 = str;
	str1 = "TEST";

	if( str1.c_str() == str.c_str() )
	{
		cout << "�����Ѱ�" << endl; 
	}
	
	cout << str1.c_str() << endl; 
	cout << str.c_str() << endl; 


}
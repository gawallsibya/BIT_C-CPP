#include <iostream>
#include <vector>     // STL �� vector �츮�� ���� Array�� ���
#include <algorithm>  // �츮�� ���� find()�� ���� �Լ���...
#include <string>     // STL�� string class
using namespace std;
//typedef basic_string<char> string;
void main()	{
//	basic_string<char> s;
	string s = "hello,world"; // ���� container �Դϴ�.
	cout << s << endl;
	// s �� ������ ����ϼ���..
	reverse( s.begin(), s.end() );		cout << s << endl;
	// s�� sort �غ�����..
//	sort(s.begin(), s.end());			cout << s << endl;
	s = "ABCD";
	// s�� ���� iterator�� ����������..
	string::iterator b =  s.begin();
	++b;				cout << *b << endl; // 'B'
	--b;				cout << *b << endl; // 'A'
	vector<int> v(5);
	v[0] = 5;	v[1] = 3; 
	v[2] = 7;   v[3] = 10;
	v[4] = 1;
	// container�� ������ �˰� ������ reverse �Դϴ�. v�� ������ ������.
	// ?
	reverse( v.begin(), v.end() );
	for ( int i = 0 ; i < 5; i++)		cout << v[i] << endl;
	vector<string> v2(10);
	v2[0] = "hello";			v2[1] = "world";
	vector<string>::iterator b2 = v2.begin();
	cout << *b2 << endl; // ?"hello"
	reverse( (*b2).begin(), (*b2).end());

	cout << *b2 << endl;
}


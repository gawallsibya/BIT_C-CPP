#include <iostream>
#include <vector>     // STL 의 vector 우리가 만든 Array와 비슷
#include <algorithm>  // 우리가 만든 find()와 같은 함수들...
#include <string>     // STL의 string class
using namespace std;
//typedef basic_string<char> string;
/*
void main()	
{
//	basic_string<char> s;
	string s = "hello,world"; // 역시 container 입니다.
	cout << s << endl;
	// s 를 뒤집어 출력하세요..
	reverse( s.begin(), s.end() );		cout << s << endl;
	
	// s를 sort 해보세요..
	sort(s.begin(), s.end());			cout << s << endl;

	s = "ABCD";
	// s의 시작 iterator를 꺼내보세요..
	string::iterator b =  s.begin();
	++b;				cout << *b << endl; // 'B'
	--b;				cout << *b << endl; // 'A'

	vector<int> v(5);
	v[0] = 5;	v[1] = 3; 
	v[2] = 7;   v[3] = 10;
	v[4] = 1;
//	v.push_back(100);
//	v.insert(v.begin()+3, 10);
//	for(int i=0; i<6; i++)
//	{
//		cout << v[i] << endl; 
//	}

	// container를 뒤집는 알고 리즘은 reverse 입니다. v를 뒤집어 보세요.
	// ?
	reverse( v.begin(), v.end() );
	for ( int i = 0 ; i < 5; i++)		cout << v[i] << endl;

//	vector<vector<int> > n2;
//	char arr[3][20]
	vector<string> v2(10);
	
	v2[0] = "hello";			v2[1] = "world";
	vector<string>::iterator b2 = v2.begin();
	cout << *b2 << endl; // ?"hello"

	reverse( v2.begin(), v2.end());

	reverse( (*b2).begin(), (*b2).end());
//
	cout << *b2 << endl;
	
}
*/


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void main()
{
	int x[] = { 1,2,3,4,5};
	vector<int> v (5, 3);
	copy( x, x +5, v.begin() );
	copy( v.begin(), v.end(), ostream_iterator<int>(cout, " - ") );
}
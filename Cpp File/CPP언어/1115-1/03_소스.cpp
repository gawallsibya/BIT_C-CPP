#include  <iostream>
using namespace std;

class MyTime
{
	int h, m, s;
public:
	MyTime(int _h, int _m, int _s): h(_h), m(_m), s(_s) {}

	bool operator== ( const MyTime & rhs)
	{
		if( h == rhs.h && m == rhs.m && s == rhs.s)
			return true;
		else
			return false;
	}
	bool operator != ( const MyTime & rhs)
	{
		return !(*this == rhs);
	}
};

void main()
{
	MyTime time1(3,2,2);
	MyTime time2(3,2,2);

	if( time1 != time2 )		// time1.operator==( time2 )
	{
		cout << "동일한 시간" << endl;
	}
}

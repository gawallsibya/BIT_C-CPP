#include <iostream>
using namespace std;

class CA
{
	int num;

	friend void foo();
	friend class CB;
};

class CB
{
	void foo()
	{
		CA  a;
		a.num;
	}
};

void foo()
{
	CA a;
	a.num;		
}

void main()
{
}
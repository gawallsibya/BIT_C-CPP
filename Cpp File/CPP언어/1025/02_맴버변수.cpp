#include <iostream>
using namespace std;

class CA
{
	int num;
public:
	void woo()			// inline
	{
		num = 100;
	}
	void foo( int num )	// inline
	{
		num = num;
		CA::num = num;
		this->num = num;

		woo();
	}
	inline void goo();		// inline O
};

inline void CA::goo()
{

}

void main()
{
	CA		a;		 a.foo(1);		// 
}
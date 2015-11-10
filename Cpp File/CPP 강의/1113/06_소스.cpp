// overloading과 overriding 과의 관계,

#include <iostream>
using namespace std;

class CA
{
public:
	void foo()		{}
	void foo(int n) {}
};

class CB : public CA
{
public:
	void foo()		{}
	void foo(int n) {  CA::foo(n);	}
};

void main()
{
	CB		 b;
	b.foo();
	b.foo(10);
}

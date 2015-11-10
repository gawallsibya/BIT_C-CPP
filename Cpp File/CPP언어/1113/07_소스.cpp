// 가상 소멸자

#include <iostream>
using namespace std;

class CA
{
public:
	CA() { cout << "CA()" << endl; }
	virtual ~CA() { cout << "~CA()" << endl; }
};

class CB : public CA
{
public:
	CB() { cout << "CB()" << endl; }
	~CB() { cout << "~CB()" << endl; }

};

void main()
{
	CA *p = new CB;

	delete p;
}
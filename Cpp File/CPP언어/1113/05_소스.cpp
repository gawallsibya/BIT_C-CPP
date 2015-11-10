
#include <iostream>
using namespace std;
/*
class CA
{
};

class CB : public CA	// protected CA,   private CA
{
};

void main()
{
	CB b;				CA* pA = &b;		// Upcasting
	CA *pA	= new CB;

//	CA a;				CB *pB = &a;		// downcasting	==> error.
}
*/

/*
class Animal
{
public:
	virtual void Sound() { cout << "........." << endl; }
};

class Dog : public Animal
{
public:
	void Sound() { cout << "港港.." << endl; }
};

class Cat : public Animal
{
public:
	void Sound() { cout << "具克.." << endl; }

};

void main()
{
	Animal *p[10];
	p[0]	= new Dog;		p[1] = new Cat;
	p[0]->Sound();
	p[1]->Sound();

//	Dog*  d[5];
//	Cat*  d1[5];

//	d[0]	= new Dog;			d[0]->Sound();
//	d1[0]	= new Cat;			d1[0]->Sound();
}
*/



class CA
{
public:
	virtual void foo() { cout << "CA" << endl; }
};

class CB : public CA
{
public:
	virtual void foo() { cout << "CB" << endl; }
};

void foo(CA *p1, CA& p2, CA p3)
{
	p1->foo();

	p2.foo();

	p3.foo();		// CA 
}

void main()
{
	CB		b;			foo(&b, b, b);
//	b.foo();		// CB
}

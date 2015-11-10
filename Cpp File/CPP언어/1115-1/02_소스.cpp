#include <iostream>
using namespace std;

class CA
{
	int num1;
	int num2;
public:
	CA(int _n1, int _n2 ) : num1(_n1), num2(_n2) {}
//	void DataPrint() { cout << num1 << " : " << num2 << endl; }

	friend ostream operator<<( ostream & os, CA ca);
};

ostream operator<<( ostream & os, CA ca)
{
	return os << ca.num1 << " : " << ca.num2 << endl; 
}

void main()
{
	CA		a(10, 20);		//a.DataPrint();

	cout << a;	// cout.operator<<( a );
				// operator<<( cout, a);
}


/*
#include <iostream.h>
#include <stdio.h>
class MyOstream
{
public:
	MyOstream& operator<<(int n) { printf("%d", n); return *this; }
	MyOstream& operator<<(char ch) { printf("%c", ch); return *this; }
	MyOstream& operator<<(char* ch) { printf("%s", ch); return *this; }
};

void main()
{
	cout;
	MyOstream cout;		
	cout << 10 << ' ' << "TEST ";
	
}
*/
/*
#include <iostream.h>

// ostream& (*_f)(ostream&)
ostream& twoendl(ostream &os)
{
	return os << "\n\n";
}

ostream& twotab(ostream &os)
{
	return os << "\t\t";
}

void main()
{
	cout << "TEST" << twotab; 
	cout << "TEST" << endl; 
}
*/
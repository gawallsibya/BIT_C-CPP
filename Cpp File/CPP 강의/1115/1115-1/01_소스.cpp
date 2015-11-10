//-------------------------------------------------------------------------
// 연산자 재정의
//-------------------------------------------------------------------------

/*
10 + 3i 
2  + 2i
-----------
12 + 5i
*/

#include <iostream>
using namespace std;

/*
class Complex
{
	int real;
	int image;
public:
	Complex(){}
	Complex(int _r, int _i) : real(_r), image(_i) {}

//	Complex Add(const Complex & rhs)
	Complex operator+(const Complex & rhs)
	{
		Complex temp;
		temp.real	= real + rhs.real;
		temp.image  = image + rhs.image;
		return temp;
	}
	void DataPrint()		{ cout << real << " + " << image << "i" << endl;}
	friend Complex operator-(const Complex & rhs1, const Complex & rhs2);
};

Complex operator-(const Complex & rhs1, const Complex & rhs2)
{
		Complex temp;
		temp.real	= rhs1.real - rhs2.real;
		temp.image  = rhs1.image - rhs2.image;
		return temp;
}


void main()
{
	Complex com1(10, 2);		// 10+2i
	Complex com2(20, 2);		// 20+2i
	Complex com3;
	
//	com3	= com1.Add(com2);
	com3    = com1 + com2;		// com1.operator+( com2 );
	com3	= com1 - com2;		// operator-(com1, com2);
	com3.DataPrint();
}
*/

/*
class Complex
{
	int real;
	int image;
public:
	Complex(){}
	Complex(int _r, int _i) : real(_r), image(_i) {}

	Complex operator++()
	{
		real++;		image++;
		return *this;
	}
};



void main()
{
//	int num1 = 10;
//	++++num1;		// num1 = 12 ==> ++num1 ==> ++num1

	Complex com1(10, 2);		// 10+2i
	
	++++com1;		// com1.operator++()
}
*/

// 후위
class Complex
{
	int real;
	int image;
public:
	Complex(){}
	Complex(int _r, int _i) : real(_r), image(_i) {}

	Complex operator++(int)
	{
		Complex temp(real, image);
		real++;		image++;
		return temp;
	}
};



void main()
{
	int num1 = 10;
	int num2	= num1++;		// num2 = 10 , num1 = 11

}
#include <iostream>
using namespace std;
/*
class CA
{
	int num;
public:
	int GetNum()   const;

	void SetNum(int n)  const;
	void SetNum1(int n)					
	{
		n = 100;
		num = 100;
	}
};

void CA::SetNum(int n) const
{
	n = 100;		// ok....
}

int CA::GetNum() const	
{
	SetNum(10);			// ok
	SetNum1(10);		// error
	num++;			    // error..
	return num;
}

void main()
{
	CA  a;		a.GetNum();

	const CA a1;		a1.SetNum1(10);	//error...
}
*/

class CA
{
public:
	int num;

	int GetNum() const 	// 상수 맴버 함수
	{ 
		return num;		
	}

	const int* GetNum1() const
	{ 
		return &num;		
	}
};

void main()
{
	CA		a;		const	int *p = a.GetNum1();		//*p = 100;

	cout << a.num << endl; 
}
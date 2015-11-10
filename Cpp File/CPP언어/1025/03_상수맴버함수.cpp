#include <iostream>
using namespace std;
/*
class CA
{
	int num;
public:
	int GetNum()   const;

	void SetNum(int n)  const;
	void SetNum1(int n)					{ n = 100;  num = 100;   }
};

void CA::SetNum(int n) const
{
	n = 100;		// ok....
}

// 상수 맴버 함수 : 해당 함수 내부에서 맴버 변수의 수정 불가.
//                  함수 내부에서는 상수 맴버 함수만 호출 가능.
int CA::GetNum() const	
{
	SetNum(10);			// ok
//	SetNum1(10);		// error
//	num++;			    // error..
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

public:
	int GetNum() const { return num;		}	// 상수 맴버 함수

	 const int* GetNum1() const { return &num;		}
};

void main()
{
	CA		a;		const	int *p = a.GetNum1();		//*p = 100;

	cout << a.num << endl; 
}
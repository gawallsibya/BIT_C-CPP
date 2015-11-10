#include <iostream>
using namespace std;

class CA
{
	int num;
	char name[20];
public:
	CA()
	{
		cout << "CA()" << endl;
	}

	CA( int _num, char* _name) 
	{ 
		num = _num;  strcpy(name, _name); 
		cout << "CA(int, char*)" << endl; 	
	}

	void DataPrint() const
	{
		cout << num << " : " << name << endl;
	}
};

void main()
{
//	CA	 a;								// 인스턴스 : 1
//	CA  a1[10] = { CA(10,"김길동")};	// 인스턴스 : 10

	CA *pA;								// 인스턴스 XXXX
	pA= new CA(10, "김길동");			// 인스턴스 : 1
	pA->DataPrint();
	delete pA;

//	CA *pA[10];
//	pA[0] = new CA(10, "김길동");
}
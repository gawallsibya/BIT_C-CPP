#include <iostream>
using namespace std;

class CA
{
	int num;
	char ch;

public:
	CA(int _num, char _ch)  
	{ 
		num = _num;    
		ch = _ch;  
		cout <<"생성자" <<endl;
		cout << num << " : " << ch << endl; 
	}
/*
	CA(const CA & rhs) // = CA(CA rhs)
	{
		cout << "복사 생성자" << endl; 
		num = rhs.num;
		ch  = rhs.ch;
	}

	void DataPrint() const
	{
		cout << num << " : " << ch << endl; 
	}*/
};

void main()
{
	CA a(10, 'a');
//	a.DataPrint();
//	CA b(a);
//	b.DataPrint();
}

/*
class CA
{
	char *pName;
	int   age;

public:
	CA( char *_name, int _age)
	{
		age = _age;
		pName = new char[strlen(_name)+1];
		strcpy(pName, _name);
	}

	CA(  const CA & rhs )
	{
		age		= rhs.age;
		pName	= rhs.pName;
		pName	= new char[strlen(rhs.pName)+1];
		strcpy(pName, rhs.pName);
	}

	void SetName(char* _name)  
	{ 
		strcpy(pName, _name);	
	}

	void DataPrint() const 
	{
		cout << pName << " : " << age << endl; 
	}
};

void main()
{
	CA  data("홍길동", 10);		data.DataPrint();

	CA  data1(data);			data1.DataPrint();

	data.SetName("김길동");		data.DataPrint();
								data1.DataPrint();
}*/
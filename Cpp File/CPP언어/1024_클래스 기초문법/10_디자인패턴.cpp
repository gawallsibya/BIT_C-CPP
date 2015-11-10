/**********************************************************
 [������ ���� ] 
**********************************************************/
/*

========================================================
 Singletone
=========================================================
 ���� 1���� ��ü���� ���� �� �ִ� Ŭ����
 Private ������
 ���� �� ������ �����Ѵ�.
 1���� instance�� ���� ���ִ� static ����Լ�

#include <iostream>
using namespace std;

class Singleton
{
private:
	Singleton() {}
	Singleton(const Singleton&);
	void operator=(const Singleton&);
public:
	static Singleton& get_instance()
	{
		static Singleton _instance;
		return _instance;
	}
};
void main()
{
	Singleton& s1 = Singleton::get_instance();
	Singleton& s2 = Singleton::get_instance();
	cout << &s1 << endl;
	cout << &s2 << endl;
}

*/

/*
========================================================
 Monostate
=========================================================
 ��ü�� ������ �ʿ䰡 ����.
   - Private ������
 ���� �ִ� �Լ��� �ϳ��� ��� ����

class Math
{
private:
	Math(); // Only Declaration.! No definition
public:
	static int Plus(int a, int b) 
	{ 
		return a+b;
	}
	static int Minus(int a, int b)
	{
		return a-b;
	}
	static int Multiply(int a, int b)
	{
		return a*b;
	}
};
void main()
{
	int n = Math::Plus( 10 ,20 );
	cout << n << endl;
}

-------------------------------------------------
========================================================
 example
=========================================================

  1. ���� ���� ���� ���� �� ������ ������ �����غ�����. 
  �׸��� �Ʒ� ����� �� static ����� �ٲپ�� �� �κ��� 
  ã�Ƽ� �ٲټ���.

class Car
{
public:
	enum CARNAME { FERRARI = 1, BENZ, BMW, LEXUS };

	Car( CARNAME n) : name(n) {}
	const char* GetName() { return carname[name];}

	void Go() { cout << "~~~~~~" << endl;}
private:
	const char* carname[4] = { "Ferrai", "Benz", "BMW", "Lexus" }; // Error
	CARNAME name;
};

void main()
{
	Car c(Car::LEXUS );
	cout << c.GetName() << endl;
	c.Go();
}


*/
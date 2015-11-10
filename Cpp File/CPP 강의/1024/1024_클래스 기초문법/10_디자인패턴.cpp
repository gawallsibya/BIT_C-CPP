/**********************************************************
 [디자인 패턴 ] 
**********************************************************/
/*

========================================================
 Singletone
=========================================================
 오직 1개의 객체만을 만들 수 있는 클래스
 Private 생성자
 복사 와 대입을 금지한다.
 1개의 instance를 리턴 해주는 static 멤버함수

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
 객체를 생성할 필요가 없다.
   - Private 생성자
 관련 있는 함수를 하나로 묶어서 관리

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

  1. 다음 에러 나는 곳이 왜 에러가 나는지 생각해보세요. 
  그리고 아래 멤버들 중 static 멤버로 바꾸어야 할 부분을 
  찾아서 바꾸세요.

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
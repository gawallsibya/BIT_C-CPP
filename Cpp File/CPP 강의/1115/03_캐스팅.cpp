//〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓
//  [ ex ] 클래스에서 
//〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓

/*
//──────────────────────────────────
//	[ static_cast ]
//──────────────────────────────────

  // A와 B가 기초, 파생 클래스 관계일 경우 
  A		a;
  B		b;

  A *pA = static_cast<A*>(&b);		// ok
  B *pB = static_cast<*B>(&a);		// ok
  C *pC = statkc_cast<*C> (&a);		// error


//──────────────────────────────────
//	[ reinterpret_cast ]
//──────────────────────────────────

  편법적인 일을 수행하는 cating 기법 

  struct aa { short a;  shor b; }
  long value = 0xa224b118;

  aa *pb = reinterpret_cast<aa*>(&value);
  cout << pb->a;								// 처음 2byte를 출력 
*/




//──────────────────────────────────
//	[ ex ] 상속과 casting
//──────────────────────────────────

#include <iostream>	
using namespace std;


class AAA 
{ 
public: 
	int x;
};	
class BBB 
{ 
public: 
	int y;
};

// 다중 상속
class CCC : public AAA, public BBB
{	
public:		
	int z;		
};

void main()
{
	CCC c;	// &c == 100이라면
	c.x = 10;	c.y = 10;		c.z = 10;
	AAA* p1 = (AAA*)&c;						//  p1 == 100이고

	BBB *p2 = (BBB*)&c;						//  p2 == 104

	BBB* p3 = static_cast<BBB*>(&c);		// p2 == 104임.

	BBB* p4 = reinterpret_cast<BBB*>(&c);	// p3 == 100

	cout << p2 << " : " << p3 << " : " << p4 << endl << endl;	

	p2->y = 20;		
//	p3->y = 20;		
//	p4->y = 20;
	cout << c.x << " : " << c.y << " : " << c.z << endl;
}






/*
//──────────────────────────────────
	RTTI = Run Time Type Information(실행 시간 데이터형 정보)
//──────────────────────────────────

  상속 관계에 있는 클래스 계층
  가상 함수들을 가지고 있는 클래스 계층에 대해서만 사용 가능 
  내가 가지고 있는 포인터가 어떠한 객체를 지시하고 있는가???


//──────────────────────────────────
	[ typeid 연산자 & type_info 클래스 ]
//──────────────────────────────────

  두 객체의 데이터형이 같은지 결정 할 수 있다.
  AAA *aaa;
  if( typied( AAA) == typeid( *aaa) )

  >> 잘 사용되어지지 않는다.(거의 안씀)



*/
//──────────────────────────────────
//	[ ex ] 누구를 가리키는 포인터??
//──────────────────────────────────
/*
#include <iostream>	
using namespace std;

class Animal
{ 
public: 		
	int Age; 		
	virtual void foo() { }	
};

class Dog: public Animal	{  };

class People: public Animal	
{ 	
public: 		
	int x; 	
};

// overloading으로 각각의 나이를 만든다??
void NewYear(People* p){		p->Age++;	}

void NewYear(Dog* d){		d->Age++;		}


// Animal로 NewYear로 만들면 하나만 만들어도 됨.
// 하지만 어느 클래스인지 어떻게 구분하는가??
void NewYear(Animal* p)
{
	p->Age;
	((People*)p)->x++; // ???	
}
// RTTI => p가 가리키는 포인터가 Animal인지 	
// Dog인지 People인지 알수 있을까? RTTI 사용
// RTTI는 속도와 메모리에서 overhead가 좀 있다.!!! - 아직까지는 많이 사용 안됨..!!

void main()
{
	People p;
	NewYear(&p);
	Dog d;
	NewYear(&d);
}
*/

//──────────────────────────────────
//	[ ex ] 누구를 가리키는 포인터??
//  방법 1. typedid() 연산자 사용 
//──────────────────────────────────
/*
#include <iostream>	
#include <typeinfo.h>		// RTTI를 사용하기 위한 H 포함
							// project setting -> C++(C++Language)
using namespace std;

class Animal
{ 
public: 		
	int Age; 		
	virtual void foo() { }	
};

class Dog: public Animal	
{
public:
	int y;
};

class People: public Animal	
{ 	
public: 		
	int x; 	
};


void NewYear(Animal* p)
{
//	p->Age;
//	((People*)p)->x++; // ???	

	//----------------------------------------------
	const type_info& r = typeid(*p);	// typeinfo.h 있어야됨.
	cout << r.name() << endl;			// 클래스 이름 찍힘

	if(typeid(*p) == typeid(People))
	{
		cout << "People 맞네...	" << endl;
		((People*)p)->x++ ;
	}		
	else if( typeid(*p) == typeid(Dog))
	{
		cout << "Dog 맞네..." << endl;
		((Dog*)p)->y++;
	}
	//---------------------------------------------
}

void main()
{
	People p;
	NewYear(&p);
	Dog d;
	NewYear(&d);
}
*/


//──────────────────────────────────
//	[ ex ] 누구를 가리키는 포인터??
//  방법 2. dynamic_cast 중요함. 잘알아둘 것.
//──────────────────────────────────
/*
#include <iostream>	
#include <typeinfo.h>		// RTTI를 사용하기 위한 H 포함
							// project setting -> C++(C++Language)
using namespace std;

class Animal
{ 
public: 		
	int Age; 		
	virtual void foo() { }	
};

class Dog: public Animal	
{
public:
	int y;
};

class People: public Animal	
{ 	
public: 		
	int x; 	
};


void NewYear(Animal* p)
{
//	p->Age;
//	((People*)p)->x++; // ???	

	//----------------------------------------------
	People* pp = dynamic_cast<People*>(p);
	if(pp != 0)
	{ // p 는 People를 가리킨다.
		cout << " People 정말 맞네..." << endl;
		pp->x++; 
	}

	//---------------------------------------------
}

void main()
{
	People p;
	NewYear(&p);
	Dog d;
	NewYear(&d);
}
*/
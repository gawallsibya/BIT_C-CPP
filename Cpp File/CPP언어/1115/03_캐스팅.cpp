//�����������������������������������
//  [ ex ] Ŭ�������� 
//�����������������������������������

/*
//��������������������������������������������������������������������
//	[ static_cast ]
//��������������������������������������������������������������������

  // A�� B�� ����, �Ļ� Ŭ���� ������ ��� 
  A		a;
  B		b;

  A *pA = static_cast<A*>(&b);		// ok
  B *pB = static_cast<*B>(&a);		// ok
  C *pC = statkc_cast<*C> (&a);		// error


//��������������������������������������������������������������������
//	[ reinterpret_cast ]
//��������������������������������������������������������������������

  ������� ���� �����ϴ� cating ��� 

  struct aa { short a;  shor b; }
  long value = 0xa224b118;

  aa *pb = reinterpret_cast<aa*>(&value);
  cout << pb->a;								// ó�� 2byte�� ��� 
*/




//��������������������������������������������������������������������
//	[ ex ] ��Ӱ� casting
//��������������������������������������������������������������������

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

// ���� ���
class CCC : public AAA, public BBB
{	
public:		
	int z;		
};

void main()
{
	CCC c;	// &c == 100�̶��
	c.x = 10;	c.y = 10;		c.z = 10;
	AAA* p1 = (AAA*)&c;						//  p1 == 100�̰�

	BBB *p2 = (BBB*)&c;						//  p2 == 104

	BBB* p3 = static_cast<BBB*>(&c);		// p2 == 104��.

	BBB* p4 = reinterpret_cast<BBB*>(&c);	// p3 == 100

	cout << p2 << " : " << p3 << " : " << p4 << endl << endl;	

	p2->y = 20;		
//	p3->y = 20;		
//	p4->y = 20;
	cout << c.x << " : " << c.y << " : " << c.z << endl;
}






/*
//��������������������������������������������������������������������
	RTTI = Run Time Type Information(���� �ð� �������� ����)
//��������������������������������������������������������������������

  ��� ���迡 �ִ� Ŭ���� ����
  ���� �Լ����� ������ �ִ� Ŭ���� ������ ���ؼ��� ��� ���� 
  ���� ������ �ִ� �����Ͱ� ��� ��ü�� �����ϰ� �ִ°�???


//��������������������������������������������������������������������
	[ typeid ������ & type_info Ŭ���� ]
//��������������������������������������������������������������������

  �� ��ü�� ���������� ������ ���� �� �� �ִ�.
  AAA *aaa;
  if( typied( AAA) == typeid( *aaa) )

  >> �� ���Ǿ����� �ʴ´�.(���� �Ⱦ�)



*/
//��������������������������������������������������������������������
//	[ ex ] ������ ����Ű�� ������??
//��������������������������������������������������������������������
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

// overloading���� ������ ���̸� �����??
void NewYear(People* p){		p->Age++;	}

void NewYear(Dog* d){		d->Age++;		}


// Animal�� NewYear�� ����� �ϳ��� ���� ��.
// ������ ��� Ŭ�������� ��� �����ϴ°�??
void NewYear(Animal* p)
{
	p->Age;
	((People*)p)->x++; // ???	
}
// RTTI => p�� ����Ű�� �����Ͱ� Animal���� 	
// Dog���� People���� �˼� ������? RTTI ���
// RTTI�� �ӵ��� �޸𸮿��� overhead�� �� �ִ�.!!! - ���������� ���� ��� �ȵ�..!!

void main()
{
	People p;
	NewYear(&p);
	Dog d;
	NewYear(&d);
}
*/

//��������������������������������������������������������������������
//	[ ex ] ������ ����Ű�� ������??
//  ��� 1. typedid() ������ ��� 
//��������������������������������������������������������������������
/*
#include <iostream>	
#include <typeinfo.h>		// RTTI�� ����ϱ� ���� H ����
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
	const type_info& r = typeid(*p);	// typeinfo.h �־�ߵ�.
	cout << r.name() << endl;			// Ŭ���� �̸� ����

	if(typeid(*p) == typeid(People))
	{
		cout << "People �³�...	" << endl;
		((People*)p)->x++ ;
	}		
	else if( typeid(*p) == typeid(Dog))
	{
		cout << "Dog �³�..." << endl;
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


//��������������������������������������������������������������������
//	[ ex ] ������ ����Ű�� ������??
//  ��� 2. dynamic_cast �߿���. �߾˾Ƶ� ��.
//��������������������������������������������������������������������
/*
#include <iostream>	
#include <typeinfo.h>		// RTTI�� ����ϱ� ���� H ����
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
	{ // p �� People�� ����Ų��.
		cout << " People ���� �³�..." << endl;
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
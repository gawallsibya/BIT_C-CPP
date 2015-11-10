/**********************************************************
 [ Class Declaration ] 
**********************************************************/
/*
 다른 class 의 객체가 멤버로 포함 될때
  - 반드시 해당 클래스의 완전한 선언 부분이 필요하다.
  - #include < … >

 다른 class를 가르키는 포인터가 멤버로 포함 될때
  - class classname;
  - 헤더를 include 할 필요가 없다.

class B; // class Declaration

class A
{
	B* pb; // Ok..
	B  obj; // Error
	//......;
};

class B
{

};

void main()
{

}

  ---------------------------------------
*) class Declaratin VS include "Header"

어떤 클래스가 다른 클래스의 포인터형 변수를 멤버로 
포함 하고 있을 때는 헤더 파일을 include 하지 않아도 된다.

  // A.h
#ifndef A_H
#define A_H

class A
{
public:
	void foo() {}
};
#endif // A_H
---------------------------------
// B.h
#ifndef B_H
#define B_H

class A;
class B
{
	A* pa; // OK
public:
	void goo();
};
#endif  // B_H
-------------------------------
// B.cpp
#include “A.h”
#include “B.h”

void B::goo()
{
	pa = new A;	// must inlcude “A.h”
	pa->foo();	// must inlcude “A.h”
}


*/

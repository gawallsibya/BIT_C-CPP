/**********************************************************
 [ Class Declaration ] 
**********************************************************/
/*
 �ٸ� class �� ��ü�� ����� ���� �ɶ�
  - �ݵ�� �ش� Ŭ������ ������ ���� �κ��� �ʿ��ϴ�.
  - #include < �� >

 �ٸ� class�� ����Ű�� �����Ͱ� ����� ���� �ɶ�
  - class classname;
  - ����� include �� �ʿ䰡 ����.

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

� Ŭ������ �ٸ� Ŭ������ �������� ������ ����� 
���� �ϰ� ���� ���� ��� ������ include ���� �ʾƵ� �ȴ�.

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
#include ��A.h��
#include ��B.h��

void B::goo()
{
	pa = new A;	// must inlcude ��A.h��
	pa->foo();	// must inlcude ��A.h��
}


*/

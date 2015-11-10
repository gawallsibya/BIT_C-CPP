/**********************************************************
 [ 맴버함수의 외부정의 ] 
**********************************************************/

/*
 클래스 내부에서는 함수를 선언만 하고 구현은 클래스 외부에서 
 주로 만든다.
 클래스 내부에서 함수를 직접 구현할 경우 inline함수가 된다.

 주로 클래스 선언부분은 헤더파일로 만들고  
 멤버 함수 구현 부분은 .cpp 파일로 만든다.

class Point
{
private:
	int x;
	int y;

public:
	Point( int _x = 0, int _y = 0);
	void Print();
};

Point::Point( int _x, int _y) : x(_x), y(_y)
{

}

void Point::Print()
{
	cout << x << ", " << y << endl;
}


==========================================================
// Point.h

#ifndef POINT_H
#define POINT_H

class Point
{
private:
	int x;
	int y;

public:
	Point( int _x = 0, int _y= 0);
	void Print();
};
#endif

  -------------------------------------
// Point.cpp

  #include "Point.h"
#include <iostream>
using namespace std;

Point::Point( int _x, int _y) : x(_x), y(_y)
{
}
void Point::Print()
{
	cout << x << ", " << y << endl;
}
 --------------------------
// Main.cpp

#include "Point.h"
#include <iostream>
using namespace std;

void main()
{
	Point p(1,2);
	p.Print();
}

*/
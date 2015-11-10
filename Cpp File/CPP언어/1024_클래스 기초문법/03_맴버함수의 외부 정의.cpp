/**********************************************************
 [ �ɹ��Լ��� �ܺ����� ] 
**********************************************************/

/*
 Ŭ���� ���ο����� �Լ��� ���� �ϰ� ������ Ŭ���� �ܺο��� 
 �ַ� �����.
 Ŭ���� ���ο��� �Լ��� ���� ������ ��� inline�Լ��� �ȴ�.

 �ַ� Ŭ���� ����κ��� ������Ϸ� �����  
 ��� �Լ� ���� �κ��� .cpp ���Ϸ� �����.

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
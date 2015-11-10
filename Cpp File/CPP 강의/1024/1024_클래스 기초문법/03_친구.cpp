/**********************************************************
 [ friend ] 
**********************************************************/
/*
 - Private ����� ���� �� �� �ִ� �Ϲ� �Լ�.
 - ��������, ĸ��ȭ�� ��Ģ�� ������ �ǹǷ� �ǵ��� ������� 
   �ʴ´�.
 - ������ �����ǿ��� �ַ� ���ȴ�.

 - friend function
 - friend member function
 - friend class


class Point
{
private:
	int x;
	int y;

public:
	Point( int _x = 0, int _y = 0) : x(_x), y(_y) {}

	friend void print( const Point& );
};

void print( const Point& p)
{
	cout << "(" << p.x << ", " << p.y << ")" << endl;
}
void main()
{	
	Point p(3,4);
	print( p );
}

----------------------------------------------
*) friend function
   C++ ������ ��ü�� private ����� �ܺ� �Լ� ���� ���� 
   �ϴ� ���� ����� Error�̴�.
   ������ friend �Լ� ������ ��ü�� Private����� �����ϴ�
   ���� ���ȴ�. �ַ� ������ �����ǿ��� ����Ѵ�.
 
*) friend class
   friend class �� ����� �͵� �����ϴ�. 
   �Ʒ� �������� Circle �� Point �� friend class �̹Ƿ� 
   Circle �� ��� ������� Point �� privae����� x, y�� 
   �����ϴ� ���� ���ȴ�.

#include <iostream>
using namespace std;
class Point
{
private:
	int x, y; 
public:
	Point(int _x = 0,int _y = 0) : x(_x), y(_y) {}
	friend class Circle;
};

class Circle
{
private:
	Point orign;
	int radius;
public:
	Circle(Point or, int r) : orign(or),radius(r) {}
	Circle(int x, int y, int r) : orign(Point(x,y)), radius(r) {}

	void SetOrign(int x, int y)
	{
		orign.x = x;
		orign.y = y;
	}
};

void main()
{
	Circle c( 10, 10,5);
	c.SetOrign( 2,2);
}

*/
/**********************************************************
 [ const member function ] 
**********************************************************/

/*
 ��� ������ ���� �ٲ� �� ����.
 ��� ��� data�� ��� ��޵ȴ�.
 ����Լ� ������ �� ��� �Լ��� ȣ���� �� ����.
 �Լ��� ����� ������ ��� const�� ����� �Ѵ�.

class Point
{
private:
	int x;
	int y;
public:
	void Set(int _x, int _y)
	{
		x = _x;
		y = _y;
	}
	void Print() const
	{
		x = 0;  // error Can't Modify
		y = 0;  // error Can't Modify

		cout << x << ", " 
		      << y << endl; // Ok

		Set(0, 0); // error
	}
};

  -----------------------------------
1. ��� �Լ� �ڿ� const�� �ٴ� �Լ��� ����Լ� ��� �Ѵ�. 
  ��� �Լ� �ȿ����� Ŭ�������� ������� ���� �ٲٴ� ���� 
  ������ �ʴ´�.
 
2. ��� �Լ� ������ �� ��� �Լ��� ȣ���� �� ����.
3. ����Լ� ������ ��� ��� data�� const ��޵ȴ�. ��,
	class Point
	{
	private:	int x,y; 
	public:
		int* foo() const
		{
			return &x; // Error 
		}
	};
4. ���������� ��� ��� �Լ��� Ŭ���� �ܺο��� ���� �� 
   ���� ����� ������ ��� const�� ����� �Ѵ�.
	class Point
	{
		void foo() const;
	};
	void Point::foo() const
	{
	}



*/

/*
============================================================
 ��� �Լ��� �ʿ��� ���� 
============================================================
 ��ü�� const�� ������ ��� ��� �Լ��� ȣ���� �� �ִ�.

 Const�� ������ ��ü�� ��� data�� ������ �� ������ 
 ��� data�� ���� ���� �� �� �־�� �Ѵ�.

 �����̸��� ���� ��� �Լ��� �� ��� �Լ��� ���� �� �ִ�.

 class Point
{
public:
	int x, y;

	Point( int _x = 0, int _y = 0) : x(_x), y(_y) {}
	
	void Set(int _x, int _y)  {  x = _x; y = _y; }

	void print()
	{ 	cout << x << ", " << y << endl;	}

	void foo() {}
	void foo() const {}
};
void main()
{
	const Point p(1,2);

	p.x = 10;     	// Error
	p.Set( 0, 0); 	// Error
	p.print();    	// ??
	p.foo();	 	// ??
}

  -----------------------------------------

��� ��ü�� const�� ������ ���, �ش� ��ü�� 
���data ���� �ٲ� �� ����. 
���� Const Object�� �� ��� �Լ��� ȣ���� ���� ����.

	const Point p(1,2);
	p.x = 10; // Error
	p.print(); // error �� ��� �Լ� ȣ��

	point ��ü�� Const�� ������ ���� �ϴ��� 
	����ڴ� x,y���� ����Ҽ��� �־�� �Ѵ�.. 
	��, print()�� �ݵ�� ��� �Լ��� �����Ǿ�� �Ѵ�.

	void printf() const 
	{ ��
	}

�����̸��� ���� ��� �Լ��� �� ��� �Լ��� ���ÿ� 
���� �� �ִ�. �̶� ��� ��ü�� ��� �Լ��� �� ��� ��ü�� �� 
��� �Լ��� ȣ���Ѵ�.

	Class Point
	{
	public:
		void foo() const;  // ��� �Լ�
		void foo();	        // �� ��� �Լ�
	}

	Point p1;
	const Point p2;
	p1.foo();  // �� ��� �Լ� ȣ��
	p2.foo();  // ��� �Լ� ȣ��

*/

/*
========================================================
 ���� Ŭ������ ����Լ��� �߿��� ��� �Լ��� �ٲپ�� 
 �� ���� ã�� �ٲپ� ������
========================================================
class Rect
{
private:
	int left;
	int top;
	int right;
	int bottom;

public:
	Rect(int l = 0, int t = 0, int r= 0, int b = 0) : left(l), top(t), right(r), bottom(b) {}

	void SetRect( int l, int t, int r, int b)  
	{
		left   = l;
		top    = t;
		right  = r;
		bottom = b;
	}
	int GetArea()
	{
		return ( right - left ) * ( bottom - top );
	}
	int GetWidth()
	{
		return ( right - left );
	}
	void Inflate(int dx, int dy)
	{
		right += dx;
		bottom += dy;
	}
	void Move( int dx, int dy)
	{
		left	+= dx;
		right	+= dx;
		top		+= dy;
		bottom	+= dy;
	}
	bool PtInRect( int x, int y)
	{
		if ( ( x >= left) && ( x <= right) &&
		     ( y >= top ) && ( y <= bottom ) )
			 return true;
		return false;
	}
};
*/
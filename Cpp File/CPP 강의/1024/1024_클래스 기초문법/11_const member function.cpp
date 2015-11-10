/**********************************************************
 [ const member function ] 
**********************************************************/

/*
 멤버 변수의 값을 바꿀 수 없다.
 모든 멤버 data는 상수 취급된다.
 상수함수 내에서 비 상수 함수를 호출할 수 없다.
 함수의 선언과 구현에 모두 const를 적어야 한다.

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
1. 멤버 함수 뒤에 const가 붙는 함수를 상수함수 라고 한다. 
  상수 함수 안에서는 클래스내의 멤버변수 값을 바꾸는 것을 
  허용되지 않는다.
 
2. 상수 함수 내에서 비 상수 함수를 호출할 수 없다.
3. 상수함수 내에서 모든 멤버 data는 const 취급된다. 즉,
	class Point
	{
	private:	int x,y; 
	public:
		int* foo() const
		{
			return &x; // Error 
		}
	};
4. 마지막으로 상수 멤버 함수를 클래스 외부에서 정의 할 
   때는 선언과 구현에 모두 const를 적어야 한다.
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
 상수 함수가 필요한 이유 
============================================================
 객체가 const로 생성된 경우 상수 함수만 호출할 수 있다.

 Const로 생성된 객체의 멤버 data를 변경할 수 없지만 
 멤버 data의 값을 얻을 수 는 있어야 한다.

 동일이름을 가진 상수 함수와 비 상수 함수를 만들 수 있다.

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

어떠한 객체를 const로 생성할 경우, 해당 객체의 
멤버data 값을 바꿀 수 없다. 
또한 Const Object는 비 상수 함수를 호출할 수도 없다.

	const Point p(1,2);
	p.x = 10; // Error
	p.print(); // error 비 상수 함수 호출

	point 객체가 Const로 생성된 경우라 하더라도 
	사용자는 x,y값을 출력할수는 있어야 한다.. 
	즉, print()는 반드시 상수 함수로 구현되어야 한다.

	void printf() const 
	{ …
	}

동일이름을 가진 상수 함수와 비 상수 함수를 동시에 
만들 수 있다. 이때 상수 객체는 상수 함수를 비 상수 객체는 비 
상수 함수를 호출한다.

	Class Point
	{
	public:
		void foo() const;  // 상수 함수
		void foo();	        // 비 상수 함수
	}

	Point p1;
	const Point p2;
	p1.foo();  // 비 상수 함수 호출
	p2.foo();  // 상수 함수 호출

*/

/*
========================================================
 다음 클래스의 멤버함수들 중에서 상수 함수로 바꾸어야 
 할 곳을 찾아 바꾸어 보세요
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
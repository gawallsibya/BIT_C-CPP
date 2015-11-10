/**********************************************************
 [ static member function ] 
**********************************************************/
/*
 객체 없이 호출할 수 있는 멤버 함수
 Class이름::함수이름()

 일반 멤버함수를 호출하려면 반드시 객체가 필요하다.

 멤버 함수를 외부에 구현할 경우 함수선언에만static을 표시


class Point
{
private:
	int x, y;
	static int count;
public:
	Point( int _x=0, int _y=0) : x(_x), y(_y) {++count;}
	~Point() { --count;}

	void print() const
	{
		cout << x << ", " << y << endl;
	}
	static int GetCount() { return count;}
};

int Point::count = 0;

void main()
{
	cout << Point::print()	<< endl;  // Error 객체가 필요하다.
	cout << Point::GetCount() << endl;// Ok
}

  ------------------------------------------
  Static 멤버 함수는 객체 없이 호출할 수 있는 함수이다. 
  객체가 없으므로 static 멤버 변수가 아닌 어떤 멤버 변수도
  메모리에 잡혀 있지 않다. 
  그래서 static 멤버 함수 내에서는 Static 멤버 data만 
  접근할 수 있다. 
  Static 멤버 함수만 호출할 수 있다.
  this를 사용할 수 없다.(객체가 없으므로 당연하다.)

class Test
{
private:
	int one;
	static int two;

public:
	void foo()
	{
		one = 10; // Ok
		two = 10; // ok
	}
	static void goo()
	{
		one = 10; // Error
		two = 10; // Ok
		cout << this << endl; // Error
	}
};
int Test::two = 0;

[ 연습 문제 ] 

Static 멤버 함수와 전역함수를 비교해 보자. 

*/
/**********************************************************
 [ static member data ] 
**********************************************************/
/*
 동일한 클래스의 모든 객체가 공유하는 변수
class Point
{
public:
	int x;
	int y;
	static int count;

	Point( int _x, int _y) : x(_x), y(_y) {}
};
int Point::count = 0;

void main()
{
	cout << Point::count << endl;

	Point p1(1,1);
	Point p2(2,2);
	p1.x	 	= 10;
	p1.count	= 20;

	cout << p2.x	 	<< endl;
	cout << p2.count 	<< endl;
	cout << sizeof(p1) << endl;
}
-------------------------------------------------
*) Static member data

   동일한 class의 모든 객체가 공유하는 멤버를 만들수 있다. 

   - 반드시 클래스 외부에(구현 파일에서)서 정의되어야 한다.
   - 객체를 1개도 생성하지 않아도 메모리는 할당된다.
   - 모든 객체에 의해 공유 된다.
   - 클래스 이름과  객체 이름 모두 사용해서 접근할 수 있다.
     (하지만 되도록 클래스 이름을 사용해서 접근하는게 좋다.)

*) Static 멤버 data를 사용하면 아래처럼 생성된 
   객체의 개수를 Count할 수 있다.

class Point
{
public:
	int x, y;
	static int count;
	Point( int _x=0, int _y=0) : x(_x), y(_y) {++count;}
	~Point() { --count;}
};
int Point::count = 0;
void main()
{
	Point p1, p2;
	Point parr[5];

	cout 	<< "총 " << Point::count 
		<< "개의 점이 생성되었습니다." << endl;
}

*) static const 멤버
  클래스의 const 멤버 data는 반드시 생성자에서 콜론 
  초기화 해야 한다. 
  하지만 대부분 const는 static으로 만들어 진다.
  이때 static const 변수는 클래스의 선언부에서 초기화 
  할 수 있다. 물론 이때도 클래스의 구현 파일에서 정의 되야
  한다.
  단, 정수계열의 정적 상수만 class 내에서 초기화 할 수 있다.

class Some {
public:
	static const int sz = 10;
	char buf[sz];
};
const int Some::sz;


[ 연습 문제 ]
1. 위 Point클래스의 count를 static 멤버 대신 
   전역변수로 바꾸어 보세요.
   Static 멤버 data와 전역변수의 차이점을 생각해 보세요 
   각각의 장단점을 생각해 이야기해 보세요.

*/

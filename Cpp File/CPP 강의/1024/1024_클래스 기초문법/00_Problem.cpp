/**********************************************************
  01 문제 제시 
**********************************************************/

/*
 임의의 날짜를 입력 받아서 다음 날짜를 리턴하는 함수를 
 만들어 보자.
 Out Parameter / In Parameter
 
 코드가 복잡해진다.

void GetTomorrow(int y, int m, int d, int* ny, int* nm, int* nd)
{
	*ny 	= ......;
	*nm	= ......;
	*nd 	= ......;
}

void main()
{
	int ny, nm, nd;

	GetTomorrow(2004, 10, 25, &ny, &nm, &nd);
}

============================================================
임의의 날짜는 입력 받아 다음 날짜를 리턴 하는 함수를 만든다고
가정해 보자. 

함수는 1개의 리턴 값만을 가질 수 있다. 
그런데 날짜를 표현하려면 정수 3개가 필요하다.

어떻에 하면 함수로부터 3개의 값을 꺼내 올수 있을까 ? 
이럴경우 대부분 정수형 변수의 주소를 전달하고 함수내에서 
해당 주소에 값을 넣는 방법을 사용한다.

이 처럼 함수로 부터 값을 꺼내오기 위해 사용하는 파라미터를
Out Parameter라고 한다. 
반대로 값을 전달만 하는 파라미터를 in Parameter라고 한다.

[ 연습 문제 ] 
임의의 날짜를 입력 받아서 다음 날짜를 얻을수 있는 함수를 
만들어 보자.
(구조체를 사용하지 말고 그냥 int 를 사용해서 만들어 보자.

그리고 문제점이 무엇인지 생각해 보자.
*/




/**********************************************************
  01 문제 해결  
**********************************************************/

/*
구조체를 사용하면 사용자 정의 type을 만들 수 있다.
Type을 먼저 설계한 후 사용하면 프로그램을 훨씬 보기 좋게 
설계할 수 있다.

struct Date
{
	int year;
	int month;
	int day;
};

Date GetTomorrow( Date date )
{
	Date temp;
	//......;

	return temp;
}

void main()
{
	Date today = { 2004,10,26 };
	Date tomorrow = GetTomorrow(today);
}

============================================================
현재 프로그램을 하고 싶은 내용은 날짜에 관련된 일이다. 
하지만 C/C++에는 날짜라는 type이 없으므로 날짜 1개를 표현하기 
위해 int 변수 3개를 사용했다.
바로 이것이 프로그램을 복잡하게 하고 관리하기 힘들게 하고 있다. 

프로그램을 보다 단순화 하고 관리하기 편하기 하려면 먼저 
int 3개를 묶어서 1개의 type으로 만든 후 사용하는 것이 좋다.

C의 구조체는 사용자에게 새로운 type를 만들 수 있게 한다.


[ 연습 문제 ] 
임의의 날짜를 입력 받아서 다음 날짜를 얻을수 있는 함수를 
만들어 보자.(구조체를 사용해서 만들어 보자.)

앞장에서 만든 함수에 비해 장점이 무엇인지 생각해 보자. 
그리고 문제점이 무엇인지 생각해 보자.
*/


/**********************************************************
  02 다른 방법의 접근 ==> OOP : Encapsulation  
**********************************************************/
/*
struct
C 	: data만 넣을 수 있다.
C++ 	: data와 함수를 모두 넣을 수 있다.

함수도 구조체 안에 포함하는 것이 관리 하기 쉽다.
상태와 기능을 하나로 묶어서 새로운 type을 설계하자.
프로그램이 간결해진다.
유지보수 하기가 수월해 진다.

struct Date
{
	int year;
	int month;
	int day;

	Date GetTomorrow( )
	{
		Date temp;
		//......;
		return temp;
	}
};
void main()
{
	Date today = { 2004,10,26 };
	Date tomorrow = today.GetTomorrow();
}

============================================================
C의 구조체는 data만을 넣을 수 있지만 C++에서는 구조체 
안에 함수도 넣을 수 있다.
Data와 함수를 묶어서 새로운 type을 만드는 경우 프로그램이 
보다 간결해 지고 유지 보수 하기가 수월해 진다.

이때 data를 멤버 data라고 하고 구조체 내의 함수를 멤버함수 
라고 한다.
멤버 함수 내에서는 멤버 data를 마음대로 접근할 수 있는 
특징이 있다.

*/



/**********************************************************
  03 상태 + 기능  =  User Type  
**********************************************************/

/*
 C Style 의 코드 분석

enum DOORSTATE { OPEN=1, CLOSE, UNKNOWN };

void DoorOpen(int* state)	{*state = OPEN;}
void DoorClose(int* state) { *state = CLOSE;}

void ShowDoorState(int state) 
{ 
	cout << "Door is ";
	if ( state == OPEN) 
		cout << "Open" << endl;
	else if ( state == CLOSE) 
		cout << "Closed" << endl;
	else cout << "Unknown" << endl;
}
void main()
{
	int door = UNKNOWN;
	ShowDoorState( door );
	DoorOpen( &door);
	ShowDoorState( door );

	DoorClose( &door);
	ShowDoorState( door );
}

 ==> 코드 분석 

 상태	: 현재 문의 상태(Door)
 기능	: Open, Close, ShowState

 상태와 기능이 별개로 되어 있다.
   - 프로그램이 복잡해 보인다.
   - 유지보수가 어려워진다.

 함수 중심

===========================================================

C++ Style

아래 코드는  data와 함수를 묶어서  door 라는
새로운 type 을 만든 경우이다.

  
struct Door
{
	enum DOORSTATE { OPEN=1, CLOSE, UNKNOWN };

	int door;

	void Open() { door = OPEN;}
	void Close() { door = CLOSE;}
	void ShowState() 
	{
		cout << "Door is ";
		if ( door == OPEN) 
			cout << "Open" << endl;
		else if ( door == CLOSE)
			cout << "Closed" << endl;
		else
			cout << "Unknown" << endl;
	}
};

void main()
{
	Door door;

	door.ShowState();
	door.Open();
	door.ShowState();
	door.Close();
	door.ShowState();
}

C Style 코드와 C++ Style 코드를 비교해 보자.
객체 중심 코드의 장점을 생각해 보자. 

===========================================================
[ example 1]

아래의 코드를 객체 중심의 코드로 변경해보자.

#include <stdio.h>

typedef struct _Rect
{
	int left;
	int top;
	int right;
	int bottom;
} Rect;

int GetArea( Rect r )
{
	return ( r.right - r.left ) * ( r.bottom - r.top);
}

bool PtInRect( Rect r, int x, int y )
{
	if ( r.left < x && r.right > x &&
		 r.top  < y && r.bottom > y )
		 return true;
	return false;
}

void print( Rect r )
{
	printf("(%d, %d)~(%d, %d)\n", r.left, r.top, r.right, r.bottom);
}

void InflateRect( Rect* r, int dx, int dy)
{
	r->right  += dx;
	r->bottom += dy;
}

void main()
{
	Rect r = { 10, 10,20,20};

	InflateRect( &r, 10,10);
	print( r );

	int s = GetArea(r);

	if ( PtInRect( r, 15,15))
		printf( "(15,15) is In r\n");
}


[ example 2]

아래 만년 달력을 출력하는 C Style의  프로그램이다.
객체 중심의 코드로 변경해보자.

#include <stdio.h>
#include <memory.h>

const char DAYS[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

#define IsLeapYear( year ) ((year % 400 == 0) || (year % 100 != 0) && (year % 4 == 0))
#define CountLeapYear(year) ((year-1) / 4 - (year - 1) / 100 + ( year - 1 ) / 400 )
#define WeekOfYear( year) &&(( year + CountLeapYear(year) ) % 7)

int WeekOfMonth( int year, int month )
{
	int past = 0;
    for ( int i = 0 ; i < month - 1 ; i++) past += DAYS[i];
	if ( IsLeapYear( year ) && month > 2 ) past++;
	return ( WeekOfYear( year ) + ?past) % 7;
}

void MakeMonth( int year, int month, int* cal )
{
	memset( cal, 0, sizeof(int) * 42 );
	int d = 1;
	int week = WeekOfMonth( year, month );
	for ( int i = week ; i < week + DAYS[month-1]; i++)cal[i] = d++;
	if ( month == 2 && IsLeapYear( year ) ) cal[i] = d; // 윤년의 2월인 경우 !
}

void print_month(int year, int month )
{
	int cal[42];
	MakeMonth( year, month, cal );
	printf("\n\t\t[ %04d년 %2d월 ]\n", year, month );
	printf("Sun\tMon\tTue\tWed\tThu\tFri\tSat");
	for ( int i = 0; i < 42; i++)
	{
		if ( cal[i] != 0 )
			printf( "%d", cal[i] );
		if ( i%7 == 0 )
			printf("\n");
		else printf("\t");
	}
	printf("\n===================================================\n");
}

void main()
{
	int year, month;
	while(1)
	{
		printf("원하는 년, 월을 입력해 주세요( 예:2004 5 종료는 -1.) =>");
		scanf("%d", &year );
		if ( year == -1 ) break;
		scanf("%d", &month);
		print_month(year, month);
	}
}
*/
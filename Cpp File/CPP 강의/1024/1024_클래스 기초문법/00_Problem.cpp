/**********************************************************
  01 ���� ���� 
**********************************************************/

/*
 ������ ��¥�� �Է� �޾Ƽ� ���� ��¥�� �����ϴ� �Լ��� 
 ����� ����.
 Out Parameter / In Parameter
 
 �ڵ尡 ����������.

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
������ ��¥�� �Է� �޾� ���� ��¥�� ���� �ϴ� �Լ��� ����ٰ�
������ ����. 

�Լ��� 1���� ���� ������ ���� �� �ִ�. 
�׷��� ��¥�� ǥ���Ϸ��� ���� 3���� �ʿ��ϴ�.

��� �ϸ� �Լ��κ��� 3���� ���� ���� �ü� ������ ? 
�̷���� ��κ� ������ ������ �ּҸ� �����ϰ� �Լ������� 
�ش� �ּҿ� ���� �ִ� ����� ����Ѵ�.

�� ó�� �Լ��� ���� ���� �������� ���� ����ϴ� �Ķ���͸�
Out Parameter��� �Ѵ�. 
�ݴ�� ���� ���޸� �ϴ� �Ķ���͸� in Parameter��� �Ѵ�.

[ ���� ���� ] 
������ ��¥�� �Է� �޾Ƽ� ���� ��¥�� ������ �ִ� �Լ��� 
����� ����.
(����ü�� ������� ���� �׳� int �� ����ؼ� ����� ����.

�׸��� �������� �������� ������ ����.
*/




/**********************************************************
  01 ���� �ذ�  
**********************************************************/

/*
����ü�� ����ϸ� ����� ���� type�� ���� �� �ִ�.
Type�� ���� ������ �� ����ϸ� ���α׷��� �ξ� ���� ���� 
������ �� �ִ�.

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
���� ���α׷��� �ϰ� ���� ������ ��¥�� ���õ� ���̴�. 
������ C/C++���� ��¥��� type�� �����Ƿ� ��¥ 1���� ǥ���ϱ� 
���� int ���� 3���� ����ߴ�.
�ٷ� �̰��� ���α׷��� �����ϰ� �ϰ� �����ϱ� ����� �ϰ� �ִ�. 

���α׷��� ���� �ܼ�ȭ �ϰ� �����ϱ� ���ϱ� �Ϸ��� ���� 
int 3���� ��� 1���� type���� ���� �� ����ϴ� ���� ����.

C�� ����ü�� ����ڿ��� ���ο� type�� ���� �� �ְ� �Ѵ�.


[ ���� ���� ] 
������ ��¥�� �Է� �޾Ƽ� ���� ��¥�� ������ �ִ� �Լ��� 
����� ����.(����ü�� ����ؼ� ����� ����.)

���忡�� ���� �Լ��� ���� ������ �������� ������ ����. 
�׸��� �������� �������� ������ ����.
*/


/**********************************************************
  02 �ٸ� ����� ���� ==> OOP : Encapsulation  
**********************************************************/
/*
struct
C 	: data�� ���� �� �ִ�.
C++ 	: data�� �Լ��� ��� ���� �� �ִ�.

�Լ��� ����ü �ȿ� �����ϴ� ���� ���� �ϱ� ����.
���¿� ����� �ϳ��� ��� ���ο� type�� ��������.
���α׷��� ����������.
�������� �ϱⰡ ������ ����.

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
C�� ����ü�� data���� ���� �� ������ C++������ ����ü 
�ȿ� �Լ��� ���� �� �ִ�.
Data�� �Լ��� ��� ���ο� type�� ����� ��� ���α׷��� 
���� ������ ���� ���� ���� �ϱⰡ ������ ����.

�̶� data�� ��� data��� �ϰ� ����ü ���� �Լ��� ����Լ� 
��� �Ѵ�.
��� �Լ� �������� ��� data�� ������� ������ �� �ִ� 
Ư¡�� �ִ�.

*/



/**********************************************************
  03 ���� + ���  =  User Type  
**********************************************************/

/*
 C Style �� �ڵ� �м�

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

 ==> �ڵ� �м� 

 ����	: ���� ���� ����(Door)
 ���	: Open, Close, ShowState

 ���¿� ����� ������ �Ǿ� �ִ�.
   - ���α׷��� ������ ���δ�.
   - ���������� ���������.

 �Լ� �߽�

===========================================================

C++ Style

�Ʒ� �ڵ��  data�� �Լ��� ���  door ���
���ο� type �� ���� ����̴�.

  
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

C Style �ڵ�� C++ Style �ڵ带 ���� ����.
��ü �߽� �ڵ��� ������ ������ ����. 

===========================================================
[ example 1]

�Ʒ��� �ڵ带 ��ü �߽��� �ڵ�� �����غ���.

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

�Ʒ� ���� �޷��� ����ϴ� C Style��  ���α׷��̴�.
��ü �߽��� �ڵ�� �����غ���.

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
	if ( month == 2 && IsLeapYear( year ) ) cal[i] = d; // ������ 2���� ��� !
}

void print_month(int year, int month )
{
	int cal[42];
	MakeMonth( year, month, cal );
	printf("\n\t\t[ %04d�� %2d�� ]\n", year, month );
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
		printf("���ϴ� ��, ���� �Է��� �ּ���( ��:2004 5 ����� -1.) =>");
		scanf("%d", &year );
		if ( year == -1 ) break;
		scanf("%d", &month);
		print_month(year, month);
	}
}
*/
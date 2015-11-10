/************************************************************
 class
 -> �Ʒ� �ڵ带 ��ü �߽��� �ڵ�� �����Ͻÿ�.
*************************************************************/
#include <iostream>
#include <memory.h>
using namespace std;

const char DAYS[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

inline int IsLeapYear(int year) 
{
	return ((year % 400 == 0) || (year % 100 != 0) && (year % 4 == 0));
}

inline int CountLeapYear(int year)
{
	return ((year-1) / 4 - (year - 1) / 100 + ( year - 1 ) / 400 );
}

inline int WeekOfYear(int year) 
{
	return (( year + CountLeapYear(year) ) % 7);
}

class A
{
public:
	int year, month;

	int WeekOfMonth()
	{
		int past = 0;
		for ( int i = 0 ; i < month - 1 ; i++) past += DAYS[i];
		if ( IsLeapYear( year ) && month > 2 ) past++;
		return ( WeekOfYear( year ) + past) % 7;
	}

	void MakeMonth(int* cal)
	{
		memset( cal, 0, sizeof(int) * 42 );
		int d = 1;
		int week = WeekOfMonth();
		for ( int i = week ; i < week + DAYS[month-1]; i++)cal[i] = d++;
		if ( month == 2 && IsLeapYear( year ) ) cal[i] = d; // ������ 2���� ��� !
	}

	void print_month()
	{
		int cal[42];
		MakeMonth(cal);
		printf("\n\t\t[ %04d�� %2d�� ]\n", year, month );
		printf("Sun\tMon\tTue\tWed\tThu\tFri\tSat");
		for ( int i = 0; i < 42; i++)
		{
			if ( cal[i] != 0 )
				printf( "%d", cal[i] );
			if ( i%7 == 0 )
				printf("\n");
			else 
				printf("\t");
		}
		printf("\n===================================================\n");
	}
};

void main()
{
	A a;
	while(1)
	{
		printf("���ϴ� ��, ���� �Է��� �ּ���( ��:2004 5 ����� -1.) =>");
		cin >> a.year;
		if ( a.year == -1 ) break;
		cin >> a.month;
		a.print_month();
	}
}

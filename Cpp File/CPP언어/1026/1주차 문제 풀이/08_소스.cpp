/************************************************************
 class
 -> �Ʒ� �ڵ带 ��ü �߽��� �ڵ�� �����Ͻÿ�.
*************************************************************/

#include <stdio.h>
#include <memory.h>

const char DAYS[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

#define IsLeapYear( year )((year % 400 == 0) || (year % 100 != 0) && (year % 4 == 0))
#define CountLeapYear(year) ((year-1) / 4 - (year - 1) / 100 + ( year - 1 ) / 400 )
#define WeekOfYear( year) (( year + CountLeapYear(year) ) % 7)

int WeekOfMonth( int year, int month )
{
	int past = 0;
	for ( int i = 0 ; i < month - 1 ; i++) past += DAYS[i];
	if ( IsLeapYear( year ) && month > 2 ) past++;
	return ( WeekOfYear( year ) + past) % 7;
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
		else 
			printf("\t");
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

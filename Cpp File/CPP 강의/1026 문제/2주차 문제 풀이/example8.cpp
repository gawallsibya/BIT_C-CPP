/************************************************************
  08. 다음 출력 결과를 만족하는 클래스를 구현하시오.
		결과 : 
		1990/1/1 
		1990/1/1 
		1990/1/1 
		true 
		false 
*************************************************************/
#include <iostream>
using namespace std;

class Date // 1) 클래스명 
{
	int year, month, day;
public:
	Date(int y = 1990, int m = 1, int d =1) : year(y), month(m), day(d){} //2) 인자를 3개 받는 생성자
	
	void print() //3) print 메서드
	{
		cout << year << " : " << month << " : " << day << endl;
	}

    bool cmp(const Date & a) //4) 객체를 인자로 받는 cmp 메서드
	{
		if(a.year == year && a.month == month && a.day == day)
			return true;
		else
			return false;
	}
    bool cmp(int a, int b, int c) //5) 정수형 인자 3개를 받는 cmp 메서드
	{
		if(a == year && b == month && c == day)
			return true;
		else
			return false;
	}
};

void main ( ) 
{ 
        Date arr[3];
		int i;

        for( i = 0 ; i < 3 ; i++)
			arr[i].print( );// 모두 1990/1/1 

        arr[1].cmp(arr[0]) ? cout << "true" <<  endl : cout << "false" << endl;
        arr[1].cmp(1990,2,1) ? cout << "true" << endl : cout << "false" << endl;
} 

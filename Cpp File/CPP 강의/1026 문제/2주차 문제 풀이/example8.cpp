/************************************************************
  08. ���� ��� ����� �����ϴ� Ŭ������ �����Ͻÿ�.
		��� : 
		1990/1/1 
		1990/1/1 
		1990/1/1 
		true 
		false 
*************************************************************/
#include <iostream>
using namespace std;

class Date // 1) Ŭ������ 
{
	int year, month, day;
public:
	Date(int y = 1990, int m = 1, int d =1) : year(y), month(m), day(d){} //2) ���ڸ� 3�� �޴� ������
	
	void print() //3) print �޼���
	{
		cout << year << " : " << month << " : " << day << endl;
	}

    bool cmp(const Date & a) //4) ��ü�� ���ڷ� �޴� cmp �޼���
	{
		if(a.year == year && a.month == month && a.day == day)
			return true;
		else
			return false;
	}
    bool cmp(int a, int b, int c) //5) ������ ���� 3���� �޴� cmp �޼���
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
			arr[i].print( );// ��� 1990/1/1 

        arr[1].cmp(arr[0]) ? cout << "true" <<  endl : cout << "false" << endl;
        arr[1].cmp(1990,2,1) ? cout << "true" << endl : cout << "false" << endl;
} 

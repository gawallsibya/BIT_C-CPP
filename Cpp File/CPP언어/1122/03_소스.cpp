//stream
#include <iostream>
using namespace std;
/*
void main()
{
	printf("%5d\n", 10);

	cout.width(5);			cout << 5 << endl;
	cout.width(5);			cout << 5 << endl; 
	
	printf("%d : %x : %o\n", 10, 10,10);

	cout << hex << 10 <<  " : " << 10 << endl;
	cout << dec ;
	cout << 10 << endl; 

	printf("%.2f\n", 0.123123);

	cout.precision(3);			cout << 1.121234 << endl;
}
*/


#include <windows.h>
void main()
{
	int num;
	while(1)
	{
		cin >> num;
		if( cin )		// ��ȯ������
		{
			cout << "���� �Է� " << endl;
		}
		else
		{			
			cin.clear();		// �⺻�� : 0
			cin.ignore();
			cout << "����" << endl; 
			
		}
	}
}
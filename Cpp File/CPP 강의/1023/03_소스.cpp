//enum : C & C++ ���� 
//����� ���� ������ Ÿ��
// 1. ������ ���� 
// 2. define�� ����(��� define)

#include <stdio.h>

/*
enum AAA { A=1, B=10, C };

void main()
{
	enum AAA	temp;
	temp		= A;		printf("%d\n", temp);
	temp		= B;		printf("%d\n", temp);
	temp		= C;		printf("%d\n", temp);
//	temp		= 100;
}
*/

#include <iostream>
using namespace std;

/*
char _suj[4][10] = {"COM", "IT", "GAME", "ETC" };
enum suj { COM = 1, IT, GAME, ETC };

void main()
{
	int idx;
	cout << "�а� �Է� [1]COM [2]IT [3]GAME [4] ��Ÿ : ";
	cin  >> idx;

	cout << "����� ������ �а��� : " << _suj[idx-1] << endl; 	
}
*/

/*(
enum suj { COM = 1, IT, GAME, ETC };

void main()
{
	enum suj  SUJ;
	cout << "�а� �Է� [1]COM [2]IT [3]GAME [4] ��Ÿ : ";
//	cin >> SUJ;		//error....
//	scanf("%??", &SUJ);
}
*/


//2) ��� ��뿹
enum {INSERT =1, PRINT, EXIT};
//#define INSERT	1
//#define PRINT   2
//#define EXIT	3
void main()
{
	while(1)
	{
		cout << "[1]�Է� [2]��� [3]����";
		int idx;
		cin >> idx;
		
		switch(idx)
		{
		case INSERT: cout << "�Է�" << endl;  break;
		case PRINT:	 cout << "���" << endl;  break;
		case EXIT:	 return;
		}
	}
}
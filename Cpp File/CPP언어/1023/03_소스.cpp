//enum : C & C++ 동일 
//사용자 정의 데이터 타입
// 1. 변수의 형태 
// 2. define의 형태(상수 define)

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
	cout << "학과 입력 [1]COM [2]IT [3]GAME [4] 기타 : ";
	cin  >> idx;

	cout << "당신이 선택한 학과는 : " << _suj[idx-1] << endl; 	
}
*/

/*(
enum suj { COM = 1, IT, GAME, ETC };

void main()
{
	enum suj  SUJ;
	cout << "학과 입력 [1]COM [2]IT [3]GAME [4] 기타 : ";
//	cin >> SUJ;		//error....
//	scanf("%??", &SUJ);
}
*/


//2) 상수 사용예
enum {INSERT =1, PRINT, EXIT};
//#define INSERT	1
//#define PRINT   2
//#define EXIT	3
void main()
{
	while(1)
	{
		cout << "[1]입력 [2]출력 [3]종료";
		int idx;
		cin >> idx;
		
		switch(idx)
		{
		case INSERT: cout << "입력" << endl;  break;
		case PRINT:	 cout << "출력" << endl;  break;
		case EXIT:	 return;
		}
	}
}
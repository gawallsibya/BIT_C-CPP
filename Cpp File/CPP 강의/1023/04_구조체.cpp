//구조체 : 태그명이 타입명이된다.
#include <iostream>
using namespace std;

/*
//typedef struct tagAA AA;
struct tagAA
{
	int num;
};

void main()
{
	tagAA	aa;
}
*/

// 비트필드 구조체
struct STUDENT
{
	unsigned int grade	 : 3;
	unsigned int age	 : 5;
	unsigned int gender	 : 1;	//0:남 1:여
	unsigned int sub	 : 5;   //0:COM 1 : IT 2 : GAME 3:ETC
};

void main()
{
	STUDENT stu;
	int temp;
	cout << "몇 학년 : ";		cin >> temp;		stu.grade = temp;
	cout << "나   이 : ";		cin >> temp;		stu.age   = temp;
	cout << "성   별 : ";	    cin >> temp;        stu.gender = temp;
	cout << "학과 입력 [0]COM [1]IT [2]GAME [3] 기타 : ";
	cin  >> temp;			stu.sub	= temp;

	cout << "학년 : " << stu.grade << endl;
	cout << "나이 : " << stu.age	<< endl;
	cout << "성별 : " << stu.gender << endl;
	cout << "학과 : " << stu.sub    << endl; 

}
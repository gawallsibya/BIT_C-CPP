//����ü : �±׸��� Ÿ�Ը��̵ȴ�.
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

// ��Ʈ�ʵ� ����ü
struct STUDENT
{
	unsigned int grade	 : 3;
	unsigned int age	 : 5;
	unsigned int gender	 : 1;	//0:�� 1:��
	unsigned int sub	 : 5;   //0:COM 1 : IT 2 : GAME 3:ETC
};

void main()
{
	STUDENT stu;
	int temp;
	cout << "�� �г� : ";		cin >> temp;		stu.grade = temp;
	cout << "��   �� : ";		cin >> temp;		stu.age   = temp;
	cout << "��   �� : ";	    cin >> temp;        stu.gender = temp;
	cout << "�а� �Է� [0]COM [1]IT [2]GAME [3] ��Ÿ : ";
	cin  >> temp;			stu.sub	= temp;

	cout << "�г� : " << stu.grade << endl;
	cout << "���� : " << stu.age	<< endl;
	cout << "���� : " << stu.gender << endl;
	cout << "�а� : " << stu.sub    << endl; 

}
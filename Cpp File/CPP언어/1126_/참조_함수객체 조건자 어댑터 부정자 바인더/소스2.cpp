//����������������������������������������
//  [ �Լ� 3 ] 
//����������������������������������������


//������������������������������������������������������������������������������
// �Լ� ��ü 
//������������������������������������������������������������������������������

#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
using namespace std;

bool GreateThan5(int a)
{
	return a > 5; 
}

template <class T>
void foo( T func, int number)
{
	func(number);
}
void main()
{
	// 5���� ���� ���ΰ�?
	foo( GreateThan5, 10);


}
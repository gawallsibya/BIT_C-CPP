/************************************************************
 ������ 2���� ��ȯ�ϴ� swap �Լ��� ���۷����� ����ؼ� �����Ͻÿ�. 
*************************************************************/
 
#include <iostream>
using namespace std;

void swap(int & A, int & B);

int main()
{
	int num = 10, num1 = 20;

	int & A = num;
	int & B = num1;

	swap(A, B);

	cout << num << " / " << num1 << endl;

	return 0;
}

void swap(int & A, int & B)
{
	int temp;

	temp = A;
	A = B;
	B = temp;

	cout << A << " / " << B << endl;
}

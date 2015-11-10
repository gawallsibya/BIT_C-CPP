/************************************************************
 정수값 2개를 교환하는 swap 함수를 레퍼런스를 사용해서 구현하시오. 
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

/************************************************************
 class
 -> �Ʒ� �ڵ尡 ���������� ������ �� �ֵ��� class�� �ϼ��Ͻÿ�.
*************************************************************/
 
#include <iostream>
using namespace std;

int main()
{
	DATE today(2010, 4, 30);

	DATE tomorrow = today.GetTomorrow(); // today�� ���� ��¥ ����

	today.Print();     // 2010 / 4 / 30
	tomorrow.Print();  // 2010 / 4 / 31

	return 0;
}

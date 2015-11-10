/************************************************************
 class
 -> �Ʒ� �ڵ尡 ���������� ������ �� �ֵ��� class�� �ϼ��Ͻÿ�.
*************************************************************/
#include <iostream>
using namespace std;

class DATE
{
	int Year, Month, Day;
public:
	DATE(int _Year, int _Month, int _Day) : Year(_Year), Month(_Month), Day(_Day)
	{
	}

	DATE GetTomorrow()
	{
		return DATE(Year, Month, Day+1);
	}

	void Print()
	{
		cout << Year << ", " << Month << ", " << Day << endl;
	}
};

int main()
{
	DATE today(2010, 4, 30);

	DATE tomorrow = today.GetTomorrow(); // today�� ���� ��¥ ����

	today.Print();     // 2010 / 4 / 30
	tomorrow.Print();  // 2010 / 4 / 31

	return 0;
}

/************************************************************
 namespace 
*************************************************************/
#include <iostream>
using namespace std;

namespace one
{
	void foo()
	{
		cout << "�̷� �����" << endl;
	}
};

namespace two
{
	void foo()
	{
		cout << "�̷� �����" << endl;
	}
}

void foo()
{
	cout << "���ߴ� �úζ�" << endl;
}

int main()
{
	foo();			// global foo()
	one::foo();		// namespace one::foo()
	two::foo();		// namespace two::foo()

	return 0;
}

/************************************************************
 namespace 
*************************************************************/
#include <iostream>
using namespace std;

namespace one
{
	void foo()
	{
		cout << "ÀÌ·± Á¦±â¶ö" << endl;
	}
};

namespace two
{
	void foo()
	{
		cout << "ÀÌ·± Á¦±â¶ö" << endl;
	}
}

void foo()
{
	cout << "¸ÁÇß´Ù ½ÃºÎ¶ö" << endl;
}

int main()
{
	foo();			// global foo()
	one::foo();		// namespace one::foo()
	two::foo();		// namespace two::foo()

	return 0;
}

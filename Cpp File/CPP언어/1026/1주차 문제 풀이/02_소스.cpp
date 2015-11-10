/************************************************************
 namespace 
*************************************************************/
 
#include <iostream>
using namespace std;

int main()
{
	foo();			// global foo()
	one::foo();		// namespace one::foo()
	two::foo();		// namespace two::foo()

	return 0;
}

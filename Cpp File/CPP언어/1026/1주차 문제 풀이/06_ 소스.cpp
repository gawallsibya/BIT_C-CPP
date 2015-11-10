/************************************************************
 class
 -> 아래 코드가 정상적으로 동작할 수 있도록 class를 완성하시오.
*************************************************************/
 
#include <iostream>
using namespace std;

int main()
{
	DATE today(2010, 4, 30);

	DATE tomorrow = today.GetTomorrow(); // today의 다음 날짜 리턴

	today.Print();     // 2010 / 4 / 30
	tomorrow.Print();  // 2010 / 4 / 31

	return 0;
}

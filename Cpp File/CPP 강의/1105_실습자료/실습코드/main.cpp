// main.cpp

#include "std.h"

void main()
{
	Cal	cal1;

	Cal cal2(10, 0);

	// 저장값이 0, 0이므로 값을 넣으세요 라는 메시지를 출력하게 된다.
	cal1.Add();

	// 값을 넣을 수 있는 2개의 SetMethod를 호출한다.
	cal1.SetNum1(20);
	cal1.SetNum2(30);

	// 다시 연산을 수행한다. 연산의 결과가 출력된다.
	// Add 메서드 에서는 연산의 결과를 맴버 변수result에 저장한다.
	// Add 메서드 내부에서 print() 맴버 함수를 호출하여 연산 결과를 화면에 출력한다.
	cal1.Add();

	// 0으로 나눌 수 없다는 에러 메시지를 출력한다.
	cal2.Div();
}
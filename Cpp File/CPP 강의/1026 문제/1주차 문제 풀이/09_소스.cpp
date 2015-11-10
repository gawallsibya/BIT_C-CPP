/************************************************************
 class
 -> 아래 코드를 객체 중심의 코드로 변경하시오.
*************************************************************/
#include <iostream>
using namespace std;

enum { OPEN = 1, CLOSE, UNKNOWN };

class A
{
	int pDoor;

public:
	void door_open()
	{
		pDoor = OPEN;
	}

	void door_close()
	{
		pDoor = CLOSE;
	}

	void show_door_status()
	{
		if ( pDoor == OPEN )
			cout << "Door is Open" << endl;

		else if ( pDoor == CLOSE )
			cout << "Door is Close" << endl;

		else
			cout << "I don't Know !!" << endl;
	}
};

void main()
{
	A a;
	a.show_door_status();
	a.door_open();
	a.show_door_status();

	a.door_close();
	a.show_door_status();
}

/************************************************************
 class
 -> 아래 코드를 객체 중심의 코드로 변경하시오.
*************************************************************/
#include <iostream>
using namespace std;

enum { OPEN = 1, CLOSE, UNKNOWN };

void door_open( int* pDoor )
{
	*pDoor = OPEN;
}

void door_close(int* pDoor)
{
	*pDoor = CLOSE;
}

void show_door_status(int door )
{
	if ( door == OPEN )
		cout << "Door is Open" << endl;

	else if ( door == CLOSE )
		cout << "Door is Close" << endl;

	else
		cout << "I don't Know !!" << endl;
}

void main()
{
	int door;
	show_door_status( door );
	door_open( &door );
	show_door_status( door );

	door_close( &door );
	show_door_status( door );
}

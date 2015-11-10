//cd.cpp
#include "std.h"
#include "cd.h"

CD::CD(char* _name, char* t1, char* t2, char* t3)
{
	strcpy(name, _name);
	strcpy(track[0], t1);
	strcpy(track[1], t2);
	strcpy(track[2], t3);
}

void CD::DataPrint() const	
{
	cout <<"******************" << endl; 
	cout << "CD Á¦¸ñ : " << name << endl; 
	cout << "1 : " << track[0] << endl; 
	cout << "2 : " << track[1] << endl; 
	cout << "3 : " << track[2] << endl; 
}						

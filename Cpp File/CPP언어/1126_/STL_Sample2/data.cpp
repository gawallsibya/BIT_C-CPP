//data.cpp

#include "std.h"


Data::Data() : num(0)
{
	strcpy(name, "");
}

Data::Data(char *_name, int _num) : num(_num)
{
	strcpy(name, _name);
}

// method
void Data::DataPrint() const
{
	cout << "�� �� : " << name << endl; 
	cout << "�� �� : " << num	<< endl;
}

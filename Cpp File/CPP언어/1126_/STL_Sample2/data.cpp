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
	cout << "이 름 : " << name << endl; 
	cout << "학 번 : " << num	<< endl;
}

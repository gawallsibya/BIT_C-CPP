//person.cpp
#include "std.h"
#include "person.h"

Person::Person(const char* n, const char* p)
{
	strcpy(name, n);
	strcpy(phone, p);
}

void Person::DataPrint() const
{
	cout << "[이름] " << name << "\t[전화번호] " << phone << endl; 
}
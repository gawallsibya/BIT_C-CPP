//employee.cpp
#include "std.h"
#include "employee.h"

void Employee::printdata()
{
	cout<<name.c_str()<<" : "<<id<<" : "<<grade.c_str()<<" : "<<depart.c_str()<<endl;
}

Employee::Employee(string _name, int _id, string _grade, string _depart)
: id(_id), name(_name), grade(_grade),depart(_depart)
{
}
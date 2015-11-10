//person.cpp
#include "std.h"
#include "person.h"


CPerson::CPerson(char* name)
: m_library(0), m_pcroom(0), m_sool(0), m_training(0)
{
	strcpy(m_name, name);
}


void CPerson::DataPrint()
{

	cout << "[이름 : " << m_name << "]" << endl;
	cout << "===============================" << endl; 
	cout << "박사게이지     : " << m_library << endl; 
	cout << "운동선수게이지 : " << m_training << endl; 
	cout << "게임페인게이지 : " << m_pcroom << endl; 
	cout << "알콜중독게이지 : " << m_sool << endl; 
	cout << "===============================\n" << endl; 
}
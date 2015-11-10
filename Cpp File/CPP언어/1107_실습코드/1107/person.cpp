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

	cout << "[�̸� : " << m_name << "]" << endl;
	cout << "===============================" << endl; 
	cout << "�ڻ������     : " << m_library << endl; 
	cout << "����������� : " << m_training << endl; 
	cout << "�������ΰ����� : " << m_pcroom << endl; 
	cout << "�����ߵ������� : " << m_sool << endl; 
	cout << "===============================\n" << endl; 
}
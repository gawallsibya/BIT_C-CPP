//cal.cpp

#include "std.h"
#include "Cal.h"

void Cal::SetData(int num1, int oper, int num2)
{
	m_num1 = num1; 
	m_num2 = num2;
	m_oper = oper;
	SetResultData();
}

void Cal::SetResultData()
{
	switch( IntToCharOper( m_oper) )
	{
	case '+':	m_result = (float)m_num1 + m_num2;  break;
//	case '+':   Add();  break;
	case '-':	m_result = (float)m_num1 - m_num2;  break;
	case '*':	m_result = (float)m_num1 * m_num2;  break;
	case '/':	m_result = (float)m_num1 / m_num2;  break;
//	case '/':   Div();	break;
	}
}

char Cal::IntToCharOper(int oper)
{
	char op;
	switch( oper)
	{
	case 0: op = '+'; break;
	case 1: op = '-'; break;
	case 2: op = '*'; break;
	case 3: op = '/'; break;
	}
	return op;
}

void Cal::ExamPrint()
{
	cout << m_num1 << " " << IntToCharOper(m_oper) << 
		" " << m_num2 << " = ";
}

void Cal::SetInputResult(int result)
{
	m_inputresult = result;
}

void Cal::SetFlag()
{
	m_flag = (m_inputresult == m_result) ? true : false;
}

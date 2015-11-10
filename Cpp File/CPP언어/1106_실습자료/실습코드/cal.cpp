//cal.cpp

#include "std.h"
#include "Cal.h"

void Cal::Add()
{
	if( m_num1 == 0 && m_num2 == 0 )
	{
		cout << "저장값이 0, 0이므로 값을 넣으세요" << endl;
		return;
	}

	m_result	= m_num1 + m_num2;
	print();
}


void Cal::print()
{
	cout << "결과값 : " << m_result << endl; 
}

void Cal::Div()
{
	if( m_num2 == 0 )
	{
		cout <<"0으로 나눌 수 없습니다." << endl;
		return;
	}

	m_result = (float)m_num1 / m_num2;
	print();
}

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

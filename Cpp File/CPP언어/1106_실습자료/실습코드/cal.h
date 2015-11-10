// cal.h
#ifndef _CAL_H_
#define _CAL_H_

class Cal
{
private:	
	int		m_num1;
	int		m_num2;
	int     m_oper;
	float	m_result;
	float	m_inputresult;
	bool	m_flag;
private:
	void SetResultData();
	void print();

public:
	void SetFlag();
	void SetInputResult(int result);
	// »ı¼ºÀÚ 
	Cal() : m_num1(0), m_num2(0)							{}
	Cal(int num1, int num2, int op) : m_num1(num1), m_num2(num2), m_oper(op)	{}
//	Cal(int num1 = 0, int num2 = 0) : m_num1(num1), m_num2(num2)	{} 

	// get & set method
	void SetNum1(int num) 		{ m_num1 = num;		}
	void SetNum2(int num) 		{ m_num2 = num;		}
	int GetNum1()	const		{ return m_num1;	}
	int GetNum2()	const		{ return m_num2;	}
	float GetResult()	const   { return m_result;	}

	// method
	char IntToCharOper(int oper);
	void SetData( int num1, int oper, int num2);
	void ExamPrint();

	void Add();
	void Div();


};

#endif /*_CAL_H_*/
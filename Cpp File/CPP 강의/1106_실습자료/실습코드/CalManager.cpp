// CalManager.cpp: implementation of the CCalManager class.
//
//////////////////////////////////////////////////////////////////////
#include "std.h"
#include "CalManager.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CCalManager::CCalManager() : m_max(10)
{

}

CCalManager::~CCalManager()
{

}

void CCalManager::ExamInit()
{
	cout << "문제를 생성합니다...." << endl; 	
	for(int i=0; i<10; i++)
	{
		int num1 = rand()%100;
		int op   = rand()%4;
		int num2 = rand()%100;
		m_data[i].SetData(num1, op, num2);
		Sleep(100);
		cout << ". ";		
	}
	cout << "\n문제 생성을 완료했습니다.." << endl; 
}

void CCalManager::init()
{
	srand(time(NULL));
}

void CCalManager::RunExam()
{
	int temp;
	for(int i=0; i<m_max; i++)
	{
		cout << "[ " << i+1 << " ]";
		m_data[i].ExamPrint();
		cin >> temp;
		m_data[i].SetInputResult(temp);
		m_data[i].SetFlag();
	}
}

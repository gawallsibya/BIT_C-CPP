//simul.cpp
#include "std.h"
#include "simul.h"

void CSimul::Init()
{
	srand(time(NULL)); 
}

void CSimul::InitData()
{
	cout << "[ 시뮬레이션 정보 입력 ]" << endl;
	cout << "인원 수(1~10) : ";	scanf("%d", &m_idx);
	
	char name[20];
	cin.ignore();
	for(int i=0; i < m_idx; i++)
	{
		cout << "[" << i+1 << "] 이름 : " ;  gets(name);

		m_data[i] = new CPerson(name);
	}
}


void CSimul::RunData()
{
	cout << "[ 시뮬레이션  실행 ]" << endl;

//	cin.ignore();
	cout << "시뮬레이션 타임(단위 : 년) : "; 
	cin >> m_interval;

	for(int i=0; i< m_interval*365; i++)
	{	
		for(int j=0; j<m_idx; j++)
		{
			int temp = rand();
			temp	 = temp%4;
			switch(temp)
			{
			case 0:	m_lib.Visit(m_data[j]);		break;
			case 1:	m_pcroom.Visit(m_data[j]);	break;
			case 2: m_sool.Visit(m_data[j]);	break;
			case 3:	m_train.Visit(m_data[j]);	break;
			}
		}	
		PrintView(i, i);
	}
}


void CSimul::PrintView(int idx, int temp)
{
	system("cls");
	temp = temp+1;
	int year = temp/365;
	temp	 = temp%365;
	cout << year << "년 " << temp << "일 경과" << endl;
}


void CSimul::Result()
{
	cout << "[시뮬레이션 결과 ]\n";

	for(int i=0; i< m_idx; i++)
	{
		m_data[i]->DataPrint();
	}
 
}

//person.h

#ifndef _PERSON_H_
#define _PERSON_H_

class CPerson
{
	char m_name[20];

	int  m_library;		//- �ڻ������
	int  m_training;    //- �����������
	int  m_pcroom;		//- �������ΰ�����
	int  m_sool;		//- �����ߵ�������

public:
	CPerson(char* name);
	void AddPcRoom(int num)		{ m_pcroom += num;		}
	void AddLibrary(int num)	{ m_library += num;		}
	void AddTraining(int num)	{ m_training += num;	}
	void AddSool(int num)		{ m_sool += num;		}

	void DataPrint();
};

#endif /*_PERSON_H_*/
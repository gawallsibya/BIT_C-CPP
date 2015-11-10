//person.h

#ifndef _PERSON_H_
#define _PERSON_H_

class CPerson
{
	char m_name[20];

	int  m_library;		//- 박사게이지
	int  m_training;    //- 운동선수게이지
	int  m_pcroom;		//- 게임페인게이지
	int  m_sool;		//- 알콜중독게이지

public:
	CPerson(char* name);
	void AddPcRoom(int num)		{ m_pcroom += num;		}
	void AddLibrary(int num)	{ m_library += num;		}
	void AddTraining(int num)	{ m_training += num;	}
	void AddSool(int num)		{ m_sool += num;		}

	void DataPrint();
};

#endif /*_PERSON_H_*/
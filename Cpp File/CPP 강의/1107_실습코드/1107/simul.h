//simul.h

#ifndef _SIMUL_H_
#define _SIMUL_H_
#include "person.h"
#include "library.h"
#include "sool.h"
#include "training.h"
#include "pcroom.h"

class CSimul
{
	CPerson *	m_data[10];
	int			m_idx;		//�ùķ��̼� ���� 
	int			m_interval;	//�ùķ��̼� Ÿ��

	CLibrary	m_lib;
	CSool		m_sool;
	CTraining   m_train;
	CPCRoom		m_pcroom;

private:
	void PrintView(int idx, int temp);

public:
	void Init()	;
	void InitData();
	void RunData();
	void Result();

};

#endif /*_SIMUL_H_*/
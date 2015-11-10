// CalManager.h: interface for the CCalManager class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CALMANAGER_H__F177FF35_76F4_4E22_99CC_24FAD5299834__INCLUDED_)
#define AFX_CALMANAGER_H__F177FF35_76F4_4E22_99CC_24FAD5299834__INCLUDED_

#include "cal.h"
class CCalManager  
{
	Cal m_data[10];
	int m_max;
public:
	// constructor & destructor
	CCalManager();
	virtual ~CCalManager();

	// method
	void init();
	void ExamInit();
	void RunExam();


};

#endif // !defined(AFX_CALMANAGER_H__F177FF35_76F4_4E22_99CC_24FAD5299834__INCLUDED_)

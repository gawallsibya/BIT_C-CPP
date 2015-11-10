//app.h
#ifndef _APP_H_
#define _APP_H_

#include "CalManager.h"

class App
{
	CCalManager m_cal;

public:
	void init();
	void run();
	void exit();

private:
	void menuprint();
};

#endif /*_APP_H_*/
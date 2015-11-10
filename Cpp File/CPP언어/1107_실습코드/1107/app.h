//app.h
#ifndef _APP_H_
#define _APP_H_

#include "simul.h"

class CApp
{
	CSimul m_simul;

public:
	void Init();
	void Run();
	void Exit();

private:
	void MenuPrint();
};

#endif /*_APP_H_*/
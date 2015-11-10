//app.h
#ifndef _APP_H_
#define _APP_H_
#include "menumanager.h"

class App
{
	MenuManager m_manager;

public:
	App(int count) : m_manager(count) {}
	void init();
	void run();
	void exit();
};

#endif /*_APP_H_*/
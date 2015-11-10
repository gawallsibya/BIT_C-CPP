//app.h
#ifndef _APP_H_
#define _APP_H_
#include "menumanager.h"
#include "ordermanager.h"

class App
{
	MenuManager		m_manager;
	OrderManager	m_order;
public:
	App(int count) : m_manager(count) {}
	void init();
	void run();
	void exit();
	void Menu();
};

#endif /*_APP_H_*/
//app.h
#ifndef _APP_H_
#define _APP_H_
#include "manager.h"
class App
{
private:
	Manager manager;
private:
	void menu();
public:
	App();
	~App();

	void Init();
	void Run();
	void Exit();

};
#endif /*_APP_H_*/
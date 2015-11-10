//app.h
#ifndef _APP_H_
#define _APP_H_

#include "telphonebook.h"

class App
{
	TelPhoneBook tb;

public:
	void init();
	void run();
	void exit();

private:
	void menuprint();
};

#endif /*_APP_H_*/
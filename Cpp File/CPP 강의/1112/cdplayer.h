//cdplayer.h
#ifndef _CDPLAYER_H_
#define _CDPLAYER_H_
#include "cd.h"

enum CD_STATE {IN_STOP1, OUT1, PLAY1 };

class CDPlayer
{
	CD *p;
	CD_STATE state;
public:
	CDPlayer();
	void ToStringState();
	void CD_In(CD* p[]);
	void CD_Play();
};

#endif /*_CDPLAYER_H_*/
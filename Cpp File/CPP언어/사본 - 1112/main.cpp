//main.cpp
#include "std.h"
#include "cd.h"
#include "cdplayer.h"

char temp1[][20] = {"Track1","Track2","Track3","CD1",
					"Track21","Track22","Track23","CD2",
					"Track31","Track32","Track33","CD3"};

CD* CreateCD()
{
	static int count = -1;
	CD *p = new CD(temp1[++count], temp1[++count], temp1[++count], temp1[++count]);

	return p;
}

void main()
{
	CD* pCD[3];
	for(int i=0; i<3; i++)
		pCD[i] = CreateCD();		// 3¹ø È£Ãâ 

	CDPlayer player;
	player.ToStringState();
	player.CD_In(pCD);

	player.CD_Play();
}





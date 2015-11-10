//main.cpp
#include "std.h"
#include "cd.h"

char temp1[][20] = {"Track1","03:21","Track2","04:10","Track3","06:08","CD1",
					"Track21","03:21","Track22","04:10","Track23","06:08","CD2",
					"Track31","03:21","Track32","04:10","Track33","06:08","CD3"};

CD* CreateCD()
{
	static int count = -1;
	CDTrackData d1(temp1[++count], temp1[++count]);
	CDTrackData d2(temp1[++count], temp1[++count]);
	CDTrackData d3(temp1[++count], temp1[++count]);
	CD *p = new CD(temp1[++count], d1, d2, d3);

	return p;
}

void main()
{
	CD* pCD[3];
	for(int i=0; i<3; i++)
		pCD[i] = CreateCD();		// 3¹ø È£Ãâ 

	for(i=0; i<3; i++)
	{
		pCD[i]->DataPrint();
	}
}





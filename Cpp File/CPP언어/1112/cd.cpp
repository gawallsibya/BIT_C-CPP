//cd.cpp
#include "std.h"
#include "cd.h"

CD::CD(char*_name, CDTrackData d1, CDTrackData d2, CDTrackData d3)
: track1( d1), track2( d2), track3( d2) 
{
	strcpy(name, _name);
}

void CD::DataPrint() const	
{
	cout <<"******************" << endl; 
	cout << "CD Á¦¸ñ : " << name << endl; 
	track1.DataPrint();
	track2.DataPrint();
	track3.DataPrint();
}						

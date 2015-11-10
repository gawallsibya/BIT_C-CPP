//cd.h
#ifndef _CD_H_
#define _CD_H_

struct CDTrackData
{
	char name[20];
	char time[20];	
	
	CDTrackData() {}
	CDTrackData(char* n, char*t)
	{
		strcpy(name, t);
		strcpy(time, n);
	}
	void DataPrint() const
	{
		cout << "力格 : " << name << " : " << time << endl;
	}
};

class CD
{
private:
	char		name[20];
	CDTrackData track1;		// 力格 3俺..
	CDTrackData track2;		// 力格 3俺..
	CDTrackData track3;		// 力格 3俺..

public:
	CD()	{}
	CD(char* name, CDTrackData d1, CDTrackData d2, CDTrackData d3);

	 // get & set method
	const char* GetName() const		  { return name; }
    CDTrackData GetTrack1() const     { return track1;}
    CDTrackData GetTrack2() const     { return track2;}
    CDTrackData GetTrack3() const     { return track3;}

	// method
	void DataPrint() const;
};

#endif /*_CD_H_*/


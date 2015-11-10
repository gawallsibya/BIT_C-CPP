//cd.h
#ifndef _CD_H_
#define _CD_H_


class CD
{
private:
	char		name[20];
	char		track[3][20];

public:
	CD()	{}
	CD(char* _name, char* t1, char* t2, char* t3);

	 // get & set method
	const char* GetName() const				{ return name; }
    const char* GetTrack(int idx) const     { return track[idx];}

	// method
	void DataPrint() const;
};

#endif /*_CD_H_*/


//data.h

#ifndef _DATA_H_
#define _DATA_H_

class Data
{
	char name[20];
	int   num;

public:
	// 생성자
	Data();
	Data(char *_name, int _num);

	// get & set method
	const char *GetName() const { return name; }
	int GetNum()			const  { return num;  }
	void SetName(char *_name)    { strcpy(name, _name);}
	void SetNum(int _num)		   { num = _num; }

	// method
	void DataPrint() const;

	
	// 연산자 오버로딩
	friend bool operator<(const Data& p1, const Data& p2)
	{
		return strcmp(p1.name, p2.name) < 0;	
	}
	friend bool operator==(const Data& p1, const Data& p2)
	{
		return strcmp(p1.name, p2.name) == 0;	
	} 
};

#endif /*_DATA_H_ */
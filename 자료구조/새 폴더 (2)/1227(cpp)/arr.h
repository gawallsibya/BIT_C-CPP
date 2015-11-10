#ifndef _ARR_H_
#define _ARR_H_

class Arr
{
public:
	Member** data;   //원래의 요구는 Member* data <==40개의 배열을 동적할당할 포인터 변수만 선언.
	int ncount;			 //int ncount
	int max;					 //int max
public:
	Arr();

	void arr_info();
	void arr_insert( Member *pdata, int idx);
	Member* arr_getdata(int idx);
};



#endif /*_ARR_H_*/
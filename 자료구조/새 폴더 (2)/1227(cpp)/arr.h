#ifndef _ARR_H_
#define _ARR_H_

class Arr
{
public:
	Member** data;   //������ �䱸�� Member* data <==40���� �迭�� �����Ҵ��� ������ ������ ����.
	int ncount;			 //int ncount
	int max;					 //int max
public:
	Arr();

	void arr_info();
	void arr_insert( Member *pdata, int idx);
	Member* arr_getdata(int idx);
};



#endif /*_ARR_H_*/
//array.h
#ifndef _ARRAY_H_
#define _ARRAY_H_
#define MAX 40
#define NULL 0
template <class T>
class Array
{
private:
	T data[MAX];
	int count;
public:
	Array();
	~Array(); 

	T getdata(int i){return data[i];}
	void insert(int,T);
	void deleted(T);
};
template <class T>
Array<T>::Array()
{
	count = 0;
	for (int i = 0; i<MAX; i++)
		data[i] = NULL;
}
template <class T>
Array<T>::~Array()
{

}
template <class T>
void Array<T>::insert(int n,T _data)
{
	if(data[n] == 0x00000000)
	{
		data[n] = _data;
		count++;
	}
}
template <class T>
void Array<T>::deleted(T d)
{
	for(int i = 0; i< MAX;i++)
	{
		if (data[i] == d)
			data[i] = NULL;
	}
}
#endif /*_ARRAY_H_*/
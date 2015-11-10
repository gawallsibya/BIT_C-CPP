// [] ¿¬»êÀÚ
#include <iostream>
using namespace std;

/*
int arr[5] = {1,2,3,4,5};

int foo()	{		return arr[1];	}		//	return 2
int& goo()  {		return arr[1];	}		//  return arr[1]

void main()
{
	goo() = 100;
}
*/


class MyArr
{
	int* data;
	int   max;
	int   size;
public:
	MyArr(int m = 10);
	~MyArr()		{ delete [] data; }
	// arr.operator[](i) = i+1;

	int& operator[](int idx)		{ return data[idx]; }

	void push_back(int num)
	{
		data[size++] = num;
	}
	int get_data(int idx)		{ return data[idx]; }
};

MyArr::MyArr(int m)	: max(m), size(0)
{
	data = (int*)new int[m];	
}


void main()
{
	MyArr	arr(5);

	for(int i=0; i<5; i++)
	{
	//	arr.push_back(i+1);
		arr[i] = i+1;			// arr.operator[](i) = i+1;
	}

	for(i = 0; i<5; i++)
	{
	//	cout << arr.get_data(i) << endl; 
		cout << arr[i] << endl; 
	}
}

// ÅÛÇÃ¸´ ?
#include <iostream>
using namespace std;

/*
// overloading
int foo(int num)	{ return num; }
char foo(char num)	{ return num; }

// ÅÛÇÃ¸´ ÇÔ¼ö
template <typename T>
T foo( T num )		{ return num; }


void main()
{
	cout << foo<int>('a') << endl;
	cout << foo(10) << endl;
	cout << foo('a') << endl;
}
*/

/*
template<typename T, typename T1>
void foo( T n1, T1 n2)
{
	T  num = n1;
}

void main()
{
	foo(10, 10.1);
}
*/

/*
int max(int *start, int *end)
{
	int *p = start;
	int temp = *start;
	while(p != end )
	{
		if( temp < *p)
			temp = *p;
		p++;
	}
	return temp;	
}
*/

/*
template <typename T>
T max(T start, T end)
{
	T p = start;
	T temp = start;
	while(p != end )
	{
		if( temp < p)
			temp = p;
		p++;
	}
	return temp;	
}
void main()
{
	int arr[10] = { 1,2,3,4,50,6,7,8,9,100};
	int *p = max(arr, arr+10);
	cout << *p << endl;
}
*/

/*
int* find(int *start, int *end, int num)
{
	int *p = start;
	while(p != end)
	{
		if( *p == num )
			return p;
		p++;
	}
	return NULL;
}
*/

template<typename T, typename T1>			// int * ==> T	int ==> T1
T find(T start, T end, T1 num)
{
	T  p = start;
	while(p != end)
	{
		if( *p == num )
			return p;
		p++;
	}
	return NULL;
}

void main()
{
	int arr[10] = { 1,2,3,4,50,6,7,8,9,100};
	int *p = find(arr, arr+10, 7);
	cout << *p << endl;
}
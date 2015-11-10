//arr.cpp
#include "std.h"

Arr::Arr()
{
	ncount=0;
	max=40;
	data=new Member*[40];
	for(int i=0;i < max;i++)
	{
		data[i]=NULL;
	}
}

void Arr::arr_info()
{
	int i;
	char ch[40];
	for(i=0; i<MAX; i++)
	{
		if(data[i] != NULL)
		{
			ch[i]= 'X';
		}
		else
			ch[i]= 'O';
	}
	cout<<"===================================\n";
	cout<<"1  5  9  13 17 21 25 29 33 37\n";
	for(i=0; i<MAX; i+=4)
	{
		cout<<ch[i]<<"  ";
	}
	cout<<"\n2  6  10 14 18 22 26 30 34 38\n";
	for(i=1; i<MAX; i+=4)
	{
		cout<<ch[i]<<"  ";
	}
	cout<<"\n\n";
	cout<<"3  7  11 15 19 23 27 31 35 39\n";  
	for(i=2; i<MAX; i+=4)
	{
		cout<<ch[i]<<"  ";
	}
	cout<<"\n4  8  12 16 20 24 28 32 36 40\n";  
	for(i=3; i<MAX; i+=4)
	{
		cout<<ch[i]<<"  ";
	}
	cout<<endl;
};

void Arr::arr_insert( Member *pdata,int idx)
{
	data[idx-1] = pdata;	
}

Member* Arr::arr_getdata(int idx)
{
	return data[idx-1];
}
//member.cpp
#include "std.h"

void Member::mem_print()
{	
	cout<<"예약 전화번호 : "<<phone<<endl;;
	cout<<"예약 접수번호 : "<<number<<endl;
	cout<<"예약 매수     : "<<count<<endl;
	cout<<"좌석 번호     : ";
	for(int i=0; i<count; i++)
	cout<<seat[i]<<" ";
	cout<<"\n";
}
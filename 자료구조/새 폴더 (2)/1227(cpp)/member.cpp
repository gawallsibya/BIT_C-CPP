//member.cpp
#include "std.h"

void Member::mem_print()
{	
	cout<<"���� ��ȭ��ȣ : "<<phone<<endl;;
	cout<<"���� ������ȣ : "<<number<<endl;
	cout<<"���� �ż�     : "<<count<<endl;
	cout<<"�¼� ��ȣ     : ";
	for(int i=0; i<count; i++)
	cout<<seat[i]<<" ";
	cout<<"\n";
}
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

struct A
{
	char		name[100];		// �̸�
	int			number;			// �ε���(��ȣ)

	A()		{}
	A(int n) : number(n) {}
	//------------ ������ ������ -----------------
	int operator < ( A & y)
	{
		return this->number < y.number;
	}
	bool operator == ( A * y)
	{
		return this->number == y->number;
	}
	//-----------------------------------------------
};


void main()
{
	// ����..
	vector<A>		data;

	// ������ �Է�
	A		a1;		a1.number		= 1;		strcpy( a1.name, "�̸�1");
	data.push_back(a1);
	
	A		a2;		a2.number		= 2;		strcpy( a2.name, "�̸�2");
	data.push_back(a2);

	// ������ ���
	// ��ü ���
	for( int i=0; i < data.size(); i++)
	{
		cout << data[i].number << " : " << data[i].name << endl; 
	}

	// 1. �˻�		: find �Լ�.
	A		bb(1);

	vector<A>::iterator		p	= find( data.begin(), data.end(), &bb);
	if( p == data.end())
		cout << "����";
	else
		cout << "������" << endl; 


	// 3. ����
	strcpy(p->name		, "�ٲپ��");
	p->number		= 1000;

	// 2. ����
//	data.erase( p ); 
	// ��ü ���
	for(  i=0; i < data.size(); i++)
	{
		cout << data[i].number << " : " << data[i].name << endl; 
	}


}








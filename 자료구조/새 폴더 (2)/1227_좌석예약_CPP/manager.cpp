//manager.cpp
#include "std.h"
#include "manager.h"
Manager::Manager()
{

}

Manager::~Manager()
{

}

void Manager::print()
{
	int i;
	cout<<"화면에 좌석 출력"<<endl;
	cout<<"=========================="<<endl;
	cout.width(5);
	for (i = 1 ; i <38 ; i=i+4)
	{
		cout<<i;cout.width(5);
	}
	cout<<endl;
	for (i = 1 ; i <38 ; i=i+4)
	{
		if (array.getdata(i-1) == NULL)		
		{cout<<"o";cout.width(5);}
		else
		{	cout<<"x";cout.width(5);}
	}
	cout<<endl;
	for (i = 2 ; i <39 ; i=i+4)
	{
		cout<<i;cout.width(5);
	}
	cout<<endl;
	for (i = 2 ; i <39 ; i=i+4)
	{
		if (array.getdata(i-1) == NULL)		
		{cout<<"o";cout.width(5);}
		else
		{	cout<<"x";cout.width(5);}
	}
	cout<<endl<<endl<<endl;
	for (i = 3 ; i <40 ; i=i+4)
	{
		cout<<i;cout.width(5);
	}
	cout<<endl;
	for (i = 3 ; i <40 ; i=i+4)
	{
		if (array.getdata(i-1) == NULL)		
		{	cout<<"o";cout.width(5);}
		else
		{cout<<"x";cout.width(5);}
	}
	cout<<endl;
	for (i = 4 ; i <41 ; i=i+4)
	{
		cout<<i;cout.width(5);
	}
	cout<<endl;
	for (i = 4 ; i <41 ; i=i+4)
	{
		if (array.getdata(i-1)== NULL)		
		{cout<<"o";cout.width(5);}
		else
		{cout<<"x";cout.width(5);}
	}
	cout<<endl;
	cout<<"=========================="<<endl;;
}

void Manager::order()
{
	Member *member = new Member;
	string p;
	string n;
	int count;
	int num[5];
	int i;char ch;
	print();
	cout<<"예약 전화번호 : ";cin.ignore();cin>>p; 
	member->setphone(p); 
	n = p+ " ";
	time_t rawtime;
	time ( &rawtime );
	n += ctime (&rawtime);
	cout<<"예약 접수번호 : ";
	cout<<n;
	member->setn(n);


	cout<<"예약 매수 : ";cin.ignore();cin>>count;  
	member->setcount(count); 
	cout<<"좌석 번호 : ";cin.ignore();
	for(i = 0;i<member->getcount();i++)
	{	
		cin>>num[i];
		member->setnum(i,num[i]);
	}
	cout<<"위 예약을 취소할까요? : (y, n):";cin.ignore();cin>>ch;
	
	if (ch == 'y')
	{
		free(member);
		return;
	}
	else
	{
		for(i = 0;i<count;i++)
		{	
			 array.insert(num[i]-1,member);
		}
		
		list.insert(member);
	}
}

void Manager::deletedata()
{
	string n;
	Member* m;
	cout<<"===========삭제=========="<<endl;
	cout<<"예약 전화번호 입력:";
	cin.ignore();
	cin>>n;
	List<Member*>::Node *cur =list.Isequal(n); 
	if (cur != NULL)
	{
		m = cur->data;
		array.deleted(m);
		list.deleted(cur);
	}
	else
		cout<<"없습니다..."<<endl;
}
void Manager::sideinfo()
{
	int n,i;
	Member *cur;
	cout<<"==========좌석 예약 정보=========="<<endl;
	cout<<"좌석 번호 : ";
	cin.ignore();
	cin>>n;
	cur = array.getdata(n-1);
	if( cur != NULL)
	{
		 
		cout<<"예약 전화번호 : ";cout<<cur->getphone();cout<<endl;
		cout<<"예약 접수번호 : ";cout<<cur->getn(); cout<<endl;
		cout<<"예약 매수     : ";cout<<cur->getcount();cout<<endl;
		cout<<"좌석 번호     : ";
		for(i = 0; i<cur->getcount();i++)
		{cout<<cur->gernum(i);cout.width();}
		cout<<endl;
	}
}
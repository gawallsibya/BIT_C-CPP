//manager.cpp
#include "std.h"

void Manager::ma_reserve()
{
	int i;
	
	Member *res = new Member; 
	m_arr.arr_info();
	
	while(1)
	{
		cout<<"예약매수 입력: ";		cin>>res->count;
		if(res->count > 0 && res->count < 6)
			break;
		else
			cout<<"재입력...\n";
	}
	for(i=0; i < res->count; i++)
	{
		cout<<"좌석 입력 : ";		cin>>res->seat[i];
		if(m_arr.data[res->seat[i]-1] != NULL)
		{
			cout<<"재입력...\n";
			i -= 1;
			continue;
		}
	}
	fflush(stdin);
	cout<<"전화번호 입력 : ";		gets(res->phone);
	for(i=0; i<5; i++)
	{
		res->number[i]=rand()%10+48;
		if(i==4)
			res->number[i+1]='\0';
	}
	for(i=0; i < res->count; i++)
	{
		m_arr.arr_insert( res,res->seat[i]);			//<===================================		
	}
	m_list.list_insert( res);
	cout<<"예약이 완료 되었습니다..\n";
	cout<<"예약번호: "<<res->number<<endl; 
}
void Manager::ma_check()
{
	int num;
	char num1[20];
	Member* cur;
	cout<<"[1] 전화번호 [2] 예약 번호\n";
	
	while(1)
	{
		cin>>num;
		if(num==1)
		{
			cout<<"전화번호 입력: "; 
			fflush(stdin);
			gets(num1);
			cur=m_list.list_search(num1);
			break;
		}
		else if(num==2)
		{
			cout<<"예약번호 입력: "; 
			fflush(stdin);
			gets(num1);
			cur=m_list.list_search(num1);
			break;
		}
		else
		{
			cout<<"다시 입력하세요..\n";
			continue;
		}
	}
	if(cur != NULL)
		m_list.list_print(cur);
	else
	{
		cout<<"예약정보를 찾을수 없음..\n";
		return;
	}
}
void Manager::ma_cancel()
{
	int num,i;
	char ch;
	char num1[20];
	Member* cur;
//	Arr* del;
	cout<<"[1] 전화번호 [2] 예약 번호\n";
	
	while(1)
	{
		cin>>num;
		if(num==1)
		{
			cout<<"전화번호 입력: "; 
			fflush(stdin);
			gets(num1);
			cur=m_list.list_search(num1);
			break;
		}
		else if(num==2)
		{
			cout<<"예약번호 입력: "; 
			fflush(stdin);
			gets(num1);
			cur=m_list.list_search(num1);
			break;
		}
		else
		{
			cout<<"다시 입력하세요..\n";
			continue;
		}
	}
	if(cur != NULL)
		m_list.list_print(cur);
	else
	{
		cout<<"예약정보를 찾을수 없음..\n";
		return;
	}
	cout<<"\n위 예약을 취소할까요? : (y, n)";	
	cin>>ch;
	if(ch=='y' || ch=='Y')
	{
		
		for(i=0; i < cur->count ;i++)
		m_arr.data[cur->seat[i]-1]=NULL;
		delete cur;
	}
	else
	return;
}
void Manager::ma_info()
{
	int num;
	Member* cur;
	while(1)
	{
		cout<<"원하는 좌석을 입력하시오..(0을 입력시 종료)";
		cin>>num;
		if(num==0)
		return;
		cur = numtores(num);
		if(cur==NULL)
		cout<<"예약되지 않음...\n";
		else
		m_list.list_print(cur);
	}
}
Member* Manager::numtores(int id)
{
	int i;
	Node* cur=m_list.head;
	while(cur != NULL)
	{
		for(i=0; i< cur->data->count; i++)
		{
			if(cur->data->seat[i] == id)
			return cur->data;
		}
		cur=cur->next;
	}
	return NULL;
}
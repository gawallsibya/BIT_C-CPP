//manager.cpp
#include "std.h"

void Manager::ma_reserve()
{
	int i;
	
	Member *res = new Member; 
	m_arr.arr_info();
	
	while(1)
	{
		cout<<"����ż� �Է�: ";		cin>>res->count;
		if(res->count > 0 && res->count < 6)
			break;
		else
			cout<<"���Է�...\n";
	}
	for(i=0; i < res->count; i++)
	{
		cout<<"�¼� �Է� : ";		cin>>res->seat[i];
		if(m_arr.data[res->seat[i]-1] != NULL)
		{
			cout<<"���Է�...\n";
			i -= 1;
			continue;
		}
	}
	fflush(stdin);
	cout<<"��ȭ��ȣ �Է� : ";		gets(res->phone);
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
	cout<<"������ �Ϸ� �Ǿ����ϴ�..\n";
	cout<<"�����ȣ: "<<res->number<<endl; 
}
void Manager::ma_check()
{
	int num;
	char num1[20];
	Member* cur;
	cout<<"[1] ��ȭ��ȣ [2] ���� ��ȣ\n";
	
	while(1)
	{
		cin>>num;
		if(num==1)
		{
			cout<<"��ȭ��ȣ �Է�: "; 
			fflush(stdin);
			gets(num1);
			cur=m_list.list_search(num1);
			break;
		}
		else if(num==2)
		{
			cout<<"�����ȣ �Է�: "; 
			fflush(stdin);
			gets(num1);
			cur=m_list.list_search(num1);
			break;
		}
		else
		{
			cout<<"�ٽ� �Է��ϼ���..\n";
			continue;
		}
	}
	if(cur != NULL)
		m_list.list_print(cur);
	else
	{
		cout<<"���������� ã���� ����..\n";
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
	cout<<"[1] ��ȭ��ȣ [2] ���� ��ȣ\n";
	
	while(1)
	{
		cin>>num;
		if(num==1)
		{
			cout<<"��ȭ��ȣ �Է�: "; 
			fflush(stdin);
			gets(num1);
			cur=m_list.list_search(num1);
			break;
		}
		else if(num==2)
		{
			cout<<"�����ȣ �Է�: "; 
			fflush(stdin);
			gets(num1);
			cur=m_list.list_search(num1);
			break;
		}
		else
		{
			cout<<"�ٽ� �Է��ϼ���..\n";
			continue;
		}
	}
	if(cur != NULL)
		m_list.list_print(cur);
	else
	{
		cout<<"���������� ã���� ����..\n";
		return;
	}
	cout<<"\n�� ������ ����ұ��? : (y, n)";	
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
		cout<<"���ϴ� �¼��� �Է��Ͻÿ�..(0�� �Է½� ����)";
		cin>>num;
		if(num==0)
		return;
		cur = numtores(num);
		if(cur==NULL)
		cout<<"������� ����...\n";
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
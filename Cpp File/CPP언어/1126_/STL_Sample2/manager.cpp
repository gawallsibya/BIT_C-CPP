//manager.cpp

#include "std.h"


void Manager::Insert()
{
	char name[20];
	int   number;

	fflush(stdin);
	cout << "�� �� : ";  cin.getline(name, 20);
	cout << "�� �� : ";  cin >> number;

	Data *pData = new Data(name, number);

	vec.push_back(pData);
}

void Manager::PrintAll()
{
	cout << "[�� ü �� ��]" << endl; 
	if( vec.empty())
		return;

	cout << "���� ���� : " << vec.size() << endl; 
	for(int i=0; i<vec.size(); i++)
	{
		vec[i]->DataPrint();
	}
}


bool foo(Data *p, char*name)		// ���� �Լ� 
{
	if(strcmp(p->GetName(), name))
		return false;
	else
		return true;
}
// �����Լ� ==> ���� �Լ��� ����  : bind�� ����(bind�� �Լ� ��ü�� ��밡��)
// �Լ��� �Լ� ��ü�� ����         : function adapter(�Լ� �ƴ�Ÿ) 

void* Manager::DataSearch(const char*name, bool b /*=true*/)
{
	vector<Data*>::iterator p1;
	p1 = find_if(vec.begin(), vec.end(), bind2nd( ptr_fun(foo), name));
	if( p1 == vec.end())
		return NULL;
	
	if( b ) 
		return *p1;
	else
		return p1;
}

void Manager::Search()
{
	char name[20];

	fflush(stdin);
	cout << "�˻� �̸� : ";   cin.getline(name,20);
	Data *p = (Data*)DataSearch(name);
	if( p)
		p->DataPrint();
	else
		cout << "������ ����." << endl; 
}


void Manager::Modify()
{
	char name[20];
	int num;

	fflush(stdin);
	cout << "���� �̸� : ";   cin.getline(name,20);
	Data *p = (Data*)DataSearch(name);
	if( !p)
	{
		cout << "������ ����." << endl; 
		return;
	}
	cout << "[���� ������]\n";	p->DataPrint();

	cout << "���� �̸� : ";  cin.getline(name, 20);
	cout << "���� ��ȣ : ";  cin >> num;

	p->SetName(name);
	p->SetNum(num);
}


void Manager::Delete()
{
	char name[20];

	fflush(stdin);
	cout << "���� �̸� : ";   cin.getline(name,20);
	Data **p = (Data**)DataSearch(name, false);
	if( *p)
	{
		cout << "������ ����." << endl; 
		return;
	}
	cout << "[���� ������]\n";	(*p)->DataPrint();

	vector<Data*>::iterator p1 = vec.erase(p);
}
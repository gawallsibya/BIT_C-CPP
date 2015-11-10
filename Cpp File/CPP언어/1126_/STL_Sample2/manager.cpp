//manager.cpp

#include "std.h"


void Manager::Insert()
{
	char name[20];
	int   number;

	fflush(stdin);
	cout << "이 름 : ";  cin.getline(name, 20);
	cout << "학 번 : ";  cin >> number;

	Data *pData = new Data(name, number);

	vec.push_back(pData);
}

void Manager::PrintAll()
{
	cout << "[전 체 출 력]" << endl; 
	if( vec.empty())
		return;

	cout << "저장 개수 : " << vec.size() << endl; 
	for(int i=0; i<vec.size(); i++)
	{
		vec[i]->DataPrint();
	}
}


bool foo(Data *p, char*name)		// 이항 함수 
{
	if(strcmp(p->GetName(), name))
		return false;
	else
		return true;
}
// 이항함수 ==> 단항 함수로 변경  : bind의 개념(bind는 함수 객체만 사용가능)
// 함수를 함수 객체로 변경         : function adapter(함수 아답타) 

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
	cout << "검색 이름 : ";   cin.getline(name,20);
	Data *p = (Data*)DataSearch(name);
	if( p)
		p->DataPrint();
	else
		cout << "데이터 없다." << endl; 
}


void Manager::Modify()
{
	char name[20];
	int num;

	fflush(stdin);
	cout << "수정 이름 : ";   cin.getline(name,20);
	Data *p = (Data*)DataSearch(name);
	if( !p)
	{
		cout << "데이터 없다." << endl; 
		return;
	}
	cout << "[원본 데이터]\n";	p->DataPrint();

	cout << "수정 이름 : ";  cin.getline(name, 20);
	cout << "수정 번호 : ";  cin >> num;

	p->SetName(name);
	p->SetNum(num);
}


void Manager::Delete()
{
	char name[20];

	fflush(stdin);
	cout << "삭제 이름 : ";   cin.getline(name,20);
	Data **p = (Data**)DataSearch(name, false);
	if( *p)
	{
		cout << "데이터 없다." << endl; 
		return;
	}
	cout << "[원본 데이터]\n";	(*p)->DataPrint();

	vector<Data*>::iterator p1 = vec.erase(p);
}
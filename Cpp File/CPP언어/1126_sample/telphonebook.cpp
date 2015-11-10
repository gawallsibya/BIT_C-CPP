//telphonebook.cpp
#include "std.h"
#include "telphonebook.h"

void TelPhoneBook::Insert()
{
	cout << "[ INSERT ] " << endl; 

	char name[20], phone[30];
	cout << "name  : ";	gets(name);		
	cout << "phone : "; gets(phone);

	Person *p = new Person(name, phone);

	if (con.insert( p ))		// bool insert( Person * data);
		cout << "저장되었습니다..." << endl;
	else
		cout << "저장 실패..." << endl; 
}

void TelPhoneBook::PrintAllData() const
{
	cout << "[ PRINTALL ] " << endl; 

	for(int i=0; i< con.GetPidx(); i++)
	{

		Person *p =  con.GetData(i);   //
		p->DataPrint();
	}
}


void TelPhoneBook::Search()
{
	cout << "[ SEARCH ] " << endl; 

	//1. 검색명 입력 
	char name[20];
	cout << "search name : ";		gets(name);

	//2. 검색명의 idx 를 획득 
	int idx = NameToIdx(name);
	if( idx != -1)
	{
		//3. 획득한 idx에 위치한 person 객체 출력
		con.GetData(idx)->DataPrint();
	}
	else
	{
		cout << "해당 데이터가 존재하지 않습니다..." << endl; 
	}
}

int TelPhoneBook::NameToIdx(const char* name)
{
	for(int i=0; i< con.GetPidx(); i++)
	{
		if(strcmp( con.GetData(i)->GetName(), name) == 0)
			return i;
	}
	return -1;
}


void TelPhoneBook::Delete()
{
	cout << "[ DELETE ] " << endl;
	
	//1. 검색명 입력 
	char name[20];
	cout << "delete name : ";		gets(name);

	//2. 검색명의 idx 를 획득 
	int idx = NameToIdx(name);
	if( idx != -1)
	{
		 Person *p = con.DeleteData(idx);		// Person* DeleteData(int idx)
		 if( p != NULL)
		 {
			delete p;
			cout << "삭제 되었습니다...." << endl; 
		 }		
	}
	else
	{
		cout << "해당 데이터가 존재하지 않습니다..." << endl; 
	}
}


void TelPhoneBook::Update()
{
	cout << "[ UPDATE ] " << endl;
	
	//1. 검색명 입력 
	char name[20];
	cout << "update name : ";		gets(name);

	//2. 검색명의 idx 를 획득 
	int idx = NameToIdx(name);
	if( idx != -1)
	{
		//3. 획득한 idx에 위치한 person 객체 출력
		char name[20], phone[30];
		cout << "수정 이름 : ";		gets(name);
		cout << "수정 전번 : ";		gets(phone);
	
		Person *p = con.GetData(idx);
		p->SetName(name);
		p->SetPhone(phone);
		cout << "수정 되었습니다...." << endl; 
	}
	else
	{
		cout << "해당 데이터가 존재하지 않습니다..." << endl; 
	}
}

void TelPhoneBook::file_save()
{
	FILE *fp = fopen("data.ccm", "wb");
	if( fp == NULL)	{
		cout << "파일 저장 에러.." << endl;
		return;
	}
	int temp = con.GetPidx();
	fwrite(&temp, sizeof(int), 1, fp);
	for(int i=0; i< temp; i++)	
	{
		Person *p = con.GetData(i);
		fwrite(p, sizeof(Person), 1, fp);
	}
	fclose(fp);
}

void TelPhoneBook::file_load()
{
	FILE *fp = fopen("data.ccm", "rb");
	if( fp == NULL)	{
		return;
	}
	
	int idx;
	fread(&idx, sizeof(int), 1, fp);
	
	for(int i=0; i< idx; i++)
	{
		Person *p = new Person();
		fread(p, sizeof(Person), 1, fp);

		con.insert(p);
	//	phoneList[pidx] = p;
	//	pidx++;
	}
	fclose(fp);
}

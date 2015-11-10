//telphonebook.cpp
#include "std.h"
#include "telphonebook.h"

void TelPhoneBook::Insert()
{
	cout << "[ INSERT ] " << endl; 
	if( pidx >= DATA_MAX)
	{
		cout << "저장공간이 없습니다..." << endl; 
		return;
	}

	char name[20], phone[30];
	cout << "name  : ";	gets(name);		
	cout << "phone : "; gets(phone);

	Person p(name, phone);

	phoneList[pidx] = p;
	pidx++;

	cout << "저장되었습니다..." << endl;
}

void TelPhoneBook::PrintAllData() const
{
	cout << "[ PRINTALL ] " << endl; 

	for(int i=0; i< pidx; i++)
	{
	//	phoneList[i].DataPrint();
		Person p = phoneList[i];
		p.DataPrint();
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
		phoneList[idx].DataPrint();
	}
	else
	{
		cout << "해당 데이터가 존재하지 않습니다..." << endl; 
	}
}

int TelPhoneBook::NameToIdx(const char* name)
{
	for(int i=0; i< pidx; i++)
	{
		if(strcmp( phoneList[i].GetName(), name) == 0)
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
		//3. 획득한 idx에 위치한 person 객체 출력
		for(int i= idx; i<pidx; i++)
		{
			phoneList[i] = phoneList[i+1];
		}
		pidx--;
		cout << "삭제 되었습니다...." << endl; 
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

		phoneList[idx].SetName(name);
		phoneList[idx].SetPhone(phone);
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
	if( fp == NULL)
	{
		cout << "파일 저장 에러.." << endl;
		return;
	}

	fwrite(&pidx, sizeof(int), 1, fp);
	fwrite(phoneList, sizeof(phoneList), 1, fp);
	fclose(fp);
}

void TelPhoneBook::file_load()
{
	FILE *fp = fopen("data.ccm", "rb");
	if( fp == NULL)
	{
		return;
	}

	fread(&pidx, sizeof(int), 1, fp);
	fread(phoneList, sizeof(phoneList), 1, fp);
	fclose(fp);
}

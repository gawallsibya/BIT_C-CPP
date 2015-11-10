//telphonebook.cpp
#include "std.h"
#include "telphonebook.h"

void TelPhoneBook::Insert()
{
	cout << "[ INSERT ] " << endl; 
	if( pidx >= DATA_MAX)
	{
		cout << "��������� �����ϴ�..." << endl; 
		return;
	}

	char name[20], phone[30];
	cout << "name  : ";	gets(name);		
	cout << "phone : "; gets(phone);

	Person p(name, phone);

	phoneList[pidx] = p;
	pidx++;

	cout << "����Ǿ����ϴ�..." << endl;
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

	//1. �˻��� �Է� 
	char name[20];
	cout << "search name : ";		gets(name);

	//2. �˻����� idx �� ȹ�� 
	int idx = NameToIdx(name);
	if( idx != -1)
	{
		//3. ȹ���� idx�� ��ġ�� person ��ü ���
		phoneList[idx].DataPrint();
	}
	else
	{
		cout << "�ش� �����Ͱ� �������� �ʽ��ϴ�..." << endl; 
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
	
	//1. �˻��� �Է� 
	char name[20];
	cout << "delete name : ";		gets(name);

	//2. �˻����� idx �� ȹ�� 
	int idx = NameToIdx(name);
	if( idx != -1)
	{
		//3. ȹ���� idx�� ��ġ�� person ��ü ���
		for(int i= idx; i<pidx; i++)
		{
			phoneList[i] = phoneList[i+1];
		}
		pidx--;
		cout << "���� �Ǿ����ϴ�...." << endl; 
	}
	else
	{
		cout << "�ش� �����Ͱ� �������� �ʽ��ϴ�..." << endl; 
	}
}


void TelPhoneBook::Update()
{
	cout << "[ UPDATE ] " << endl;
	
	//1. �˻��� �Է� 
	char name[20];
	cout << "update name : ";		gets(name);

	//2. �˻����� idx �� ȹ�� 
	int idx = NameToIdx(name);
	if( idx != -1)
	{
		//3. ȹ���� idx�� ��ġ�� person ��ü ���
		char name[20], phone[30];
		cout << "���� �̸� : ";		gets(name);
		cout << "���� ���� : ";		gets(phone);

		phoneList[idx].SetName(name);
		phoneList[idx].SetPhone(phone);
		cout << "���� �Ǿ����ϴ�...." << endl; 
	}
	else
	{
		cout << "�ش� �����Ͱ� �������� �ʽ��ϴ�..." << endl; 
	}
}

void TelPhoneBook::file_save()
{
	FILE *fp = fopen("data.ccm", "wb");
	if( fp == NULL)
	{
		cout << "���� ���� ����.." << endl;
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

//cdplayer.cpp
#include "std.h"
#include "cdplayer.h"

CDPlayer::CDPlayer()
:p(NULL), state(OUT1)
{

}

void CDPlayer::ToStringState()
{
	if(state == IN_STOP1)
	{
		cout << "���� ���� : IN_STOP" << endl;
	}
	else if(state == OUT1)
	{
		cout << "���� ���� : OUT" << endl;
	}
	else if(state == PLAY1)
	{
		cout << "���� ���� : PLAY" << endl; 
	}
}

void CDPlayer::CD_In(CD* p1[])
{
	char temp[20];
	if( state == OUT1 )
	{
		// CD List ���
		for(int i=0; i<3; i++)
		{			
			p1[i]->DataPrint();
		}
		// ����� �Է�
		cout << "���ϴ� CD�� ������ �Է� : " ;		cin.getline(temp,20);
			
		// ����
		for(i=0; i<3; i++)
		{
			if( strcmp( temp, p1[i]->GetName()) == 0)
			{
				p		= p1[i];
				state	= IN_STOP1;
				cout << "CD�� ���õǾ����ϴ�..."  << endl; 
			}
		}
	}
	else
	{
		cout << "CD�� �����մϴ�.." << endl; 
	}
}

void CDPlayer::CD_Play()
{
	if( state == IN_STOP1)
	{
		cout <<"CD�� : " <<  p->GetName();

		cout << endl;
		for(int i=0; i<3; i++)
		{
			cout <<"[" << i+1 << "]" <<p->GetTrack(i)<< endl;
			Sleep(1000);		// windows.h
		}
		state = PLAY1;
	}
	else
	{
		cout << "CD�� PLAY ���̰ų�, CD�� ���� ����.." << endl; 
	}
}
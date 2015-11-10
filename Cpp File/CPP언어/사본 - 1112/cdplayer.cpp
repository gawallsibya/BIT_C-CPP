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
		cout << "현재 상태 : IN_STOP" << endl;
	}
	else if(state == OUT1)
	{
		cout << "현재 상태 : OUT" << endl;
	}
	else if(state == PLAY1)
	{
		cout << "현재 상태 : PLAY" << endl; 
	}
}

void CDPlayer::CD_In(CD* p1[])
{
	char temp[20];
	if( state == OUT1 )
	{
		// CD List 출력
		for(int i=0; i<3; i++)
		{			
			p1[i]->DataPrint();
		}
		// 사용자 입력
		cout << "원하는 CD의 제목을 입력 : " ;		cin.getline(temp,20);
			
		// 선택
		for(i=0; i<3; i++)
		{
			if( strcmp( temp, p1[i]->GetName()) == 0)
			{
				p		= p1[i];
				state	= IN_STOP1;
				cout << "CD가 선택되었습니다..."  << endl; 
			}
		}
	}
	else
	{
		cout << "CD가 존재합니다.." << endl; 
	}
}

void CDPlayer::CD_Play()
{
	if( state == IN_STOP1)
	{
		cout <<"CD명 : " <<  p->GetName();

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
		cout << "CD가 PLAY 중이거나, CD가 없는 상태.." << endl; 
	}
}
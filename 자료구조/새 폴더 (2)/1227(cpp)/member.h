#ifndef _MEMBER_H_
#define _MEMBER_H_

class Member
{
public:
	char phone[20];     //전화
	char number[5];     //예약번호
	int count;          //매수
	int seat[5];        //좌석번호
public:
	Member() {}
	void mem_print();
	int GeTCount() {return count;}
	char* GetPhone() {return phone;}
	char* GetNum() {return number;}
};



#endif /*_MEMBER_H_*/
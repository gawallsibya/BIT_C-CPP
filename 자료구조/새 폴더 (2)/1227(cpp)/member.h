#ifndef _MEMBER_H_
#define _MEMBER_H_

class Member
{
public:
	char phone[20];     //��ȭ
	char number[5];     //�����ȣ
	int count;          //�ż�
	int seat[5];        //�¼���ȣ
public:
	Member() {}
	void mem_print();
	int GeTCount() {return count;}
	char* GetPhone() {return phone;}
	char* GetNum() {return number;}
};



#endif /*_MEMBER_H_*/
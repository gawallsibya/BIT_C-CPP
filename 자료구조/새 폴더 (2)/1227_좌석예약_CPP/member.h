//member.h
#ifndef _MEMBER_H_
#define _MEMBER_H_
#define NULL 0
class Member
{
private:
	string n;
	string phone;
	int count;
	int num[5];
public:
	Member(){}
	~Member(){}

	void setn(string _n){n = _n;}
	void setphone(string _phone){phone = _phone;}
	void setcount(int _count){count = _count;}
	void setnum(int i,int _num){num[i] = _num;}

	string getphone(){return phone;}
	string getn(){return n;}
	int getcount(){return count;}
	int gernum(int i){return num[i];}
};
#endif /*_MEMBER_H_*/

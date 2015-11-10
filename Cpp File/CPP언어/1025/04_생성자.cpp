#include <iostream>
using namespace std;

// 생성자
/*(
class CA
{
	int num;
	char name[20];
public:
	// 리턴값이 X, 이름이 클래스명과 동일

	// 디폴트 생성자 : 인자가 없는 생성자
	CA() { cout << "CA() 생성자" << endl; }	
	CA( int _num, char* _name) 
	{
		num = _num;		strcpy(name, _name);
		cout << "CA(int, char*)생성자" << endl; 
	}
};

void main()
{
	CA		a;
	CA		a1(10, "홍길동");
}
*/

class CA
{
	int num;
public:
	CA()      { num = 10;}
	CA(int n) {}
	CA(int n1, int int2) {}
};

void main()
{
	CA a;		// 인스턴스 생성
	CA a1(10);
	CA a2(20,30);
}
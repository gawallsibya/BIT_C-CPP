#include <iostream>
using namespace std;

// ������
/*(
class CA
{
	int num;
	char name[20];
public:
	// ���ϰ��� X, �̸��� Ŭ������� ����

	// ����Ʈ ������ : ���ڰ� ���� ������
	CA() { cout << "CA() ������" << endl; }	
	CA( int _num, char* _name) 
	{
		num = _num;		strcpy(name, _name);
		cout << "CA(int, char*)������" << endl; 
	}
};

void main()
{
	CA		a;
	CA		a1(10, "ȫ�浿");
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
	CA a;		// �ν��Ͻ� ����
	CA a1(10);
	CA a2(20,30);
}
#include <iostream>
using namespace std;

#define ADD(X,Y) X+Y		// C���� ���� ��� : ��ũ�� �Լ�
// 1. �Լ� ȣ��߻� X			 ==> inline
// 2. Ÿ�Կ� ���� ����.(�Ϲ�ȭ)	 ==> overloading , template
// 3. ���� : �ڵ� ũ�⸦ ����..	==>  inline


inline int ADD(int x, int y)
{
	return x+y;
}


void main()
{
	cout << ADD(10, 20) << endl;	// cout <<10+20 << endl;
	cout << ADD(10.1, 20.1) << endl;	// cout << 10.1 + 20.1 << endl;
}
/************************************************************
  04. ���� class �� ���������� �����ϵ��� �����ڸ� �ϼ��Ͻÿ�
      (�⺻���� ��� �� �� : �⺻���� 50)

      �����ڿ��� ���� ���ڸ� m_nMineral�� �����Ͻÿ�. 
*************************************************************/
#include <iostream>
using namespace std;

class Teran  
{
    int m_nMineral;

public:
	Teran (int a = 50) : m_nMineral(a) {cout << m_nMineral << endl;}

};

void main()
{
   Teran a(10);
   Teran b;
}

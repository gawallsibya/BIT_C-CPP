/************************************************************
  04. 다음 class 가 정상적으로 동작하도록 생성자를 완성하시오
      (기본값을 사용 할 것 : 기본값은 50)

      생성자에서 받은 인자를 m_nMineral에 저장하시오. 
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

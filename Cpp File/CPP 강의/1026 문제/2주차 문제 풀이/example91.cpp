/************************************************************
  10. 1) class의 맴버 변수가 다음과 같을 때  
         생성자 소멸자를 구현하시오.
         단, 생성자는 디폴트 생성자와 매개변수를 2개 가지는 
	     생성자를 각각 구현할 것

      2) 복사 생성자를 구현하시오.

      3) 소멸자를 구현하시오.

      4) Get/Set Method를 구현하시오. (하나의 변수만 처리한다.)
         단 입력시 미네랄과 가스의 값은 10이하의 값만 받을 수 있다.

      5) StargateBuild  Method를 구현하시오.
         단 Stargate을 생성하려면 미네랄 150, 가스100이 필요하다. 
         해당 자원이 있다면 Stargate 생성이라는 메시지를 화면에 출력하세요.
*************************************************************/
#include <iostream>
using namespace std;

class Teran
{
	int *pMineral;
    int  m_nGas;
public:
	Teran() { pMineral = NULL; } // 반드시 초기화를 진행해야한다.

	Teran(int a, int b)
	{
		pMineral = new int(a); //*pMineral = a;
		m_nGas = b;
	}

	Teran (const Teran & A)
	{
		pMineral = new int(*A.pMineral);
		m_nGas = A.m_nGas;
	}

	~Teran() // if문으로 Teran t; 객체가 생성되었을때 소멸자를 걸러준다.
	{
		if( pMineral != NULL)
			delete pMineral;
	}

	int GetGas() const { return m_nGas; }
	void SetGas(int g) { if(g<=10) m_nGas = g;	}
	int GetMineral() const { return *pMineral; }
	void SetMineral(int m) { if(m<=10) *pMineral = m;    }

	void StargateBuild()
	{
		if(*pMineral > 150 && m_nGas > 100)
			cout << "Stargate 생성" << endl;
	}

};

void main()
{
	Teran t;
	Teran  *t1 = new Teran(10, 20);
	Teran t2(10, 20);
	t.StargateBuild();
}
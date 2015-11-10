/************************************************************
  10. 1) class�� �ɹ� ������ ������ ���� ��  
         ������ �Ҹ��ڸ� �����Ͻÿ�.
         ��, �����ڴ� ����Ʈ �����ڿ� �Ű������� 2�� ������ 
	     �����ڸ� ���� ������ ��

      2) ���� �����ڸ� �����Ͻÿ�.

      3) �Ҹ��ڸ� �����Ͻÿ�.

      4) Get/Set Method�� �����Ͻÿ�. (�ϳ��� ������ ó���Ѵ�.)
         �� �Է½� �̳׶��� ������ ���� 10������ ���� ���� �� �ִ�.

      5) StargateBuild  Method�� �����Ͻÿ�.
         �� Stargate�� �����Ϸ��� �̳׶� 150, ����100�� �ʿ��ϴ�. 
         �ش� �ڿ��� �ִٸ� Stargate �����̶�� �޽����� ȭ�鿡 ����ϼ���.
*************************************************************/
#include <iostream>
using namespace std;

class Teran
{
	int *pMineral;
    int  m_nGas;
public:
	Teran() { pMineral = NULL; } // �ݵ�� �ʱ�ȭ�� �����ؾ��Ѵ�.

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

	~Teran() // if������ Teran t; ��ü�� �����Ǿ����� �Ҹ��ڸ� �ɷ��ش�.
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
			cout << "Stargate ����" << endl;
	}

};

void main()
{
	Teran t;
	Teran  *t1 = new Teran(10, 20);
	Teran t2(10, 20);
	t.StargateBuild();
}
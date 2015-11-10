/************************************************************
  06. 다중 정의되어 있는 함수들을 기본값을 갖는 함수 하나로 
      변경하시오.

*************************************************************/

class CA
{
public:
	void DrawShape( int a, int b)
	{
	}
	void DrawShape( int a)
	{
	}
};

void main()
{
	CA a;
	a.DrawShape(10, 20);
	a.DrawShape(10);
}

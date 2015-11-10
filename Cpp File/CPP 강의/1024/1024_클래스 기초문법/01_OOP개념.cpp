/**********************************************************
 [ oop ���� ] 
 OOP�� ? �Լ��� ������ ���հ���
 OOP�� 3�� ��� = ĸ��ȭ + ��Ӽ� + ������
**********************************************************/
/*

============================================================
 Solution1 .  ����ü�� ������� ���� ��� 
============================================================

#include <iostream>
using namespace std;

int CalcRectArea( int left, int top, int right, int bottom)
{
	return ( right - left) * ( bottom - top );
}

int CalcCircleArea( int radius )
{
	return 3.14 * 3.14 * radius;
}

void main()
{
	int s1 = CalcRectArea( 10, 10, 20, 20);
	cout << s1 << endl; 

	int s2 = CalcCircleArea( 5);
	cout << s2 << endl;
}


============================================================
 Solution2 .  ����ü�� ����ϴ� ��� 
============================================================
#include <iostream>
using namespace std;

struct RECT
{
	int left;
	int top;
	int right;
	int bottom;
};

struct CIRCLE
{
	int ox;
	int oy;
	int radius;
};

int CalcRectArea( const RECT& r )
{
	return (r.right - r.left)*(r.bottom-r.top);
}

int CalcCircleArea( const CIRCLE& c )
{
	return 3.14 * 3.14 * c.radius;
}

void main()
{
	RECT r = { 10, 10, 20, 20 };
	CIRCLE c = { 0, 0, 5 };

	int s1 = CalcRectArea( r );
	cout << s1 << endl; 

	int s2 = CalcCircleArea( c);
	cout << s2 << endl;
}


============================================================
 Solution3 .  OOP (Encapsulation) 
============================================================
#include <iostream>
using namespace std;

struct RECT
{
	int left;
	int top;
	int right;
	int bottom;

	int CalcArea( )
	{
		return (right - left) * (bottom-top);
	}
};

struct CIRCLE
{
	int ox;
	int oy;
	int radius;

	int CalcArea(  )
	{
		return 3.14 * 3.14 * radius;
	}
};

void main()
{
	RECT r = { 10, 10, 20, 20 };
	CIRCLE c = { 0, 0, 5 };

	cout << r.CalcArea() << endl;
	cout << c.CalcArea() << endl;
}



============================================================
 �Լ� �߽� Vs ��ü �߽� 
============================================================
#include <iostream>
using namespace std;

int CalcRectArea( int left, int top, int right, int bottom)
{
	return ( right - left) * ( bottom - top );
}

void main()
{
	int s1 = CalcRectArea( 10, 10, 20, 20);
	cout << s1 << endl; 
}
-------------------------------------------------------
#include <iostream>
using namespace std;

struct RECT
{
	int left;
	int top;
	int right;
	int bottom;

	int CalcArea( )
	{
		return (right - left) * (bottom-top);
	}
};

void main()
{
	RECT r = { 10, 10, 20, 20 };

	cout << r.CalcArea() << endl;
}



============================================================
  More Interface 
============================================================

#include <iostream>
using namespace std;

struct CRect
{
	int left;
	int top;
	int right;
	int bottom;

	int CalcArea( )
	{
		return (right - left) * (bottom-top);
	}
	void SetRect( int l, int t, int r, int b)
	{
		left = l;
		top = t;
		right = r;
		bottom = b;
	}
	int Width() { return right - left; }
	int Height() { return bottom - top;}
	void Draw() 
	{ 
		char temp[256];
		sprintf( temp, "Draw Rectangle (%d, %d) ~ (%d, %d)", left, top, right, bottom);
		cout << temp << endl;
	}	
	void Move( int dx, int dy )
	{
		left   += dx;
		right  += dx;
		top    += dy;
		bottom += dy;
	}
	bool PtInRect( int x, int y )
	{
		if (  x >= left && x <= right &&
			  y >= top  && y <= bottom )
			  return true;
		return false;
	}
};
void main()
{
	CRect r = { 10, 10, 30, 20 };
	cout << r.CalcArea() << endl;

	r.SetRect( 0, 0, 100,100);
	r.Draw();
	r.Move( 5, 5 );
	r.Draw();

	int x, y;
	while( 1 )
	{
		cout << "Input x y ( quit : -1 ) --> ";
		cin >> x;
		if ( x == -1 ) break;		
		cin >> y;

		if ( r.PtInRect( x, y ) )
			cout << "�簢�� �ȿ� �ִ� ���Դϴ�." << endl;
		else
			cout << "�簢�� �ۿ� �ִ� ���Դϴ�." << endl;
	}
}

============================================================
 ������ ���α׷����� ����� ��ü���� ���α׷����� ���� ��  
============================================================
1. �ֿ� ����
   - ���(Function, Process) ����
   - Data ����

2. ���� ���
   - �����(Top Down)   ��������(Divide and Conquer)
   - �����(Botton up)  ��ȣ ��������

3. ���⹰ ����
   - Tree ����
   - �׷���, ��Ʈ��ũ ����

4. �� ��
   -  ó������ ���ϴ� ������ ������ ����� ���ַ� 
      �����ϹǷ� �ذ�å�� ���ϱⰡ ����

      ���� �Ⱓ�� ª���� �� �ִ�. 
	  Ư�� �䱸 ������ �� �˰� �ִ� ���¿��� �ñ��� 
	  ������ �ʿ��� ��� �����ϴ�
  
    - ���ߵ� �ذ�å�� �������� �� �� ��뼺�� ���ϴ�.
      
	  �䱸 ������ ��ȭ�� ���� ��ó�� �� �ִ�.

      �м��� ���� �ܰ迡�� ����ϴ� ���� ���� �ϹǷ�, 
	  �м����� ������� ���̰� ���ϴ�.

      ������ ���α׷��̳� ��� ��Ű���� ����Ͽ� �����ϴ� 
	  ���� ����.

      ���踦 �����Ѵ�.

5. �� ��
   -  �䱸 ���� ��ȭ�� ����ϸ�, �̷� ���� ��������, 
      ������ �����.

      �м������ ���� ������� ���� ������ �Ų����� ���ϴ�.

      �˰����̳� ����� �߽����� �� ���� ����̱� ������ 
	  ���� ������ �Ұ����ϰ�, �� �κ��� ���濡 ���� ���� �޴� 
	  ������ �������� �����.

    - ���� �ý����� ���, ��ӱ����� ��ü���� ��ȣ �ۿ��� 
	  �ʹ� ������ �� �� ������, �ٷ��� �� ��ü�� ���� �� ��
	  �ִ�.

      ����ý����� ���� ����� ���� ����� �������� �ʾҴ�.

      �������� �ý��� �������� ����̳� ���� �м� ����� 
	  ���ȵ� ���� ���� ����, ������ ��ü�� ���� �ϴ� �͵� 
	  �����.  

6. �Ǽ���� ������ ������ ���̼�
   - ��� �����̹Ƿ� �Ǽ���� ������ ������ �����. 
  
   - ��ü�� ���� �Ǽ������ ������ ������ ���� ����.

7. �ֿ� ���� �о� 
   - ����̳� ������ �˰��� �߽��� ���� �о�

   - Ŀ�´����̼��� ���� �о� �Ǵ� �ùķ��̼�, 
     ����Ͻ� ����о�


*/
  
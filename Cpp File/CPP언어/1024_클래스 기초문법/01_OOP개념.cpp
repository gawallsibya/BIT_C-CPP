/**********************************************************
 [ oop 개념 ] 
 OOP란 ? 함수와 변수를 통합관리
 OOP의 3대 요소 = 캡슐화 + 상속성 + 다형성
**********************************************************/
/*

============================================================
 Solution1 .  구조체를 사용하지 않은 경우 
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
 Solution2 .  구조체를 사용하는 경우 
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
 함수 중심 Vs 객체 중심 
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
			cout << "사각형 안에 있는 점입니다." << endl;
		else
			cout << "사각형 밖에 있는 점입니다." << endl;
	}
}

============================================================
 구조적 프로그래밍의 개념과 객체지향 프로그래밍의 개념 비교  
============================================================
1. 주요 관점
   - 기능(Function, Process) 위주
   - Data 위주

2. 접근 방식
   - 하향식(Top Down)   분할정복(Divide and Conquer)
   - 상향식(Botton up)  상호 관계정의

3. 산출물 구조
   - Tree 구조
   - 그래프, 네트워크 구조

4. 장 점
   -  처음부터 원하는 목적을 수행할 기능을 위주로 
      생각하므로 해결책을 구하기가 쉽다

      개발 기간이 짧아질 수 있다. 
	  특히 요구 사항을 잘 알고 있는 상태에서 시급히 
	  개발이 필요한 경우 적합하다
  
    - 개발된 해결책의 유지보수 및 재 사용성이 편리하다.
      
	  요구 사항의 변화에 쉽게 대처할 수 있다.

      분석과 설계 단계에서 사용하는 모델이 동일 하므로, 
	  분석에서 설계로의 전이가 편리하다.

      기존의 프로그램이나 상용 패키지를 상속하여 재사용하는 
	  것이 쉽다.

      설계를 강요한다.

5. 단 점
   -  요구 사항 변화에 취약하며, 이로 인해 유지보수, 
      관리가 힘들다.

      분석결과로 부터 설계로의 전이 과정이 매끄럽지 못하다.

      알고리즘이나 기능을 중심으로 한 접근 방법이기 때문에 
	  잦은 변경이 불가피하고, 한 부분의 변경에 의해 영향 받는 
	  범위를 구분짓기 힘들다.

    - 대형 시스템의 경우, 상속구조나 객체간의 상호 작용이 
	  너무 복잡해 질 수 있으며, 다루어야 할 객체도 많아 질 수
	  있다.

      서브시스템의 정의 방법이 아직 제대로 정립되지 않았다.

      아직까지 시스템 전반적인 기능이나 행위 분석 방법이 
	  제안된 것이 거의 없고, 적절한 객체를 정의 하는 것도 
	  힘들다.  

6. 실세계와 개념적 대응의 용이성
   - 기능 위주이므로 실세계와 개념적 대응이 힘들다. 
  
   - 객체를 통한 실세계와의 개념적 대응이 비교적 쉽다.

7. 주요 응용 분야 
   - 계산이나 복잡한 알고리즘 중심의 응용 분야

   - 커뮤니케이션이 많은 분야 또는 시뮬레이션, 
     비즈니스 응용분야


*/
  
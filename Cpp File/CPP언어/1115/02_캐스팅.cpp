//-------------------------------------------------------------------------
//1 casting이란?

//   1) C의 모든 메모리는 type이 있다.

//   2) 기존의 메모리를 다른 type으로 접근할수 있게 하는 도구.
//-------------------------------------------------------------------------


#include <iostream>
using namespace std;

/*
void main()
{
             char c = 0x41;
             int  n = 0x41;
             n = 0x41424344;
//           char * p = &n;       //error C에서 포인터는 반드시 동일 type을 사용 해야 한다.
             char * p = (char*)&n;
             cout << p[0] << p[1] << p[2] << p[3] << endl;
}
*/
 


//-------------------------------------------------------------------------
// 2. C casting 의 문제점. 
//    -  천하무적. 대부분 성공.
//       말도 안되는 경우가 허용된다. - 비이성적인 캐스팅이다.
//-------------------------------------------------------------------------

/*
void main()
{
	int n = 0;
	double* p1 = (double*)&n;     //C casting은 너무나 위험하다.
	
	//모든 버그의 원인이 된다.
//	*p1 = 1;
	cout << n << endl;      //메모리 error
	
	////////////////////////////////////////////////////////////////////////////

	const int c = 10;
	int *p = (int *)&c;        //int* = &const int;
	*p = 20;                 //컴파일 에러가 나지 않는다.
	cout << c << endl;      //값은 10이다.
}
*/
 

//-------------------------------------------------------------------------
//3. C++ casting

//4 가지의 casting 연산자 제공.

   //1> static_cast : 논리적으로 말이 되는 경우만 허용.
   //2> reinterpret_cast : 비론리적이라도 허용.(대부분 허용.)
   //3> const_cast  : const를 비const로 바꾼다.
   //4> dynamic_cast : RTTI 위해서 사용. 상속에서 등장 합니다.

   //C 캐스팅 : static_cast + reinterpret_cast + const_cast의 3가지
   //                                     기능을 합한것.!!
//-------------------------------------------------------------------------
/*
void main()
{
	double d = 3.4;
	int n = (int)d;        //ok
	
	//template 함수에서 인자의 type을 명시적으로 지정하는 표현.
	
	int n1 = static_cast<int>(d);   //ok
	
	//-------------------------------------
	
	//서로 다른 type의 주소를 담는 casting의 경우.
	
	double* p1 = (double*)&n;           //ok
	
//	double* p2 = static_cast<double*>(&n); // 위험하다 error
	
	double* p3 = reinterpret_cast<double*>(&n);  // ok강제로 라도 해달라.
	
	
	
	//const를 제거 하는 cast
	
	const int c = 10;
	
	int* p11 = (int*)&c;                   //ok
	
//	int* p12 = static_cast<int*>(&c);           //error 너무 위험.
	
//	int* p13 = reinterpret_cast<int*>(&c);   //error 너무 위험.
	
	//cont를 제거할수는 없다.
	
	
	
	//동일 type에 대해 const를 제거 할 때 사용.
	
	int* p21 = const_cast<int*>(&c);  //ok 
	
}

*/
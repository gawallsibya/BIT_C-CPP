/*********************************************************************************
1.	const 관련 내용이다. 에러를 찾고, 이유를 설명하시오.
**********************************************************************************/
/*
void main()
{
	int a = 10;		
	const int *p1 = &a;			//p1의 역참조 값 상수화
	int* const p2 = &a;			//p2의 주소값 상수화
	//*p1 = 20;					//p1의 값을 상수화 시켰기 때문에 대입 불가.
	p1 = &b;
	*p2 = 20;					//p2의 주소값을 상수화하였기 때문에 변수값은 변경 가능.
    p2 = &b;
}*/

/************************************************************************************
2.	아래 구문의 의미를 적고, 각각에 대한 메모리 해지 구문을 작성하시오.
************************************************************************************/

int* p4 = new int[2];	
delete [] p4;

int* p5 = new int(2); 
delete p5;

int* p3 = new int;
delete p3;

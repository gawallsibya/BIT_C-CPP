/*
1. 아래에 해당하는 함수의 선언부를 작성하시오.
?1.1 함수 sum2()는 두 개의 int 형 인자를 사용하고 반환 값은 int 형을 나타내는 함수
*/
int sum2(int, int);

//1.2 함수 int2double()은 한 개의 정수 인자를 사용하고, double 유형의 자료값을 반환 
double int2double(int);

//?1.3 함수 print()는 인자도 없고 반환 값도 없음.
void print();

//  1.4 함수 sum2()는 두 개의 int 형 인자를 사용하고 반환 값은 int 형 
int sum2(int, int);
  
//  1.5 함수 sum3()는 세 개의 int 형 인자를 사용하고 반환 값은 int 형 
int sum3(int, int, int);


//6. 아래 구문에 해당하는 함수를 구현하시오.
int IncrementNumber(int n);

void main()
{
	int num = 10;

	num = IncrementNumber(num);  // 전달받은 값을 1더한 결과를 리턴하는 함수
	
	printf("%d\n", num);
}

int IncrementNumber(int n)
{
	return n+1;
}


//7. 
int Is_Number(char ch);

void main()
{
    char ch = '9'
    if( Is_Number(  ch ) )	    // 전달받은 값이 숫자이면 1, 문자이면 0을 리턴하는 함수
        printf("숫자\n");
    else 
        printf("문자\n");
}

int Is_Number(char ch)
{
	if( '0' >= ch  && ch <= '0')
		return 1;
	else
		return 0;
}

//8. 

int MyAdd(int n1, int n2);

void main( )
{
   int num1 = 10, num2 = 20;
   int result;
   result = MyAdd( num1, num2 );   // 전달받은 값의 합을 리턴하는 함수
   printf("%d", result);
}
int MyAdd(int n1, int n2)
{
	return n1 + n2;
}


//9. 주어진 함수를 사용하여 number의 값을 출력하시오.

void PrintNumber(int num )
{
    printf("%d\n", num);
}

void main()
{
	int number = 100;
	PrintNumber(number);
}

//10. 사용자가 전달한 정수의 값을 제곱하여 리턴하는 함수를 구현하고 사용하시오.

int MulNum(int n);

void main()
{
	int num  = 10;
	num		 = MulNum(num);
}

int MulNum(int n)
{
	return n*n;
}
   





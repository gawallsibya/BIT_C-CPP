//fun.c
#include "std.h"

/*
1. 자신의 이름을 gets() 함수로 입력받아
   printf() 함수로 출력
*/
void fun_1()
{
	char name[20];
	printf("입력 : ");	gets(name);

	printf("이름 : %s\n", name);
}


/*
2. 변수에 상수를 입력 후 출력 '=' 사용
   정수형(10진수, 8진수, 16진수로 출력)
   실수형(소숫점 2째 자리까지 출력) 
   1개의 문자(문자 및 10진수로 각각 출력)
   각각 변수의 주소값 출력(16진수로 출력)
*/
void fun_2()
{
	int		num		= 10;
	double	d_num	= 123.456;
	char	ch		= 'A';

	printf("%d :%o : 0x%x\n", num, num,num);
	printf("%.2f\n", d_num);
	printf("%c : %d\n", ch, ch);

	printf("%p : %p: %p\n", &num, &d_num, &ch);
}


/*
3. 소수점 3자리 실수를 입력 받아 
   첫째, 둘째, 셋째 자리에서 각각 반올림하여 출력
   예) 소수점 3자리 실수 입력 : (12.345)
       출력 : 12, 12.3, 12.35
*/
void fun_3()
{
	float	f;
	printf("소수점 3자리 실수 입력 : ");	scanf("%f", &f);
	printf("%.f : %.1f : %.2f\n", f, f,f);
}


/*
4. 화씨 온도를 입력한 후 섭씨온도로 출력(단, 소수 첫째 자리까지)
   참조) 섭씨온도 = 5 / 9 * (화씨온도 - 32 )

*/
void fun_4()
{
	int   c;
	float f;
	printf("화씨 온도 : ");		scanf("%d", &c);

	f	= (float)5 / 9 * ( c - 32 );
	printf("섭씨 온도 : %.1f도\n", f);
}


/*
5. 세 개의 정수를 입력한 후 합계와 평균을 출력
   (단, 평균은 소수 둘째 자리에서 반올림)
*/
void fun_5()
{
	int num;
	int sum = 0;
	printf("정수 입력 : ");		scanf("%d", &num);
	sum		+= num;

	printf("정수 입력 : ");		scanf("%d", &num);
	sum		+= num;

	printf("정수 입력 : ");		scanf("%d", &num);
	sum		+= num;

	printf("합계 : %d\n", sum);
	printf("평균 : %.2f\n", (float)sum/3);
}


/*
6. 한 개의 영문자를 입력한 후 알파벳에서 몇 
   번째 문자인지 출력 
   출력예) 영문자 입력 : C
           결과 : C는 3번째 알파벳이다.

*/
void fun_6()
{
	char ch;
	int  idx;
	printf("영문자 입력 : ");	scanf("%c", &ch);

	idx	= (ch>=97) ? ch-'a'+1  : ch -'A'+1;
	printf("결과 : %c는 %d번째 알파벳이다.\n", ch, idx);
}

/*
7. 두 개의 정수를 두 개의 변수에 입력한 후 내용을
   서로 교환하여 출력
   출력예) 두 정수  : 1, 2
           교환결과 : 2, 1
*/
void fun_7()
{
	int num1 = 10, num2 = 20, temp;

	printf("두 정수  : %d, %d\n", num1, num2);

	temp = num1;
	num1 = num2;
	num2 = temp;

	printf("교환결과 : %d, %d\n", num1, num2);
}

/*
9. 두 수를 입력 받아 덧셈 연산
   출력예) 정수 입력 : 3
           정수 입력 : 2
           두 정수의 합 : 5
*/
void fun_9()
{
	int num, num1;

	printf("정수 입력 : ");	scanf("%d", &num);
	printf("정수 입력 : "); scanf("%d", &num1);
	printf("두 정수의 합 : %d\n", num + num1);
}


/*
10. 문자 하나를 입력받아 숫자로 변환하여 출력
     출력예) 문자입력 : 3
             숫    자 : 3
*/
void fun_10()
{
	char ch;
	int  num;
	printf("문자입력 : ");	scanf("%c", &ch);

	num	= ch - '0';
	printf("숫    자 : %d\n", num);
}

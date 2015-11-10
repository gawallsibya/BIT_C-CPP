//fun2.c
#include "std.h"


/*
1. while 문과 for문을 이용하여 Hello World!를 각각 10번씩 출력
*/
void fun2_1()
{
	int count = 0;
	while( count != 10)
	{
		printf("[%2d]Hello World!\n", count+1);
		++count;
	}
	printf("\n");

	count = 0;
	while(1)
	{
		if( count == 10)
			break;

		printf("[%2d]Hello World!\n", count+1);

		++count;
	}

	printf("\n");
	{
	int i;
	for(i=0; i<10; i++)
	{
		printf("[%2d]Hello World!\n", i+1);

	}
	}
}

/*
2. 사용자로부터 숫자를 입력 받아, 그 수만큼 Hello World! 를 출력
*/
void fun2_2()
{
	int i, count;
	printf("반복 횟수 : ");		scanf("%d", &count);
	for(i=0; i<count; i++)
	{
		printf("[%2d]Hello World!\n", i+1);

	}
}

/*
3. 문자 'x' 를 입력할 때 까지 계속해서 문자 입력을 받아 화면에 출력
   단, 종료문자 'x'는 대소문자 구분 없다.)

   출력 예) 문자 입력 : a
            문자 입력 : b
            문자 입력 : X
*/
void fun2_3()
{
	char ch;

	while(1)
	{
		fflush(stdin);
		printf("문자 입력 : ");		ch = getchar();
		
		if( ch == 'x' || ch == 'X' )
			break;
	}
}

/*
4. 구구단 중 5단을 출력
*/
void fun2_4()
{
	int i;
	for(i=1; i<10; i++)
	{
		printf("%d * %d = %2d\n", 5, i, 5*i);
	}
}


/*
5. 출력하고자 하는 구구단 단수를 입력받아 
   해당 단수의 구구단을 출력
   반복적인 구구단 출력을 하고, 0을 입력하면 프로그램 종료
*/
void fun2_5()
{	
	int i, dan;
	while(1)
	{
		printf("출력하고자 하는 단수 : ");	scanf("%d", &dan);

		if( dan <0 || dan >9)			continue;
		if(dan == 0)					break;

		for(i=1; i<10; i++)
		{
			printf("%d * %d = %2d\n", dan, i, dan*i);
		}
	}
}

/*
6. 사용자가 입력하는 정수를 계속 더한다.
   만약 0을 입력하면 입력된 합의 결과 및 평균를 
   출력하고 프로그램 종료
   출력예) 정수 입력 : 1
           정수 입력 : 3
           정수 입력 : 0
           합계 = 4
           평균 = 2
*/
void fun2_6()
{
	int num;
	int count = 0;
	int sum   = 0;

	while(1)
	{
		printf("정수 입력 : ");		scanf("%d", &num);
		if(num == 0 )
			break;
		sum += num;
		++count;
	}
	printf("합계 = %d\n", sum);
	printf("평균 = %.2f\n", (float)sum/count);
}

/*
7. 1부터 100까지의 수 중 짝수의 합과 홀수의 합, 
   그리고 3의 배수의 합
*/
void fun2_7()
{
	int even = 0, odd = 0, mul = 0;
	int i;

	for( i=1; i<101; i++)
	{
		if( i%2 == 0)		even += i;
		else if(i%2 != 0)   odd  += i;
		
		if(i%3 == 0)	mul  += i;		//<======
	}
	printf("짝수의  합 :%d\n", even);
	printf("홀수의  합 :%d\n", odd);
	printf("3배수의 합 :%d\n", mul);
}

/*
8. 화씨 온도를 섭씨 온도로 환산
   단, 0도부터 100도까지 10도 단위  
   (식, C = 5/9 * (F-32) )
   출력 예) 화씨   0도는 섭씨 -17-8 이다.
            화씨  10도는 섭씨 -12.2 이다.
             ...
            화씨  100도는 섭씨 37.8 이다.
*/
void fun2_8()
{
	int i;
	float c;
	for(i = 0; i<101; i +=10)
	{
		c = (float)5/9 * ( i-32);
		printf("화씨 %3d도는 섭씨 %.2f 이다.\n",i, c);
	}
}

/*
9. 두 자리수의 정수를 계속하여 입력, 만약, 
   두 자리가 아닐 경우 종료 
   출력 예) 정수 : 12
            정수 : 99
            정수 : 9
*/
void fun2_9()
{
	int num;
	while(1)
	{
		printf("정수 : ");		scanf("%d", &num);
		if( num <10)
			break;
	}
}

/*

10. 사칙 연산 기호를 계속하여 입력, 
   만약 입력 오류일 경우 재입력, 
   'q' 를 입력하면 종료.

   출력 예)연산기호[+, -, *, /, q] : +
           연산기호[+, -, *, /, q] : -
           연산기호[+, -, *, /, q] : @
           key error !! try again!!
           연산기호[+, -, *, /, q] : *
           연산기호[+, -, *, /, q] : q
*/
void fun2_10()
{
	char op;

	while(1)
	{
		fflush(stdin);
		printf("연산기호[+, -, *, /, q] :");	scanf("%c", &op);

		if( op == 'q' || op == 'Q')		//<======== 순서.......
			break;

		if( op != '+' && op != '-' && op != '*' && op != '/')
		{
			printf("key error !! try again!!\n");
			continue;
		}			
	}
}


/*
11. 4칙 연산 프로그램을 다음의 조건에 따라 작성
   - 입력되는 수는 실수
   - 연산기호가 4칙 연산 이외의 기호이면 재 입력
   - 결과 출력 후  y를 누르면 재시작, n을 누르면 종료
   출력 예) 첫번째 수 : 3
            두번째 수 : 4
            연산 종류 : +
            결과     = 7.000000

             Continue<y/n>? y

	    첫번째 수 : 3
            두번째 수 : 4
            연산 종류 : &
            연산 종류 : /
            결과     = 0.750000

             Continue<y/n>? n
*/
void fun2_11()
{
	float f_num1, f_num2;
	char  op;

	while(1)
	{
		printf("첫번째 수 : ");		scanf("%f", &f_num1);
		printf("두번째 수 : ");		scanf("%f", &f_num2);
		fflush(stdin);
		
		while(1)
		{
			fflush(stdin);
			printf("연산 종류 : ");		scanf("%c", &op);
			if( op == '+' || op == '-' || op == '*' || op == '/')
				break;
		}

		switch(op)
		{
		case '+':	printf("결과     = %.6f\n", f_num1+ f_num2);	break;
		case '-':	printf("결과     = %.6f\n", f_num1- f_num2);	break;
		case '*':	printf("결과     = %.6f\n", f_num1* f_num2);	break;
		case '/':	printf("결과     = %.6f\n", f_num1/ f_num2);	break;
		}

		fflush(stdin);
		printf("Continue<y/n>? ");		scanf("%c", &op);
		if( op == 'y' || op == 'Y' )
			break;
	}	
}

/*
12. 10~100 까지의 양의 정수들 중에서 4의 배수의 개수와 
    그들의 합
*/
void fun2_12()
{
	int count = 0, sum = 0;
	int i;
	for(i=10; i<101; i++)
	{
		if( i % 4 == 0)
		{
			++count;
			sum += count;
		}
	}
	printf("4의 배수의 개수 : %d\n", count);
	printf("그들의 합       : %d\n", sum);
}


/*
13. n을 입력 받아 1부터 n까지의 합
*/
void fun2_13()
{
	int num, i, sum = 0;
	printf("정수 입력 : ");		scanf("%d", &num);
	for(i=0; i<=num; i++)
	{
		sum = sum + i;	
	}
	printf("1부터 %d까지의 합 = %d\n", num, sum);
}

/*
14. 5명 학생의 점수를 입력 한 후 학점으로 변경시키고, 
   합계와 평균을 출력
   (90~100:A, 80~89:B, 70~79:C, 60~69:D, other:F)
*/
void fun2_14()
{
	int num, sum = 0;
	char c_num;
	int i;
	for(i=0; i<5; i++)
	{
		printf("[%d]학생 점수 : ",i+1);
		scanf("%d", &num);

		sum += num;
		if(num>=90)		c_num = 'A';
		else if( num >= 80 && num <= 89) c_num = 'B';
		else if( num >= 70 && num <= 79) c_num = 'C';
		else if( num >= 60 && num <= 69) c_num = 'D';
		else							 c_num = 'F';	

		printf("==> [%d]학생 학점 : %c\n", i+1, c_num);
	}
	
	printf("합 계 = %d\n", sum);
	printf("평 균 = %.2f\n", (float)sum / 5);
}

/*
15. n개의 정수를 입력한 후 이들 중 최대값과 최소값, 
   합과 평균을 출력
   출력예) 정수의 개수 : 5
           1번째 정수 : 1
           2번째 정수 : 9
           3번째 정수 : 3
           4번째 정수 : 5
           5번째 정수 : 7
           최대값= 9, 합= 25, 평균= 5.0
*/
void fun2_15()
{
	int n, i, num;
	int sum=0, max, min;
	printf("정수의 개수 : ");		scanf("%d", &n);

	printf("1번째 정수 : ");	scanf("%d", &num);
	max = min = num;

	for(i=1; i<n; i++)
	{
		printf("%d번째 정수 : ", i+1);	scanf("%d", &num);
		if( num > max)			max = num;
		if( num < min)			min = num;
		sum += num;
	}
	printf("최대값= %d, 최소값= %d, 합= %d, 평균= %.1f\n", 
		max, min, sum , (float)sum/n);
}


/*
16. m에서 n까지 연속되는 수의 합을 아래 조건에 따라 출력
    - 끝 값이 시작값보다 작으면 서로 바꾸어 준다.
    - 끝 값과 시작값이 같으면 종료하고, 그렇지 않으면 계속 입력

    출력예) 시작 값은? 1
            끝   값은? 10
            1-10까지의 합은 55입니다.

            시작 값은? 10
            끝   값은?  7
            7-10까지의 합은 34입니다.
 
            시작 값은? 10
            끝   값은? 10
*/
void fun2_16()
{
	int start, end, sum = 0, i;
	int temp;

	while(1)
	{
		printf("시작 값은? ");  scanf("%d", &start);
		printf("끝   값은? ");	scanf("%d", &end);

		if( start == end) break;

		if(start > end)
		{
			temp	= start;
			start	= end;
			end		= temp;
		}

		for(i=start; i<=end; i++)   sum += i;
		printf("%d-%d까지의 합은 %d입니다.\n", start, end, sum);
	}
}






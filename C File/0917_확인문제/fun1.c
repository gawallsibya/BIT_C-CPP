//fun1.c
#include "std.h"
//[ 제어문 ]

/*
1. 양의 정수를 입력한 후 짝수면 "even number"
   홀수면 "odd number" 출력
   출력예) 정수 : 3
           3은 odd number
*/
void fun1_1()
{
	int num;
	printf("정수 : ");		scanf("%d", &num);
	if( num %2 == 0 )
		printf("%d은 even number\n", num);
	else
		printf("%d은 odd number\n", num);
}


/*
2. 0~24 수를 입력한 후 오전 혹은 오후 몇 시의   
   형태로 출력
   출력예) 시각[0~23] : 15
           오후 3시
*/
void fun1_2()
{
	int num;
	printf("시각[0~23] : ");	scanf("%d", &num);

	if( num > 12 )
		printf("오후 %d시\n", num-12);
	else
		printf("오전 %d시\n", num);
}

/*
3. 알파벳 한 글자를 입력한 후 소문자이면 대문자로, 
   대문자이면 소문자로 변환하여 출력
   출력예) 알파벳 : a
           변  환 : A
*/
void fun1_3()
{
	char ch;
	printf("알파벳 : ");		scanf("%c", &ch);
	if( ch >= 'A' && ch <= 'Z')
		printf("변 환 : %c\n", ch + ('a'-'A'));
	else
		printf("변 환 : %c\n", ch - ('a'-'A'));
}


/*
4. 한 문자를 입력한 후 숫자이면 "number", 
   알파벳 대문자이면 "capital letter"
   소문자이면 "small letter", 기호이면 "symbol" 출력
   (숫자 0-9:48~57, 대문자:65~90, 소문자:97~122)
   출력예)  문자 : 6
            number
*/
void fun1_4()
{
	char ch;
	printf("문자 : ");		scanf("%c", &ch);
	if(ch >= '0' && ch <= '9')
		printf("number\n");
	else if( ch >= 'A' && ch <= 'Z')
		printf("capital letter\n");
	else if( ch >= 'a' && ch <= 'z')
		printf("small letter\n");
	else
		printf("symbol\n");
}

/*
5. 출력예에 맞는 4칙연산을 완선 

   출력예)  My Calculator
            =========================
            1. 더하기
            2. 빼  기
            3. 곱하기 
            4. 나누기 
            선택하세요 [ 1 ] 
   
            첫번째 수 : 5
            두번째 수 : 7
            두 수의 합  = 12
*/
void fun1_5()
{
	int num1, num2, op;

	printf("My Calculator\n");
	printf("=========================\n");
	printf("1. 더하기\n");
	printf("2. 빼  기\n");
	printf("3. 곱하기\n");
	printf("4. 나누기\n");
	printf("선택하세요 [ ]\b\b");		scanf("%d", &op);

	printf("\n첫번째 수 : ");			scanf("%d", &num1);
	printf("두번째 수 : ");				scanf("%d", &num2);

	switch(op)
	{
	case 1:  printf("두 수의 합 = %d\n", num1 + num2); break;
	case 2:  printf("두 수의 차 = %d\n", num1 - num2); break;
	case 3:  printf("두 수의 곱 = %d\n", num1 * num2); break;
	case 4:  printf("두 수의 제 = %d\n", num1 / num2); break;
	}
}

/*
6. 3개의 수를 입력한 후 가장 큰 수를 출력
*/
void fun1_6()
{
	int num, max;
	printf("정수 입력 : ");		scanf("%d", &num);
	max = num;

	printf("정수 입력 : ");		scanf("%d", &num);
	if( max < num)
		max = num;

	printf("정수 입력 : ");		scanf("%d", &num);
	if( max < num)
		max = num;

	printf("가장 큰 수 %d\n", max);
}


/*
7. 다음 조건에 맞는 프로그램 작성
   출력예)
   당신의 학년은?[신입생:1, 재학생:2]____

    (2를 입력했을 경우)
    재학생 전용 창구로 가세요. (프로그램 종료)
   
   (1을 입력했을 경우)
    당신의 성별은?[남자1, 여자:2]_____
   (1을 입력했을 경우) 당신은 남자입니다.
   (2를 입력했을 경우) 당신은 여자입니다.
*/
void fun1_7()
{
	int num;

	printf("당신의 학년은?[신입생:1, 재학생:2] : ");	scanf("%d", &num);
	if( num == 1)
	{
		printf("당신의 성별은?[남자1, 여자:2] : ");		scanf("%d", &num);
		if( num == 1)
			printf("당신은 남자입니다.\n");
		else
			printf("당신은 여자입니다.\n");

	}
	else if(num == 2)
	{
		printf("재학생 전용 창구로 가세요.\n");
	}
}

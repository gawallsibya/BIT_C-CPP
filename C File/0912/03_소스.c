//스트림 
#include <stdio.h>
#include <conio.h>
/*
void main()
{
//	int num, num1;
//	scanf("%d%d", &num, &num1);		// enter, tab, space
//	printf("num :%d num1 : %d\n", num, num1);

	char name[20];
	scanf("%s", name);

	printf("입력된 이름 : %s\n", name);
}
*/
// 이름, 나이, 성별

void main()
{
	char name[20];
	int  age;
	char sex;

	printf("이름 : ");		scanf("%s", name);	// gets(name);	
	fflush(stdin);
	printf("나이 : ");		scanf("%d", &age);
	fflush(stdin);
	printf("성별(M/F : ");	scanf("%c", &sex);	// sex = getchar();

	printf("이름 : %s\n", name);
	printf("나이 : %d\n", age);
	printf("성별 : %c\n", sex);
}



/*
void main()
{
	char str[10];
	gets(str);

	puts(str);
}
*/

/*
void main()
{
	char ch;
	ch = getch();

	printf("입력 값 : %c\n", ch);
}
*/

/*
int main(void)
{
    char ch;

    while ((ch = getchar()) != EOF)	// ctrl+Z
	{
        putchar(ch);
	}

    return 0;
}
*/


/*
void main()
{
	char ch, ch1;
	ch	= getchar();

	fflush(stdin);
	ch1 = getchar();

	printf("CH 저장값 : ");	putchar(ch);		printf("\n");
	printf("CH1 저장값: ");	putchar(ch1);		printf("\n");
}
*/

/*
//printf(const char*, ...);				// const char* ==> 상수 문자열 
//fprintf(FILE*, const char*, ...);		// ... ==> 가변형 인자 

void main()
{
	int num;

	printf("데이터 전송\n");		// 'A'(문자)  "A"(문자열)
	fprintf(stdout, "데이터 전송\n");

	scanf("%d", &num);				// num = 10
	fscanf(stdin, "%d", &num);		// num = 20
	printf("입력된 숫자 : %d\n", num);
}
*/
#include <stdio.h>
#include <string.h>		// 문자열 전용 함수 

// strcpy, strcmp, strlen, strcat

void main()
{
	char name[50] = "홍길동";
	strcat(name, "님이 로그인하셨습니다.");

	printf("%s\n", name);
}

/*
void main()
{
	char name[20] = "홍 길 동";
	char name1[20] = "hong kil dong";

	printf("%d : %d\n", sizeof(name), strlen(name));	// 20: 8
	printf("%d : %d\n", sizeof(name1), strlen(name1));	// 20: 13
}
*/

/*
void main()
{
	char pw[20], pw1[20];
	printf("비밀번호 저장 : ");		 gets(pw);

	printf("비밀번호 입력 : ");		 gets(pw1);

	if( !strcmp(pw ,pw1) )		// 1(pw가 클떄)  0(일치할 경우) -1(pw1이 클때)
	{
		printf("성공\n");
	}
	else
	{
		printf("실패\n");
	}
}
*/

//char* strcpy(char*, const char*);	
/*
void main()
{
	int num			= 10;

	char name[20]	= "홍길동";

	num				= 20;
//	name			= "김길동";
	strcpy(name, "김길동");		printf("%s\n", name);
}
*/

/*
// 문자열 배열 & char 포인터
void main()
{
	char arr[] = "TEST";		// arr : 5byte
	char *p    = "TEST";		//  p  : 4byte

	arr[1]		= 'e';		printf("%s\n", arr);
	//p[1]		= 'e';		printf("%s\n", p);

//	arr			= "BBB";		// arr = 'b', 'b', 'b', '\0'
	p			= "BBB";	printf("%s\n", p);
}
*/


/*
#define STRING "TEST"

// 문자열 상수
void main()
{
	printf(STRING);		// printf("TEST");
}
*/

// 문자열 : size??? 가변적 
/*
void main()
{
	// 문자 배열 
	char arr1[] = {'a', 'b', 'c'};			// 3byte : a b c

	// 문자열 
	char arr2[] = {'a', 'b', 'c', '\0'};	// 4byte : a b c \0
	char arr3[] = "abc";					// 4byte : a b c \0
	char arr4[] = { "abc" };				// 4byte : a b c \0

	printf("%s\n", arr2+1);		// bc
}
*/
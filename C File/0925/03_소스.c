#include <stdio.h>
#include <string.h>		// ���ڿ� ���� �Լ� 

// strcpy, strcmp, strlen, strcat

void main()
{
	char name[50] = "ȫ�浿";
	strcat(name, "���� �α����ϼ̽��ϴ�.");

	printf("%s\n", name);
}

/*
void main()
{
	char name[20] = "ȫ �� ��";
	char name1[20] = "hong kil dong";

	printf("%d : %d\n", sizeof(name), strlen(name));	// 20: 8
	printf("%d : %d\n", sizeof(name1), strlen(name1));	// 20: 13
}
*/

/*
void main()
{
	char pw[20], pw1[20];
	printf("��й�ȣ ���� : ");		 gets(pw);

	printf("��й�ȣ �Է� : ");		 gets(pw1);

	if( !strcmp(pw ,pw1) )		// 1(pw�� Ŭ��)  0(��ġ�� ���) -1(pw1�� Ŭ��)
	{
		printf("����\n");
	}
	else
	{
		printf("����\n");
	}
}
*/

//char* strcpy(char*, const char*);	
/*
void main()
{
	int num			= 10;

	char name[20]	= "ȫ�浿";

	num				= 20;
//	name			= "��浿";
	strcpy(name, "��浿");		printf("%s\n", name);
}
*/

/*
// ���ڿ� �迭 & char ������
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

// ���ڿ� ���
void main()
{
	printf(STRING);		// printf("TEST");
}
*/

// ���ڿ� : size??? ������ 
/*
void main()
{
	// ���� �迭 
	char arr1[] = {'a', 'b', 'c'};			// 3byte : a b c

	// ���ڿ� 
	char arr2[] = {'a', 'b', 'c', '\0'};	// 4byte : a b c \0
	char arr3[] = "abc";					// 4byte : a b c \0
	char arr4[] = { "abc" };				// 4byte : a b c \0

	printf("%s\n", arr2+1);		// bc
}
*/
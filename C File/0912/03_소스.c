//��Ʈ�� 
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

	printf("�Էµ� �̸� : %s\n", name);
}
*/
// �̸�, ����, ����

void main()
{
	char name[20];
	int  age;
	char sex;

	printf("�̸� : ");		scanf("%s", name);	// gets(name);	
	fflush(stdin);
	printf("���� : ");		scanf("%d", &age);
	fflush(stdin);
	printf("����(M/F : ");	scanf("%c", &sex);	// sex = getchar();

	printf("�̸� : %s\n", name);
	printf("���� : %d\n", age);
	printf("���� : %c\n", sex);
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

	printf("�Է� �� : %c\n", ch);
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

	printf("CH ���尪 : ");	putchar(ch);		printf("\n");
	printf("CH1 ���尪: ");	putchar(ch1);		printf("\n");
}
*/

/*
//printf(const char*, ...);				// const char* ==> ��� ���ڿ� 
//fprintf(FILE*, const char*, ...);		// ... ==> ������ ���� 

void main()
{
	int num;

	printf("������ ����\n");		// 'A'(����)  "A"(���ڿ�)
	fprintf(stdout, "������ ����\n");

	scanf("%d", &num);				// num = 10
	fscanf(stdin, "%d", &num);		// num = 20
	printf("�Էµ� ���� : %d\n", num);
}
*/
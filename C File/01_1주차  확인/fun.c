//fun.c
#include "std.h"

/*
1. �ڽ��� �̸��� gets() �Լ��� �Է¹޾�
   printf() �Լ��� ���
*/
void fun_1()
{
	char name[20];
	printf("�Է� : ");	gets(name);

	printf("�̸� : %s\n", name);
}


/*
2. ������ ����� �Է� �� ��� '=' ���
   ������(10����, 8����, 16������ ���)
   �Ǽ���(�Ҽ��� 2° �ڸ����� ���) 
   1���� ����(���� �� 10������ ���� ���)
   ���� ������ �ּҰ� ���(16������ ���)
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
3. �Ҽ��� 3�ڸ� �Ǽ��� �Է� �޾� 
   ù°, ��°, ��° �ڸ����� ���� �ݿø��Ͽ� ���
   ��) �Ҽ��� 3�ڸ� �Ǽ� �Է� : (12.345)
       ��� : 12, 12.3, 12.35
*/
void fun_3()
{
	float	f;
	printf("�Ҽ��� 3�ڸ� �Ǽ� �Է� : ");	scanf("%f", &f);
	printf("%.f : %.1f : %.2f\n", f, f,f);
}


/*
4. ȭ�� �µ��� �Է��� �� �����µ��� ���(��, �Ҽ� ù° �ڸ�����)
   ����) �����µ� = 5 / 9 * (ȭ���µ� - 32 )

*/
void fun_4()
{
	int   c;
	float f;
	printf("ȭ�� �µ� : ");		scanf("%d", &c);

	f	= (float)5 / 9 * ( c - 32 );
	printf("���� �µ� : %.1f��\n", f);
}


/*
5. �� ���� ������ �Է��� �� �հ�� ����� ���
   (��, ����� �Ҽ� ��° �ڸ����� �ݿø�)
*/
void fun_5()
{
	int num;
	int sum = 0;
	printf("���� �Է� : ");		scanf("%d", &num);
	sum		+= num;

	printf("���� �Է� : ");		scanf("%d", &num);
	sum		+= num;

	printf("���� �Է� : ");		scanf("%d", &num);
	sum		+= num;

	printf("�հ� : %d\n", sum);
	printf("��� : %.2f\n", (float)sum/3);
}


/*
6. �� ���� �����ڸ� �Է��� �� ���ĺ����� �� 
   ��° �������� ��� 
   ��¿�) ������ �Է� : C
           ��� : C�� 3��° ���ĺ��̴�.

*/
void fun_6()
{
	char ch;
	int  idx;
	printf("������ �Է� : ");	scanf("%c", &ch);

	idx	= (ch>=97) ? ch-'a'+1  : ch -'A'+1;
	printf("��� : %c�� %d��° ���ĺ��̴�.\n", ch, idx);
}

/*
7. �� ���� ������ �� ���� ������ �Է��� �� ������
   ���� ��ȯ�Ͽ� ���
   ��¿�) �� ����  : 1, 2
           ��ȯ��� : 2, 1
*/
void fun_7()
{
	int num1 = 10, num2 = 20, temp;

	printf("�� ����  : %d, %d\n", num1, num2);

	temp = num1;
	num1 = num2;
	num2 = temp;

	printf("��ȯ��� : %d, %d\n", num1, num2);
}

/*
9. �� ���� �Է� �޾� ���� ����
   ��¿�) ���� �Է� : 3
           ���� �Է� : 2
           �� ������ �� : 5
*/
void fun_9()
{
	int num, num1;

	printf("���� �Է� : ");	scanf("%d", &num);
	printf("���� �Է� : "); scanf("%d", &num1);
	printf("�� ������ �� : %d\n", num + num1);
}


/*
10. ���� �ϳ��� �Է¹޾� ���ڷ� ��ȯ�Ͽ� ���
     ��¿�) �����Է� : 3
             ��    �� : 3
*/
void fun_10()
{
	char ch;
	int  num;
	printf("�����Է� : ");	scanf("%c", &ch);

	num	= ch - '0';
	printf("��    �� : %d\n", num);
}

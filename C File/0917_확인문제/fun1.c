//fun1.c
#include "std.h"
//[ ��� ]

/*
1. ���� ������ �Է��� �� ¦���� "even number"
   Ȧ���� "odd number" ���
   ��¿�) ���� : 3
           3�� odd number
*/
void fun1_1()
{
	int num;
	printf("���� : ");		scanf("%d", &num);
	if( num %2 == 0 )
		printf("%d�� even number\n", num);
	else
		printf("%d�� odd number\n", num);
}


/*
2. 0~24 ���� �Է��� �� ���� Ȥ�� ���� �� ����   
   ���·� ���
   ��¿�) �ð�[0~23] : 15
           ���� 3��
*/
void fun1_2()
{
	int num;
	printf("�ð�[0~23] : ");	scanf("%d", &num);

	if( num > 12 )
		printf("���� %d��\n", num-12);
	else
		printf("���� %d��\n", num);
}

/*
3. ���ĺ� �� ���ڸ� �Է��� �� �ҹ����̸� �빮�ڷ�, 
   �빮���̸� �ҹ��ڷ� ��ȯ�Ͽ� ���
   ��¿�) ���ĺ� : a
           ��  ȯ : A
*/
void fun1_3()
{
	char ch;
	printf("���ĺ� : ");		scanf("%c", &ch);
	if( ch >= 'A' && ch <= 'Z')
		printf("�� ȯ : %c\n", ch + ('a'-'A'));
	else
		printf("�� ȯ : %c\n", ch - ('a'-'A'));
}


/*
4. �� ���ڸ� �Է��� �� �����̸� "number", 
   ���ĺ� �빮���̸� "capital letter"
   �ҹ����̸� "small letter", ��ȣ�̸� "symbol" ���
   (���� 0-9:48~57, �빮��:65~90, �ҹ���:97~122)
   ��¿�)  ���� : 6
            number
*/
void fun1_4()
{
	char ch;
	printf("���� : ");		scanf("%c", &ch);
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
5. ��¿��� �´� 4Ģ������ �ϼ� 

   ��¿�)  My Calculator
            =========================
            1. ���ϱ�
            2. ��  ��
            3. ���ϱ� 
            4. ������ 
            �����ϼ��� [ 1 ] 
   
            ù��° �� : 5
            �ι�° �� : 7
            �� ���� ��  = 12
*/
void fun1_5()
{
	int num1, num2, op;

	printf("My Calculator\n");
	printf("=========================\n");
	printf("1. ���ϱ�\n");
	printf("2. ��  ��\n");
	printf("3. ���ϱ�\n");
	printf("4. ������\n");
	printf("�����ϼ��� [ ]\b\b");		scanf("%d", &op);

	printf("\nù��° �� : ");			scanf("%d", &num1);
	printf("�ι�° �� : ");				scanf("%d", &num2);

	switch(op)
	{
	case 1:  printf("�� ���� �� = %d\n", num1 + num2); break;
	case 2:  printf("�� ���� �� = %d\n", num1 - num2); break;
	case 3:  printf("�� ���� �� = %d\n", num1 * num2); break;
	case 4:  printf("�� ���� �� = %d\n", num1 / num2); break;
	}
}

/*
6. 3���� ���� �Է��� �� ���� ū ���� ���
*/
void fun1_6()
{
	int num, max;
	printf("���� �Է� : ");		scanf("%d", &num);
	max = num;

	printf("���� �Է� : ");		scanf("%d", &num);
	if( max < num)
		max = num;

	printf("���� �Է� : ");		scanf("%d", &num);
	if( max < num)
		max = num;

	printf("���� ū �� %d\n", max);
}


/*
7. ���� ���ǿ� �´� ���α׷� �ۼ�
   ��¿�)
   ����� �г���?[���Ի�:1, ���л�:2]____

    (2�� �Է����� ���)
    ���л� ���� â���� ������. (���α׷� ����)
   
   (1�� �Է����� ���)
    ����� ������?[����1, ����:2]_____
   (1�� �Է����� ���) ����� �����Դϴ�.
   (2�� �Է����� ���) ����� �����Դϴ�.
*/
void fun1_7()
{
	int num;

	printf("����� �г���?[���Ի�:1, ���л�:2] : ");	scanf("%d", &num);
	if( num == 1)
	{
		printf("����� ������?[����1, ����:2] : ");		scanf("%d", &num);
		if( num == 1)
			printf("����� �����Դϴ�.\n");
		else
			printf("����� �����Դϴ�.\n");

	}
	else if(num == 2)
	{
		printf("���л� ���� â���� ������.\n");
	}
}

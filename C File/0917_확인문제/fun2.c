//fun2.c
#include "std.h"


/*
1. while ���� for���� �̿��Ͽ� Hello World!�� ���� 10���� ���
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
2. ����ڷκ��� ���ڸ� �Է� �޾�, �� ����ŭ Hello World! �� ���
*/
void fun2_2()
{
	int i, count;
	printf("�ݺ� Ƚ�� : ");		scanf("%d", &count);
	for(i=0; i<count; i++)
	{
		printf("[%2d]Hello World!\n", i+1);

	}
}

/*
3. ���� 'x' �� �Է��� �� ���� ����ؼ� ���� �Է��� �޾� ȭ�鿡 ���
   ��, ���Ṯ�� 'x'�� ��ҹ��� ���� ����.)

   ��� ��) ���� �Է� : a
            ���� �Է� : b
            ���� �Է� : X
*/
void fun2_3()
{
	char ch;

	while(1)
	{
		fflush(stdin);
		printf("���� �Է� : ");		ch = getchar();
		
		if( ch == 'x' || ch == 'X' )
			break;
	}
}

/*
4. ������ �� 5���� ���
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
5. ����ϰ��� �ϴ� ������ �ܼ��� �Է¹޾� 
   �ش� �ܼ��� �������� ���
   �ݺ����� ������ ����� �ϰ�, 0�� �Է��ϸ� ���α׷� ����
*/
void fun2_5()
{	
	int i, dan;
	while(1)
	{
		printf("����ϰ��� �ϴ� �ܼ� : ");	scanf("%d", &dan);

		if( dan <0 || dan >9)			continue;
		if(dan == 0)					break;

		for(i=1; i<10; i++)
		{
			printf("%d * %d = %2d\n", dan, i, dan*i);
		}
	}
}

/*
6. ����ڰ� �Է��ϴ� ������ ��� ���Ѵ�.
   ���� 0�� �Է��ϸ� �Էµ� ���� ��� �� ��ո� 
   ����ϰ� ���α׷� ����
   ��¿�) ���� �Է� : 1
           ���� �Է� : 3
           ���� �Է� : 0
           �հ� = 4
           ��� = 2
*/
void fun2_6()
{
	int num;
	int count = 0;
	int sum   = 0;

	while(1)
	{
		printf("���� �Է� : ");		scanf("%d", &num);
		if(num == 0 )
			break;
		sum += num;
		++count;
	}
	printf("�հ� = %d\n", sum);
	printf("��� = %.2f\n", (float)sum/count);
}

/*
7. 1���� 100������ �� �� ¦���� �հ� Ȧ���� ��, 
   �׸��� 3�� ����� ��
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
	printf("¦����  �� :%d\n", even);
	printf("Ȧ����  �� :%d\n", odd);
	printf("3����� �� :%d\n", mul);
}

/*
8. ȭ�� �µ��� ���� �µ��� ȯ��
   ��, 0������ 100������ 10�� ����  
   (��, C = 5/9 * (F-32) )
   ��� ��) ȭ��   0���� ���� -17-8 �̴�.
            ȭ��  10���� ���� -12.2 �̴�.
             ...
            ȭ��  100���� ���� 37.8 �̴�.
*/
void fun2_8()
{
	int i;
	float c;
	for(i = 0; i<101; i +=10)
	{
		c = (float)5/9 * ( i-32);
		printf("ȭ�� %3d���� ���� %.2f �̴�.\n",i, c);
	}
}

/*
9. �� �ڸ����� ������ ����Ͽ� �Է�, ����, 
   �� �ڸ��� �ƴ� ��� ���� 
   ��� ��) ���� : 12
            ���� : 99
            ���� : 9
*/
void fun2_9()
{
	int num;
	while(1)
	{
		printf("���� : ");		scanf("%d", &num);
		if( num <10)
			break;
	}
}

/*

10. ��Ģ ���� ��ȣ�� ����Ͽ� �Է�, 
   ���� �Է� ������ ��� ���Է�, 
   'q' �� �Է��ϸ� ����.

   ��� ��)�����ȣ[+, -, *, /, q] : +
           �����ȣ[+, -, *, /, q] : -
           �����ȣ[+, -, *, /, q] : @
           key error !! try again!!
           �����ȣ[+, -, *, /, q] : *
           �����ȣ[+, -, *, /, q] : q
*/
void fun2_10()
{
	char op;

	while(1)
	{
		fflush(stdin);
		printf("�����ȣ[+, -, *, /, q] :");	scanf("%c", &op);

		if( op == 'q' || op == 'Q')		//<======== ����.......
			break;

		if( op != '+' && op != '-' && op != '*' && op != '/')
		{
			printf("key error !! try again!!\n");
			continue;
		}			
	}
}


/*
11. 4Ģ ���� ���α׷��� ������ ���ǿ� ���� �ۼ�
   - �ԷµǴ� ���� �Ǽ�
   - �����ȣ�� 4Ģ ���� �̿��� ��ȣ�̸� �� �Է�
   - ��� ��� ��  y�� ������ �����, n�� ������ ����
   ��� ��) ù��° �� : 3
            �ι�° �� : 4
            ���� ���� : +
            ���     = 7.000000

             Continue<y/n>? y

	    ù��° �� : 3
            �ι�° �� : 4
            ���� ���� : &
            ���� ���� : /
            ���     = 0.750000

             Continue<y/n>? n
*/
void fun2_11()
{
	float f_num1, f_num2;
	char  op;

	while(1)
	{
		printf("ù��° �� : ");		scanf("%f", &f_num1);
		printf("�ι�° �� : ");		scanf("%f", &f_num2);
		fflush(stdin);
		
		while(1)
		{
			fflush(stdin);
			printf("���� ���� : ");		scanf("%c", &op);
			if( op == '+' || op == '-' || op == '*' || op == '/')
				break;
		}

		switch(op)
		{
		case '+':	printf("���     = %.6f\n", f_num1+ f_num2);	break;
		case '-':	printf("���     = %.6f\n", f_num1- f_num2);	break;
		case '*':	printf("���     = %.6f\n", f_num1* f_num2);	break;
		case '/':	printf("���     = %.6f\n", f_num1/ f_num2);	break;
		}

		fflush(stdin);
		printf("Continue<y/n>? ");		scanf("%c", &op);
		if( op == 'y' || op == 'Y' )
			break;
	}	
}

/*
12. 10~100 ������ ���� ������ �߿��� 4�� ����� ������ 
    �׵��� ��
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
	printf("4�� ����� ���� : %d\n", count);
	printf("�׵��� ��       : %d\n", sum);
}


/*
13. n�� �Է� �޾� 1���� n������ ��
*/
void fun2_13()
{
	int num, i, sum = 0;
	printf("���� �Է� : ");		scanf("%d", &num);
	for(i=0; i<=num; i++)
	{
		sum = sum + i;	
	}
	printf("1���� %d������ �� = %d\n", num, sum);
}

/*
14. 5�� �л��� ������ �Է� �� �� �������� �����Ű��, 
   �հ�� ����� ���
   (90~100:A, 80~89:B, 70~79:C, 60~69:D, other:F)
*/
void fun2_14()
{
	int num, sum = 0;
	char c_num;
	int i;
	for(i=0; i<5; i++)
	{
		printf("[%d]�л� ���� : ",i+1);
		scanf("%d", &num);

		sum += num;
		if(num>=90)		c_num = 'A';
		else if( num >= 80 && num <= 89) c_num = 'B';
		else if( num >= 70 && num <= 79) c_num = 'C';
		else if( num >= 60 && num <= 69) c_num = 'D';
		else							 c_num = 'F';	

		printf("==> [%d]�л� ���� : %c\n", i+1, c_num);
	}
	
	printf("�� �� = %d\n", sum);
	printf("�� �� = %.2f\n", (float)sum / 5);
}

/*
15. n���� ������ �Է��� �� �̵� �� �ִ밪�� �ּҰ�, 
   �հ� ����� ���
   ��¿�) ������ ���� : 5
           1��° ���� : 1
           2��° ���� : 9
           3��° ���� : 3
           4��° ���� : 5
           5��° ���� : 7
           �ִ밪= 9, ��= 25, ���= 5.0
*/
void fun2_15()
{
	int n, i, num;
	int sum=0, max, min;
	printf("������ ���� : ");		scanf("%d", &n);

	printf("1��° ���� : ");	scanf("%d", &num);
	max = min = num;

	for(i=1; i<n; i++)
	{
		printf("%d��° ���� : ", i+1);	scanf("%d", &num);
		if( num > max)			max = num;
		if( num < min)			min = num;
		sum += num;
	}
	printf("�ִ밪= %d, �ּҰ�= %d, ��= %d, ���= %.1f\n", 
		max, min, sum , (float)sum/n);
}


/*
16. m���� n���� ���ӵǴ� ���� ���� �Ʒ� ���ǿ� ���� ���
    - �� ���� ���۰����� ������ ���� �ٲپ� �ش�.
    - �� ���� ���۰��� ������ �����ϰ�, �׷��� ������ ��� �Է�

    ��¿�) ���� ����? 1
            ��   ����? 10
            1-10������ ���� 55�Դϴ�.

            ���� ����? 10
            ��   ����?  7
            7-10������ ���� 34�Դϴ�.
 
            ���� ����? 10
            ��   ����? 10
*/
void fun2_16()
{
	int start, end, sum = 0, i;
	int temp;

	while(1)
	{
		printf("���� ����? ");  scanf("%d", &start);
		printf("��   ����? ");	scanf("%d", &end);

		if( start == end) break;

		if(start > end)
		{
			temp	= start;
			start	= end;
			end		= temp;
		}

		for(i=start; i<=end; i++)   sum += i;
		printf("%d-%d������ ���� %d�Դϴ�.\n", start, end, sum);
	}
}






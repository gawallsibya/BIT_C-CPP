#include <stdio.h>

// ���
void main()
{
	int			num		= 10;	// ���� 
	const int	NUM1	= 10;	// ��� 

//	const int NUM2		;		 // error ����� �ݵ�� �ʱ�ȭ 


	num		= 20;

//	NUM1	= 20;		// error.
}

/*
void main()
{
	int num1 = 10;
	int num2 = 3;
	float result;

	result	 = (float)num1 / num2;		// �Ǽ� ���� ==> �Ǽ� 
	printf("%f\n", result);
}
*/

/*
void main()
{
	int		i_num	= 10;
	float	f_num;

	f_num	= (float)i_num;
	printf("%f\n", f_num);
}
*/

/*
void main()
{
	int		i_num	= 2147483647;
	short	s_num	= 10;
	
	i_num		= s_num;	// int   <== short(�Ͻ��� ����ȯ ��)
	s_num		= i_num;	// short <== int(��û�� �����Ϸ��� ��)
	printf("%d\n", s_num);
}
*/


/*
void main()
{
	float f = 10.1f;
	while(1)
	{
		if( f == 11.0)
			break;
		f = f + 0.1f;
		printf("%f\n", f);
		getch();
	}

	float f;
	double d;

	f		= 10.1f;
	d		= 10.1;
	printf("%d : %d\n", sizeof(f), sizeof(d));

}
	*/
/*
void main()
{
	char ch, ch1;
	ch		= 'A';		// Ÿ�� , ���� 
	ch1		= 65;

	printf("%c : %c\n", ch, ch1);
	printf("%d : %d\n", ch, ch1);
}*/

/*
void main()
{
	int num1;		// int ������ �⺻ type
	printf("%d : %d\n", &num1, num1);

	num1	= 10;
	printf("%d : %d\n", &num1, num1);
}
*/

/*
void main()
{
	int		num1	= 2147483648;
	short	num2;
	long	num3;

	unsigned int num4;

	printf("%d\n", num1);


	printf("%d : %d : %d\n", sizeof(num1), sizeof(num2), sizeof(num3));
	printf("%d : %d : %d\n", sizeof(int), sizeof(short), sizeof(long));
	printf("%d : %d\n", sizeof(num4), sizeof(unsigned int));
}
*/
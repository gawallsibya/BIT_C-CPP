/*
1. �Ʒ��� �ش��ϴ� �Լ��� ����θ� �ۼ��Ͻÿ�.
?1.1 �Լ� sum2()�� �� ���� int �� ���ڸ� ����ϰ� ��ȯ ���� int ���� ��Ÿ���� �Լ�
*/
int sum2(int, int);

//1.2 �Լ� int2double()�� �� ���� ���� ���ڸ� ����ϰ�, double ������ �ڷᰪ�� ��ȯ 
double int2double(int);

//?1.3 �Լ� print()�� ���ڵ� ���� ��ȯ ���� ����.
void print();

//  1.4 �Լ� sum2()�� �� ���� int �� ���ڸ� ����ϰ� ��ȯ ���� int �� 
int sum2(int, int);
  
//  1.5 �Լ� sum3()�� �� ���� int �� ���ڸ� ����ϰ� ��ȯ ���� int �� 
int sum3(int, int, int);


//6. �Ʒ� ������ �ش��ϴ� �Լ��� �����Ͻÿ�.
int IncrementNumber(int n);

void main()
{
	int num = 10;

	num = IncrementNumber(num);  // ���޹��� ���� 1���� ����� �����ϴ� �Լ�
	
	printf("%d\n", num);
}

int IncrementNumber(int n)
{
	return n+1;
}


//7. 
int Is_Number(char ch);

void main()
{
    char ch = '9'
    if( Is_Number(  ch ) )	    // ���޹��� ���� �����̸� 1, �����̸� 0�� �����ϴ� �Լ�
        printf("����\n");
    else 
        printf("����\n");
}

int Is_Number(char ch)
{
	if( '0' >= ch  && ch <= '0')
		return 1;
	else
		return 0;
}

//8. 

int MyAdd(int n1, int n2);

void main( )
{
   int num1 = 10, num2 = 20;
   int result;
   result = MyAdd( num1, num2 );   // ���޹��� ���� ���� �����ϴ� �Լ�
   printf("%d", result);
}
int MyAdd(int n1, int n2)
{
	return n1 + n2;
}


//9. �־��� �Լ��� ����Ͽ� number�� ���� ����Ͻÿ�.

void PrintNumber(int num )
{
    printf("%d\n", num);
}

void main()
{
	int number = 100;
	PrintNumber(number);
}

//10. ����ڰ� ������ ������ ���� �����Ͽ� �����ϴ� �Լ��� �����ϰ� ����Ͻÿ�.

int MulNum(int n);

void main()
{
	int num  = 10;
	num		 = MulNum(num);
}

int MulNum(int n)
{
	return n*n;
}
   





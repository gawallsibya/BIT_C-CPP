//exam.c

void foo(int (*ar)[3], int a)			//arr[0][0]  = 10 (arr, 10)
{
	ar[0][0] = a;
}

void woo(int (*ar)[3], int a)			//pArr[0][1] = 20 (arr+1. 20)
{
	*(*(ar-1)+1)= a;
}

void goo(int *ar, int a)			//pArr[0][2] = 30 (arr[1], 30)
{
	ar[-1] = a;
}

void hoo(int *ar, int a)			//pArr[1][0] = 40 (&arr[1][1], 40)
{
	ar[-1] = a;
}

void eoo(int *ar, int a)			//pArr[1][1] = 50 ((*arr)+1, 50)
{
	ar[+3] = a;
}

void aoo(int *ar, int a)			//pArr[1][2] = 60 (arr[0], 60)
{
	*(ar+5) = a;
}
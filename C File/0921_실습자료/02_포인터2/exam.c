//exam.c
int	foo(int *rr[], int *ar)		//pArr[0] = &arr[0]
{
	rr[0] = &ar[0];
}

int	woo(int *rr[], int *ar)		//pArr[1] = &arr[1] [woo(&pArr[1] 2��°, arr 1��)]
{
	rr[0] = &ar[+1];
}

int	goo(int *rr[], int *ar)		//pArr[2] = &arr[2] (pArr+2 3����, arr+4 5��°)
{
	rr[0] = &ar[-2];
}

int	hoo(int *rr[], int *ar)		//pArr[3] = &arr[3] (pArr 0, arr+2 3��)
{
	rr[3] = &ar[+1];
}

int	eoo(int *rr[], int *ar)		//pArr[4] = &arr[4] (&pArr[2] 2 , arr 0)
{
	rr[+2] = &ar[+4];
}


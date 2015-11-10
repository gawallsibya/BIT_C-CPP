void foo(int ar[])
{
	ar[0] = 10;
}

void woo(int ar[])
{
	ar[-1] = 20;
}

void goo(int ar[])
{
	ar[-1] = 30;
}

void hoo(int *ar)
{
	ar[-2] = 40;
}

void ooo(int ar[], int b)
{
	ar[2] = b;
}
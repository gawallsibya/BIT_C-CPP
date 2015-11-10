//exam.h

void foo(int (*ar)[3], int a);				//arr[0][0]  = 10
void woo(int (*ar)[3], int a);				//pArr[0][1] = 20
void goo(int *ar, int a);				//pArr[0][2] = 30
void hoo(int *ar, int a);				//pArr[1][0] = 40
void eoo(int *ar, int a);				//pArr[1][1] = 50
void aoo(int *ar, int a);				//pArr[1][2] = 60
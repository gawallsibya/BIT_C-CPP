#include <stdio.h>
#include <string.h>

#define MAXLEN 21	//최대 문자열 길이 + 1

struct phone 
{ 
	char name[MAXLEN];
	int  age;
};

/*
void main()
{
	struct phone myphone1 = {  "홍길동",  10};

	struct phone *pPhone;		// 4byte
	pPhone	= &myphone1;

	(*pPhone).age = 20;
	pPhone->age   = 30;
	printf("%s : %d\n", (*pPhone).name, (*pPhone).age);
}	
*/


void foo( struct phone* pm, struct phone* pm1);
void woo( char * name, int* age);
int main(void)
{
    struct phone myphone1[5];
	struct phone myp;

	foo( myphone1, &myp);

//	woo( myphone1[2].name, &myphone1[2].age);

//    printf("%s : %d\n", myphone1[0].name, myphone1[0].age);
 //   printf("%s : %d\n", myphone1[1].name, myphone1[1].age);
 //   printf("%s : %d\n", myphone1[2].name, myphone1[2].age);
    return 0;
}
void woo( char * name, int *age)
{
	strcpy(name, "홍길동");
	*age	= 30;
}

void foo( struct phone* pm,  struct phone* pm1)
{	
	pm1->age = 10;

	pm1[0].age = 20;

	/*
	pm->age    = 10;
	pm[0].age  = 10;			// 원본 접근 코드

	strcpy(pm[0].name, "김길동");

	(pm+1)->age = 20;
	pm[1].age  = 20;
	strcpy(pm[1].name, "고길동");
	*/
}
#include <stdio.h>
#include <string.h>

#define MAXLEN 21	//최대 문자열 길이 + 1

struct phone 
{ 
	char name[MAXLEN];
	int  age;
};

void foo( struct phone* pm);
void woo( char * name, int* age);
int main(void)
{
    struct phone myphone1[5];
	
	foo( myphone1);

	woo( myphone1[2].name, &myphone1[2].age);

    printf("%s : %d\n", myphone1[0].name, myphone1[0].age);
    printf("%s : %d\n", myphone1[1].name, myphone1[1].age);
    printf("%s : %d\n", myphone1[2].name, myphone1[2].age);
    return 0;
}
void woo( char * name, int *age)
{
	strcpy(name, "홍길동");
	*age	= 30;
}

void foo( struct phone* pm)
{
	pm[0].age  = 10;
	strcpy(pm[0].name, "김길동");

	pm[1].age  = 20;
	strcpy(pm[1].name, "고길동");

}


/*
void foo( struct phone m);
void woo( char * name, int* age);
int main(void)
{
    struct phone myphone1 = {  "홍길동",  10};
	
	foo( myphone1);
	woo( myphone1.name, &myphone1.age);

    printf("%s : %d\n", myphone1.name, myphone1.age);
    return 0;
}
void woo( char * name, int *age)
{
	strcpy(name, "김길동");
	*age	= 20;
}
void foo( struct phone m)
{

}
*/
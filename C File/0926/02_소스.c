#include <stdio.h>
#include <string.h>

#define MAXLEN 21	//�ִ� ���ڿ� ���� + 1

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
	strcpy(name, "ȫ�浿");
	*age	= 30;
}

void foo( struct phone* pm)
{
	pm[0].age  = 10;
	strcpy(pm[0].name, "��浿");

	pm[1].age  = 20;
	strcpy(pm[1].name, "��浿");

}


/*
void foo( struct phone m);
void woo( char * name, int* age);
int main(void)
{
    struct phone myphone1 = {  "ȫ�浿",  10};
	
	foo( myphone1);
	woo( myphone1.name, &myphone1.age);

    printf("%s : %d\n", myphone1.name, myphone1.age);
    return 0;
}
void woo( char * name, int *age)
{
	strcpy(name, "��浿");
	*age	= 20;
}
void foo( struct phone m)
{

}
*/
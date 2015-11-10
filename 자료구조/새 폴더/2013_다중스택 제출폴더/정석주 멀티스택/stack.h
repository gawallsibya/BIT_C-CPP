#include "std.h"

typedef struct Stac stac;
struct Stac
{	
	int arr[MAX];
	int dtop;
	int utop;

};

void stinit();
void push_down();
void push_up();
void pop_down();
void pop_up();
void printall();

#include <iostream>
using namespace std;

void main()
{
	int *p	= new int;			// 4byte  malloc(sizeof(int));
	int *p1 = new int(10);		// 4byte  int *p = malloc(sizeof(int));
								//			  *p = 10;
	int *p2 = new int[10];		// 40byte  malloc(sizeof(int)*10)

	delete p;
	delete p1;
	delete [] p2;

//	int * p = (int*)malloc(sizeof(int)*10);
//	p[0] = 10;
//	p[1] = 20;
//	free(p);
}
//배열
#include <stdio.h>

/*
void main()
{
	int n1;

	int n[2];
	n[2] = 10;

	printf("%d\n", n1);
}
*/

/*
void main()
{
	int n		= 10;
	int n1[3]	= {20, 30, 40};

	// n1의 위치에서 +0만큼 이동한 역참조
	// *( n1 + 0 )
	printf("%d\n", n1[0]);		// 20
}
*/

/*
void main()
{
	int n		= 10;
	int n1[3]	= {20, 30, 40};
	int result;
	// 숫자 + 숫자
	result	= n + 3;			// 13

	printf("%d : %d\n", n1, &n);			// 1245040	: 1245052

	// 주소값 + 숫자 
	result	= n1 - 2;			// n1 + sizeof(int)*2
	printf("%d\n", result);		// 1245032

	// 주소값 - 주소값
	result =  &n - n1;			// 1245052 - 1245040
	printf("%d\n", result);		// 12/sizeof(int)		==> 3
}
*/
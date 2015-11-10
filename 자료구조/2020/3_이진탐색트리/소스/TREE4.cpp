//----------------------------------------------------------------
//  검색 기능  : 이분 검색 
//----------------------------------------------------------------

#include <stdio.h>

int search( char key, char *base, int *num )
{
	int mid;

	// 구간의 초기 설정
	int left	= 0;
	int right	= *num-1;

	while( right >= left )
	{
		mid	= (right + left ) / 2;		// 구간의 중간값을 구함
		if( key == base[mid])			// 구간의 중간값이 키 값과 같으면 리턴 
			return mid;

		if( key < base[mid] )			// 오른쪽 구간을 선택하여 처음으로 돌아감
			right = mid -1;

		else

			left  = mid + 1;			// 왼쪽 구간을 선택하여 처음으로 돌아감 
	}
	return -1;
}

void main()
{
	int n;
	int num = 10;
	char chArray[10] = { 'a','b','c','d','e','f','g','h','i', 'j' };
	n = search( 'b', chArray, &num);

	if( n == -1 )
		printf("없다\n");

	else
		printf("%c\n", chArray[n]);

}
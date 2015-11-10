//----------------------------------------------------------------
//  �˻� ���  : �̺� �˻� 
//----------------------------------------------------------------

#include <stdio.h>

int search( char key, char *base, int *num )
{
	int mid;

	// ������ �ʱ� ����
	int left	= 0;
	int right	= *num-1;

	while( right >= left )
	{
		mid	= (right + left ) / 2;		// ������ �߰����� ����
		if( key == base[mid])			// ������ �߰����� Ű ���� ������ ���� 
			return mid;

		if( key < base[mid] )			// ������ ������ �����Ͽ� ó������ ���ư�
			right = mid -1;

		else

			left  = mid + 1;			// ���� ������ �����Ͽ� ó������ ���ư� 
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
		printf("����\n");

	else
		printf("%c\n", chArray[n]);

}
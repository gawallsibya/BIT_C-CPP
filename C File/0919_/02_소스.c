//�迭
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

	// n1�� ��ġ���� +0��ŭ �̵��� ������
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
	// ���� + ����
	result	= n + 3;			// 13

	printf("%d : %d\n", n1, &n);			// 1245040	: 1245052

	// �ּҰ� + ���� 
	result	= n1 - 2;			// n1 + sizeof(int)*2
	printf("%d\n", result);		// 1245032

	// �ּҰ� - �ּҰ�
	result =  &n - n1;			// 1245052 - 1245040
	printf("%d\n", result);		// 12/sizeof(int)		==> 3
}
*/
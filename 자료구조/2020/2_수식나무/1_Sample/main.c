// main.c
#include "std.h"

void main()
{
	//  ���� ǥ��� ������ ����
	char post[256];
	TREE *root = NULL;

	// ���� �ʱ�ȭ
	init_stack();

	// Ʈ�� �ʱ�ȭ 
//	init_tree();

	while(1)
	{
		printf("\n\nInput Postfix expresstion()\n");
		printf("ex) 1  2  +  3 4  -  *  5  /  6  7  *  +)\n");

		gets(post);
		// �ƹ� �͵� �Է����� ���� ��� 
		if( *post == NULL)
		{
			printf("\nPrograme end..");
			exit(0);
		}
		root = make_parse_tree(post);
		printf("\nPreorder traverse -->\n");
		preorder(root);

		printf("\nInorder traverse --->\n");
		inorder(root); 
		
		printf("\nPoseorder traverse --->\n");
		postorder(root);
	}

}
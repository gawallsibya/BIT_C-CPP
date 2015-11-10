// main.c
#include "std.h"

void main()
{
	//  후위 표기법 수식을 저장
	char post[256];
	TREE *root = NULL;

	// 스택 초기화
	init_stack();

	// 트리 초기화 
//	init_tree();

	while(1)
	{
		printf("\n\nInput Postfix expresstion()\n");
		printf("ex) 1  2  +  3 4  -  *  5  /  6  7  *  +)\n");

		gets(post);
		// 아무 것도 입력하지 않은 경우 
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
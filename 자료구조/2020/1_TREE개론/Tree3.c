//-------------------------------------------------------------
// [ 3. 이진트리의 순회 ]

//   1) 현재 노드를 방문하여 데이터를 읽는 작업(D)
//   2) 현재 노드의 왼쪽 서브 트리로 이동하는 작업(L)
//   3) 현재 노드의 오른쪽 서브 트리로 이동하는 작업(R)

//   - 서브 트리 순회시 순서는 항상 왼쪽 서브트리를 먼저 방문 
//   - 현재 노드를 방문하는 순서에 따라
//     전위, 중위, 후위 순회로 구분 

//-------------------------------------------------------------


/*
//-------------------------------------------------------------
1. 연결 리스트를 사용한 이진트리 표현 
//-------------------------------------------------------------

    - 배열의 단점을 해결하기 위해 사용 


	- 연결리스트의 각 노드는 세 개의 필드를 사용
	  LeftChild, data, RightChild


1) 노드 정의 
    typedef struct _node
	{
		int key;
		struct _node *left;   // 왼쪽 자식 노드를 가리킴
		struct _node *right;  // 오른쪽 자식 노드를 가리킴
	}node;

	node *head, ;



2) 정의한 노드 초기화 
   void init_tree(void)
   {
		head		= (node*)malloc(sizeof(node));
		head->left  = NULL;
		head->right = NULL;
   }
   - 머리의 링크들을 모두 NULL로 초기화

   - 이중 연결리스트 : 앞과 뒤로 자유롭게 이동 가능
     이진 트리       : 위에서 아래로 내려오는 방법만 제공 



3) 이진 나무의 순회(Tree traverse)

   - 트리 내의 노드를 정확히 한번씩 방문하는 것(중복 없이) 
   - 순회 방법
      L, D, R : 왼쪽으로 이동, 현재 노드 방문, 오른쪽으로 이동

   - 통상 이진 트리의 순회는 왼쪽에서 오른쪽으로 이루어진다.
     LVR, LRV, VLR : 각각을 중위, 후위, 전위라 한다.
	
   - 중위(inorder) , 후위( postorder) , 전위( preorder)
     ex) LVR(중위) : 해당 노드를 방문하기 이전에 왼쪽 부트리 방문
	                 다음으로 현재 해당 노드 방문, 
					 다음으로 오른쪽 부트리를 방문 

   - 기타 : 층별순회(Levle order traverse)

   - 이러한 이진 트리의 순회는 순환(recursive) 알고리즘과 
     반복(iterative) 알고리즘을 사용하여 구현할 수 있다. 



4) 전위 순회 : 뿌리를 먼저 타는 방법 
   1) 뿌리를 먼저 방문
   2) 왼쪽 작은 나무(SubTree)방문
   3) 오른쪽 작은 나무 방문 

   void preorder_traverse(node *t)
   {
		if( t != tail)
		{
			// 뿌리를 방문
			visit(t);
			preorder_traverse(t->left); // 왼쪽 작은 나무 방문
			preorder_traverse(t->right); // 오른쪽 작은 나무 방문 
		}
	}
	==> 재귀호출과정에서 변화되는 스택의 모양을 알아야 한다.

	    전위순위에서 뿌리를 방문하면 오른쪽 자식 노드와 왼쪽 자식
		노드를 차례로 스택에 푸쉬
		다음에 방문할 노드는 스택에서 팝한 노드가 된다. 
		스택의 내용이 완전히 비게 되면 순회 완료



5) 뿌리를 중간에 타는 방법
   1) 왼쪽 작은 나무 방문, 계속 진행
   2) 뿌리 방문
   3) 오른쪽 작은 나무 방문
   void inorder_traverse(node *t)
   {
		if(t != tail)
		{
			Inorder_traverse(t->left);
			visit(t);
			inorder_traverse(t->right);
		}
   }



6) 뿌리를 나중에 타는 방법
   1) 왼쪽 작은 나무 방문, 계속 진행
   2) 오른쪽 작은 나무 방문
   3) 뿌리 방문
   void postorder_traverse(node *t)
   {
		if(t != tail)
		{
			postorder_traverse(t->left);
			postorder_traverse(t->right);
			visit(t);
		}
   }


7) 층 별로 타는 방법은 큐를 이용하여 나무를 탄다.
    1) 큐에 뿌리노드를 put 한다.
	2) 큐가 비어있지 않으면
	   2.1) 큐에서 get하여 t에 대입, t를 방문한다.
	   2.2) t의 왼쪽 자식이 있으면 그것을 큐에 put한다.
	   2.3) t의 오른쪽 자식이 있으면 그것을 큐에 put한다.
	3) 끝 
void levelorder_traverse(node *t)
{
	put(t);
	while( !is_queue_empty())
	{
		t = get();
		visit(t);
		if(t->left !=tail)
			put(t->left);
		if(t->right != tail)
		    put(t->right);
	}
}




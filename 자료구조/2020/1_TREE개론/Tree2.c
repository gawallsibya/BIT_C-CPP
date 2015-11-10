//-------------------------------------------------------------
// [ 2. 이진 트리(binary tree) ]
//   

//   - 자주 사용되는 중요한 트리 구조 중의 하나 
//   - 트리의 노드 구조를 일정하게 정의하면 트리 연산이 쉬워진다.
//   - 차수가 2 이하가 되도록 만든 것 
//-------------------------------------------------------------

/*

//-------------------------------------------------------------
1. 이진 트리 
//-------------------------------------------------------------

1) 구성
   - 공백이거나(루트도 없다.)
     내부 노드는 자식을 한개나 두개를 가진다.
     외부 노드는 자식이 없다.

   - 루트 노드와 서로 분리된 두개의 이진 트리, 즉 왼쪽 부트리와
     오른쪽 부트리로 구성된다.

  - 이진 트리 : 자식이 두개, 순서가 존재한다.
    순서가 만들어져 있기 때문에 다르다.



2) 이진 트리의 형태

   - 포화 이진트리(full binary tree)
      : 각 레벨에 노드가 가득 차 있는 이진 트리 

   - 완전 이진트리(complete binary tree)
      : 임의의 두 단말 노드의 레벨의 차이가 1이하
	    왼쪽에서 오른쪽으로 채워진 이진 트리 

   - 사향 이진트리(skewed binary tree)


3) 이진 트리의 성질
   - 한 노드에서 다른 노드로 가는 경로는 유일하다.
      임의의 두 노드는 최소 공통선조를 갖는다.(Least Common Ancestor)
	  두 노드간의 경로는 반드시 한 노드에서 최소 공통 선조까지 올라갔다가
	  다시 다른 노드로 내려오는 유일한 경로밖에 존재하지 않는다.
   - N개의 노드를 갖는 나무는 N-1개의 링크를 가진다.



4) 이진 트리의 표현
   - 배열을 사용한 표현
     포화이진트리는 루트에서 시작하여 레벨이 증가하는 방향으로 같은
	   레벨에서는 왼쪽에서 오른쪽 노드로 정수 1부터 시작하여 차례
	   로 양의 정수를 각각 노드의 번호로 부여 
	 모든 이진 트리의 노드들은 그 위치에 따라 포화 이진 트리의 
	   노드들로 일 대 일 사상이 가능 

   - 모든 이진 트리는 1차원 배열로 표현 가능
     각 노드의 자료는 그 노드의 일련 번호에 해당하는 배열의 위치에 저장
	 단 루트 노드를 1번으로 하므로 0번째 공간은 사용 안함 

  ==> 단점 : 메모리 낭비
             깊이가 4인 사항 이진트리를 배열로 표현 : 2의 k승개 -1개 
			 실제 사용 기억공간 : k개 
			 트리에 노드를 삽입 삭제하기 위해 많은 자료 이동 필요 
   - 이진 트리를 배열로 표현하는 경우는 트리가 완전 이진 트리일 때 
     효율적
*/
//main.cpp

#include "std.h"

#include "employee.h"
#include "linkedlist.h"

LinkedList g_list;

void main()
{
	// 이름, 학번, 학년, 학과
	g_list.insertNode( new Employee("홍길동", 11, "1", "IT"));
	g_list.insertNode( new Employee("김길동", 11, "1", "IT"));
	g_list.insertNode(2, new Employee("고길동", 11, "1", "IT"));

//	Employee *pData = g_list.deleteNode(1);
//	cout << "삭제되는 데이터 : ";
//	pData->printdata();

	//검색
	for(int i=1; i<= g_list.length(); i++)
	{
		Node *cur = g_list.retrieveNode(i);
		Employee *pData = cur->data;
		if( strcmp(pData->getName().c_str() , "홍길동")==0)
		{
			pData->printdata();
			return;
		}		
	}
	

//	g_list.display();
}

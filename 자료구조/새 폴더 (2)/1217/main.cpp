//main.cpp
#include "std.h"

#include "employee.h"
#include "linkedlist.h"

LinkedList g_list;

void main()
{
	g_list.insertNode(new Employee("홍길동",200910487,"1학년","IT학과"));
	g_list.insertNode(new Employee("김길동",200910487,"1학년","IT학과"));
	g_list.insertNode(2 , new Employee("고길동",200910487,"1학년","IT학과"));

	Employee *pData = g_list.deleteNode(1);
	cout<<"삭제 데이터: ";
	pData->printdata();
	g_list.display();
}

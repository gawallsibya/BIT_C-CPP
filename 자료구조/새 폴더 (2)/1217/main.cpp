//main.cpp
#include "std.h"

#include "employee.h"
#include "linkedlist.h"

LinkedList g_list;

void main()
{
	g_list.insertNode(new Employee("ȫ�浿",200910487,"1�г�","IT�а�"));
	g_list.insertNode(new Employee("��浿",200910487,"1�г�","IT�а�"));
	g_list.insertNode(2 , new Employee("��浿",200910487,"1�г�","IT�а�"));

	Employee *pData = g_list.deleteNode(1);
	cout<<"���� ������: ";
	pData->printdata();
	g_list.display();
}

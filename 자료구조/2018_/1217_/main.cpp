//main.cpp

#include "std.h"

#include "employee.h"
#include "linkedlist.h"

LinkedList g_list;

void main()
{
	// �̸�, �й�, �г�, �а�
	g_list.insertNode( new Employee("ȫ�浿", 11, "1", "IT"));
	g_list.insertNode( new Employee("��浿", 11, "1", "IT"));
	g_list.insertNode(2, new Employee("��浿", 11, "1", "IT"));

//	Employee *pData = g_list.deleteNode(1);
//	cout << "�����Ǵ� ������ : ";
//	pData->printdata();

	//�˻�
	for(int i=1; i<= g_list.length(); i++)
	{
		Node *cur = g_list.retrieveNode(i);
		Employee *pData = cur->data;
		if( strcmp(pData->getName().c_str() , "ȫ�浿")==0)
		{
			pData->printdata();
			return;
		}		
	}
	

//	g_list.display();
}

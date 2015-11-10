//linkedlist.cpp
#include "std.h"

#include "employee.h"
#include "linkedlist.h"

//Node====================================
Node::Node(Employee* _data, Node* _next, Node* _prev) : data(_data),next(_next),prev(_prev) 
{
	
}
Node::Node()
{
}

//Linkedlist====================================
LinkedList::LinkedList()
{
	count=0;
	head=NULL;
	tail=NULL;
}

LinkedList::~LinkedList()
{

}

bool LinkedList::insertNode(Employee* data)
{
	Node *newnode = new Node(data,NULL,NULL);

	if(head == NULL)
	{
		head = newnode;
		tail = newnode;
	}
	else
	{
		newnode->next = head;
		head->prev	  = newnode; 
		head		  = newnode;
	}
	++count;
	return true;
}

bool LinkedList::insertNode(int idx, Employee* data)
{
	Node* cur= retrieveNode(idx);
	if(cur != NULL)
	{
		//노드 생성
		Node* newnode = new Node(data,NULL,NULL);
		//연결
		if(cur==tail)
		{
//			newnode->next =cur->next;
			newnode->prev =cur;

			cur->next = newnode;
			tail=newnode;
		}
		else
		{
			newnode->next	=cur->next;
			newnode->prev	=cur;
			cur->next->prev	=newnode;
			cur->next       =newnode;
		}
		
		++count;
		return true;
	}
	else
	{
		cout<<"삽입 오류..."<<endl;
		return false;
	}
	return false;
}

Employee* LinkedList::deleteNode(int idx)
{
	Node* cur = retrieveNode(idx);
	if(cur != NULL)
//	if(idx > 0 && idx <= count)
	{
		//이동
//		Node* cur=head;
//		for(int i=0;i<idx;i++)	cur=cur->next;
		
		//삭제
		Node *prev=cur->prev;
		if(cur==head)
		{
			cur->next->prev=NULL;
			head=cur->next;
		}
		else if(cur==tail)
		{
			prev->next=NULL;
			tail=prev;	
		}
		else
		{
			prev->next		=cur->next;
			cur->next->prev	=prev;
		}
		Employee *pData = cur->data;
		delete cur;
		return pData;
	}
	else
	{
		cout<<"삭제 오류..."<<endl;
		return NULL;
	}
}

Node* LinkedList::retrieveNode(int idx)
{
	if(idx > 0 && idx <= count)
	{
		//이동
		Node* cur=head;
		for(int i=0;i<idx-1;i++)	cur=cur->next;
		return cur;
	}
	else
		return NULL;
}

bool LinkedList::isEmpty()
{
	if(head == NULL)  //count == 0
		return true;
	else
		return false;
}

int LinkedList::length()
{
	return count;
}

void LinkedList::display()
{
	Node* cur = head;
	while(cur != NULL)
	{
		Employee* pData = cur->data;
		pData->printdata();
		//(cur->data)->printdata();
		cur=cur->next;
	}
}
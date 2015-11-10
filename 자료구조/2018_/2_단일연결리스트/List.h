
#include <iostream>		
using namespace std;


template <typename T> class list		
{


public:
	struct Node	
	{	
		T data;		
		Node* next;		
	};
	Node* head;

	list() :head(0) {}

	void push_front( T n );	
	T pop_front();	

	typedef Node* POSITION;

	POSITION get_first_position()	
	{		
		return head;	
	}
	POSITION get_next_position(POSITION p )	
	{
		// 마지막 node인가 ??
		return p->next;
	}
	T get_data( POSITION p)	
	{		
		return p->data;		
	}
};


template <typename T>
void list<T>::push_front( T n )
{
	Node* p = new Node;				
	p->data = n;
	p->next = NULL;

	if ( head == 0) // 1번째로 list에 놓이는 경우.
	{
		head = p;
	}
	else // n개의 Node가 이미 있는 경우....
	{
		p->next = head;
		head = p;
	}
}


template <typename T>
T list<T>::pop_front()	
{
	Node *deletenode;
	T    temp;
	if( head == 0 )
	{
		cout << "삭제할 데이터가 없습니다" << endl; 
		
	}
	else
	{
		deletenode	= head;
		head		= deletenode->next;
		temp		= get_data(deletenode);
		free(deletenode);
		return temp;
	}
}

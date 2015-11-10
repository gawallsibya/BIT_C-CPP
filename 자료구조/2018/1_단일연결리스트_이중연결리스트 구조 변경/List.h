
#include <iostream>		
using namespace std;


// 자료구조 클래스 
template <typename T>		
class list		
{
public:
	struct Node	
	{	
		T data;		
		Node* next;	
		Node* prev;
	};
private:
	Node*	head;
	int		count;
public:
	//==============================================
	//생성자
	list() :head(0), count(0) {}
	//=============================================

	//===============================================
	// 데이터 front 삽입 
	//=================================================
	void push_front( T n );	

	//=================================================
	// 데이터 front 삭제
	//=================================================
	T pop_front();	

	T erase(Node * del);


	// typedef
	typedef Node* POSITION;

	// head 리턴
	POSITION get_first_position()	
	{		
		return head;	
	}

	// 인자로 전달된 node 의 다음 node 리턴
	POSITION get_next_position(POSITION p )	
	{
		// 마지막 node인가 ??
		return p->next;
	}

	// 인자로 전달된 node의 데이터 리턴
	T get_data( POSITION p)	
	{		
		return p->data;		
	}
};

template <typename T>
T list<T>::erase(Node * del)
{
	if( head == del)
	{
		head	= del->next;		//1
	}
	else if(del->next == NULL)
	{
		del->prev->next = NULL;		//1
	}
	else
	{
		del->prev->next = del->next;		// 2
		del->next->prev = del->prev;		// 3
	}

	T	data = get_data(del);
	delete del;
	count--;
	return data;
}

template <typename T>
void list<T>::push_front( T n )
{
	Node* p = new Node;				
	p->data = n;
	p->next = NULL;
	p->prev = NULL;

	if ( head == 0) // 1번째로 list에 놓이는 경우.
	{
		head = p;
	}
	else // n개의 Node가 이미 있는 경우....
	{
		p->next = head;

		head->prev = p;
		head = p;
	}
	count++;
}


template <typename T>
T list<T>::pop_front()	
{
	Node *deletenode;
	T    temp;
	if( head == 0 )
		return 0;

	else
	{
		deletenode	= head;

		head->prev	= NULL;
		head		= deletenode->next;

		temp		= get_data(deletenode);
		free(deletenode);
		count--;
		return temp;
	}
}

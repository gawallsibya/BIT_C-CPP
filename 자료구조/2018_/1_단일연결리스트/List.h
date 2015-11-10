
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
	Node* head;
	int count;


public:
	//생성자
	list() :head(0), count(0) {}

	//데이터 front 삽입
	void push_front( T n );	
	//데이터 front 출력 및 삭제
	T pop_front();

	T erase(Node * del);

	// Node * 를 POSITION으로 재정의
	typedef Node* POSITION;

	//head 리턴
	POSITION get_first_position()	
	{		
		return head;	
	}

	//전달된 Node의 다음 Node.
	POSITION get_next_position(POSITION p )	
	{
		// 마지막 node인가 ??
		return p->next;
	}

	//전달된 인자에 해당하는 데이터 가져오기.
	T get_data( POSITION p)	
	{		
		return p->data;		
	}
};

template <typename T>
void list<T>::push_front( T n )
{
	POSITION p = new Node;				
	p->data = n;
	p->next = NULL;
	p->prev = NULL;

	if(head == 0) // 1번째로 list에 놓이는 경우.
	{
		head = p;
	}
	else
	{
		p->next		= head;

		head->prev	= p;
		head = p;
	}
	count++;
}

template <typename T>
T list<T>::erase(Node * del)
{
	if(head == del)
	{
		head	= del->next;
	}
	else if(del->next == NULL)
	{
		del->prev->next  = NULL;
	}
	else
	{
		del->prev->next		= del->next;
		del->next->prev		= del->prev;
	}

	T temp	= get_data(del);
	free(del);
	count--;
	return temp;
}


template <typename T>
T list<T>::pop_front()	
{
	POSITION deletenode;
	T    temp;

	if( head == 0 )
		return 0;
	else
	{
		deletenode		= head;

		head->prev		= NULL;
		head			= deletenode->next;

		temp			= get_data(deletenode);
		free(deletenode);
		count--;
		return temp;
	}
}

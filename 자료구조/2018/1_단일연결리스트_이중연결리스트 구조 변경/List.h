
#include <iostream>		
using namespace std;


// �ڷᱸ�� Ŭ���� 
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
	//������
	list() :head(0), count(0) {}
	//=============================================

	//===============================================
	// ������ front ���� 
	//=================================================
	void push_front( T n );	

	//=================================================
	// ������ front ����
	//=================================================
	T pop_front();	

	T erase(Node * del);


	// typedef
	typedef Node* POSITION;

	// head ����
	POSITION get_first_position()	
	{		
		return head;	
	}

	// ���ڷ� ���޵� node �� ���� node ����
	POSITION get_next_position(POSITION p )	
	{
		// ������ node�ΰ� ??
		return p->next;
	}

	// ���ڷ� ���޵� node�� ������ ����
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

	if ( head == 0) // 1��°�� list�� ���̴� ���.
	{
		head = p;
	}
	else // n���� Node�� �̹� �ִ� ���....
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

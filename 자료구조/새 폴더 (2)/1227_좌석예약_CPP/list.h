//list.h
#ifndef _LIST_H_
#define _LIST_H_
#define NULL 0
template <class T>
class List
{
public:
	struct Node
	{
		T data;
		Node* prev;
		Node* next;
	};
private:
	int count;
	Node* head;
	Node* tail;
public:
	List();
	~List();

	void insert(T);
	Node* Isequal(string);
	void deleted(Node*);
};
template <class T>
List<T>::List()
{
	count = 0;
	head = NULL;
	tail = NULL;
}
template <class T>
List<T>::~List()
{
	
}
template <class T>
void List<T>::insert(T _data)
{
	Node *newnode  = new Node ;
	newnode->data = _data;
	newnode->next = NULL;
	newnode->prev = NULL;
	if(head == 0)
	{
		head = newnode;
		tail = newnode;
	}
	else 
	{
		newnode->next = head;
		head->prev = newnode;
		head = newnode;
	}
	count++;
}
template <class T>
List<T>::Node* List<T>::Isequal(string n)
{
	Node* cur;
	string _n;
	cur = head;
	while (cur != 0)
	{
		_n = cur->data->getphone();
		//if(n==_n)
		if(strcmp(n.c_str(),_n.c_str()) == 0)
			return cur;
		cur = cur->next;
	}
	return 0;
}
template <class T>
void List<T>::deleted(Node* cur)
{
	if(cur->prev == NULL)
	{	
			if(count == 1)
			{
				head = cur->next;
				delete cur;
				count--;
			}
			else
			{
				head = cur->next;
				head->prev = NULL;
				delete cur;
				count--;
			}
	}
	else
	{
		cur->prev->next = cur->next;
		if (cur->next == NULL)
		{
			cur->prev->prev = NULL;
		}
		else
		{
			cur->prev->next = cur->next;
		}
		delete cur;
		count--;
	}
}
#endif /*_LIST_H_*/
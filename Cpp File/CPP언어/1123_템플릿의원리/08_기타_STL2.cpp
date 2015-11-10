//------------------------------------------------------
// STL : ���� �ۼ�
//-------------------------------------------------------

#include <iostream>
using namespace std;


/*
template<class T>
class A{
	class B	{	};
};
void main()
{
	B b; // ?
	A<int>::B b; // ok
}
*/



/*
template<class T> 
class slist	
{
	struct Node	
	{
		T data;			Node* next;
		Node( T d, Node* n) : data(d), next(n) {}
	};
	Node* head;
public:
	slist( ): head(0) {}
	void push_back( T a) { head = new Node( a, head);}
	// slist�� ����Ҹ� �����ϴ� iterator�� �����.
	class iterator	
	{
	private:
		Node* current;
	public:
		iterator(Node* init = 0) : current(init) {}
		iterator operator++()		{
			current = current->next;
			return *this;
		}
		T& operator*()		{		return current->data;		}
		bool operator !=(const iterator& t )		{return (current != t.current);	}
	};
	// ���۰� �� iterator�� ��� �Լ�
	iterator begin() { return iterator( head); }
	iterator end()   { return iterator();}	// C++�� ����??
};


template<class T1, class T2>
T1 find( T1 begin, T1 end, const T2 value)
{
	while( begin != end && *begin != value)
		++begin;

	return begin;
}



void main()
{
	slist<int> s;
	s.push_back(10);	s.push_back(20);	s.push_back(30);	s.push_back(40);
	slist<int>::iterator b = s.begin();
	slist<int>::iterator e = s.end();

//	slist<int>::iterator p = find( s.begin(), s.end(), 20);
	slist<int>::iterator p = find( b, e, 20);
	cout << *p << endl; // 20
	++p;
	cout << *p << endl; // ?
}
*/
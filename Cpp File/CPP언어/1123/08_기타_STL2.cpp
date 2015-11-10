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
		bool operator !=(const iterator& t )	
		{return (current != t.current);	}
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


#include <vector>	// STL ���� �����Ǵ� �迭 �����̳� 
#include <list>
/*
template <typename T>
class vector
{
	T data;
	int size;
	int maxsize;
};
class vector
*/
void main()
{
	vector<int> data;
	data.push_back(10);		data.push_back(20);		data.push_back(30);
	
	int *p = find(&data[0], &data[2], 20);
	cout << *p << endl; 

	vector<int>::iterator begin = data.begin();
	vector<int>::iterator end	= data.end();
	vector<int>::iterator p1		= find(begin, end, 30);
	cout << *p1 << endl;

	list<int>	mylist;
	mylist.push_back(10);		mylist.push_back(20);
	list<int>::iterator itr = mylist.begin();
	cout << *itr << endl ;
	itr++;
	cout << *itr << endl; 
}

/*
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

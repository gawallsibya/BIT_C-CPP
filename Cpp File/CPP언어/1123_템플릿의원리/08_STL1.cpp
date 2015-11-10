//����������������������������������
//  [ �Ϲ�ȭ ���α׷��� ]
//����������������������������������


/*
//������������������������������������������������������������������
// STL �� �Ϲ�ȭ ���α׷���(generic programming)�� �� ���̴�.
//������������������������������������������������������������������

  - �� �� : ���������� ������ �ڵ带 �ۼ��ϴ°� 
  - �� �� : ���ø� 

  - STL   : �˰����� �Ϲ�ȭ�� ǥ������ ����
            iterator�� ���� �̺κ��� ������ �Ѵ�.


//������������������������������������������������������������������
// iterator�� �Ϲ�ȭ�� STL�� �����ϴµ� �ʿ��� ����
//������������������������������������������������������������������

  - iterator�� ���ؼ� �پ��� �����̳ʸ� ������ �˰��� 
    �����ų �� �ְ� ��������������.
	=> �Ϲ�ȭ�� �ʼ��̴�.
*/


// ��)
#include <iostream.h>


//������������������������������������������������������������������
// 1. int type�� Ư���� find �Լ� ���� (�迭)
//������������������������������������������������������������������
//  �迭���� ���� ã���� �߰ߵ� �ּҸ� ����.
int *find_ar(int *ar, int n, const int & val)	
{
	for( int i=0; i< n; i++)
	{
		if(ar[i] == val)			
		return &ar[i];
	}
	return 0;
}

//  ���ø�ȭ �غ���...
template<typename T>
T *find_ar(T *ar, int n, const T & val)
{
	for( int i=0; i< n; i++)	
	{
		if(ar[i] == val)		
			return &ar[i];
	}
	return 0;
}


//������������������������������������������������������������������
// 2. int type�� Ư���� find �Լ� ���� (���Ḯ��Ʈ)
//������������������������������������������������������������������
struct Node
{
	int		item;		
	Node	*next;	
};
Node* find_ll(Node* head, const int & val)
{
	Node *start;
	for( start = head; start != 0; start= start->next)
	{
		if( start->item == val)			
			return start;
	}
	return 0;
}	


//������������������������������������������������������������������
// 3. �迭�� ���Ḯ��Ʈ ��
//������������������������������������������������������������������
���� �ٸ� �˰����� ����ϰ� �ִ�. 
   ������ : �迭�� : ++ �������� ����, ���Ḯ��Ʈ�� start->next �� ����
   ������ : �����̳ʿ� ����ִ� ������ ���ʴ�� �̵��ϸ鼭 �� 
   => �������� ���������� �����Ű�� ������ �Ϲ�ȭ�����̴�



//������������������������������������������������������������������
// 4. �迭 find �˰��� ���� I
//������������������������������������������������������������������
typedef int *iterator;
iterator find_ar1(iterator ar, int n, const int & val)
{
	for ( int i =0; i< n; i++, ar++)
		if( *ar == val)		
			return ar;	
		return 0;
}


//������������������������������������������������������������������
// 4. �迭 find �˰��� ���� II -> ���� ���� �������ڷ� ����
//������������������������������������������������������������������
typedef int *iterator;
iterator find_ar2(iterator begin, iterator end, const int & val)
{
	iterator ar;
	for ( ar = begin; ar != end; ar++)		
		if( *ar == val)	
			return ar;	
		return 0;
}


//������������������������������������������������������������������
// 5. ���Ḯ��Ʈ  find �˰��� ���� I -> *�� ++ ������ ������ �ʿ�
//������������������������������������������������������������������
class iterator1{
	Node *pt;	
public:
	iterator1() : pt(0) {}
	iterator1(Node *pn) : pt(pn) {}
	int operator*() { return pt->item;}
	iterator1 & operator++()			// ++ it�� ����	
	{
		pt = pt->next;		return *this;
	}
	iterator1  operator++(int)			// it++�� ���� //  �����ڸ����� �ȵ�
	{
		iterator1 tmp = *this;	
		pt = pt->next;		
		return tmp;
	}
	iterator1 operator ==( const  iterator1 & rhs)
	{
		if( pt->item == rhs.pt->item)			
			return *this;
	}
	bool operator!=(const iterator1& i)
	{		
		return ( pt != i.pt);	
	}
};

iterator1 find_ll1(iterator1 head, const double & val)
{
	iterator1 start;
	for( start = head; start != 0; ++start)		
		if(*start == val)			
			return start;
	return 0;
}


//������������������������������������������������������������������
// 6. ���Ḯ��Ʈ�� �迭�� �̿��� find�˰����� ����� ����.
//    �� ���� �ݺ����� ���丸 �߰��ϸ� �ȴ�.
//������������������������������������������������������������������

void main()
{
	// �迭�� find �˰��� ����
	int vd[10] = { 0, 1,2,3,4,5,6,7,8,9};	
	cout << *find_ar(vd, 10, 3) << endl;

	// ���Ḯ��Ʈ�� find �˰��� ����
	Node *head = 0;
	for( int i=0;  i<10; i++)	
	{
		Node *p = new Node;	
		p->item	= i;
		p->next = head;	
		head = p;
	}
	Node *start;
	for( start = head; start != 0; start = start->next)
	{
		cout << start->item ;
	}
	cout << endl;	
	cout << find_ll(head, 3)->item << endl;
}

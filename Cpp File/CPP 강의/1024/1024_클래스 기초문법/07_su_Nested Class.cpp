/**********************************************************
 [ Nested Class : ���� Ŭ���� ] 
**********************************************************/
/*
 class ���ο� �ٸ� class�� ������ ������ �ִ� ���.
 �̸� �浹�� ���̱� ���� ���. 
 �ϳ��� Ŭ������ �ٸ� Ŭ������ ���ο����� ���� ��

class Airplane
{
public:
	class engine
	{
	};
};

class Car
{
public:
	class engine
	{
	};
};

void main()
{
	Airplane::engine e1;
	Car::engine e2;
}

---------------------------------------------
template<typename T>
class list
{
public:
	class iterator
	{

	};
};
void main()
{
	list<int>::iterator p;
}

-----------------------------------------------------------
*) template class�� nested class

  template Ŭ���� �ȿ� nested class �� ���� ��� 
  ���� Ŭ���������� template ���� �� ����� �� �ִ�. 
  ��, �Ʒ� Ŭ�������� list�� template class ������ 
  Node class �� ���ø��� �ƴϴ�. 
  ������, Node �ȿ����� template ���� T�� ����� ���� �ִ�.

template<typename T>
class list
{
public:
	class Node
	{
		T     data;
		Node* prev;
		Node* next;

		Node( T d, Node* p, Node* n )
			: data(d), prev(p), next(n) { }
	};
};

void main()
{
	list<int>::Node d;   
	// template class�ȿ� �ִ� nested class�� ��ü�� ����
}
*/
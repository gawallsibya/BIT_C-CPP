/**********************************************************
 [ Nested Class : 내포 클래스 ] 
**********************************************************/
/*
 class 내부에 다른 class의 선언을 가지고 있는 경우.
 이름 충돌을 줄이기 위해 사용. 
 하나의 클래스가 다른 클래스의 내부에서만 사용될 때

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
*) template class와 nested class

  template 클래스 안에 nested class 가 있을 경우 
  내포 클래스에서도 template 인자 를 사용할 수 있다. 
  즉, 아래 클래스에서 list는 template class 이지만 
  Node class 는 템플릿이 아니다. 
  하지만, Node 안에서도 template 인자 T를 사용할 수가 있다.

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
	// template class안에 있는 nested class의 객체를 생성
}
*/
/**********************************************************
 [ ���� ���� ] 

1. ��ü�� �Ҿ���(unstable) ���� ���� ���´�.
2. �ܺ��� ��ȭ���� ��ü ���θ� �����Ҽ� �ִ�.
3. �ɹ� data�� �ɹ� �Լ��� ���ؼ��� ���� ���� ��� �Ѵ�.
**********************************************************/


#include <iostream>		
using namespace std;

// C ��� stack�� �ʿ��Ѵ�.
int top = 0;			
int buf[10];
void push( int n )	
{		
	buf[top++] = n;	
}
int pop()		
{	
	return buf[top--];	
}
void main()	
{
	push(10);			
	push(20);
	cout << pop() << endl;
}

/*
// C++ ��� stack

void main()	{
	Stack s;		s.init( 30 );
	s.push(10);		s.push(20);		s.push(30);
	//	s.top = 100;
	cout << s.pop() << endl; // 30.
}
*/


/*
============================================================
 Sample1  Information Hiding => �Ҿ����� �ذ� 
============================================================
��ü�� �����͸� �ܺο��� ���� �����ϴ� ���� ���´�. 
��� �Լ��� ���ؼ��� ��ü�� ������ �� �ְ� �Ѵ�.
  
struct Bike
{
	int gear;
};

void main()
{
	Bike bike;
	
	bike.gear = -10;
}

-------------------------------------------------
[ �� �� �� �� ]

  ��κ� ��ü�� data�� �ܺο��� ���� �� ��� ��ü�� 
  �Ҿ����� ���� �ִ�. 
  �� �������� gear�� �ܺο��� ���� ���� �ϹǷμ� 
  gear�� -10�̶�� �߸��� ���� �ִ� �Ǽ��� �� �� �ְ� �ȴ�.

  �׷��� ��ü�� data�� �ܺο��� �������� ���ϵ��� 
  Private ������ ���´�. 
 
  ���� �ܺο��� ���� �ٲٰ��� �� ���� ��� �Լ��� ���� ���� 
  ���� ���� �ϵ��� �ؾ� �Ѵ�.


class Bike
{
	int gear;
public:
	// ��� �Լ��� private�� ���ٰ���.
	void ChangeGear( int n ) // Modifier(������) <-> accessor(������)
	{
		// ���� ��ȿ�� ���θ� �����Ҽ� �ִ�.
		if ( n >= 1 && n <= 9)
				gear = n;
	}
};

void main()
{
		Bike b;
//		b.gear = 5;
//		b.gear = 100000; // ?
		b.ChangeGear( 5 );
		b.ChangeGear( 100000);
}

*) ���� ������(private Vs public)
    private: ��ü�� ����Լ� �������� ������ �� �ִ�.
    public : ��ü�� �ܺο����� ������ �� �ִ�.

���� �����ڸ� �����ϸ� 
struct �� default�� public, 
class �� default�� private�� �ȴ�


============================================================
 Sample2  Information Hiding => �ܺ� ��ȭ ���� ���θ� ����
                                �� �� �ִ�.
============================================================

#include <iostream>
using std::cout;
using std::endl;

class stack
{
private:
	int buff[10];
	int top;
public:
	void init() 	{ top = 0;}
	void push( int n ) { buff[top++] = n;}
	int  pop( ) 	{ return buff[--top];}
	void cleanup() { top = 0;}
};
void main()
{
	stack s;

	s.init();

	s.push(10);
	s.push(20);

	cout << s.pop() << endl;
	cout << s.pop() << endl;

	s.cleanup();
}

----------------------------------------------
�� stack �� �迭�� ����ؼ� ���� �߱� ������ 
ũ�Ⱑ �׻� 10��¥�� ���� �ۿ� ����� ����. 
���� stack �� ���� �޸� �Ҵ��� ����ؼ� �ٽ� ������ٰ� ����

class stack
{
private:
	int* buff;
	int top;
public:
	void init(int n = 10) 
	{ 
		top = 0;
		buff = new int[n];
	}
	void cleanup() 
	{ 
		top = 0;
		delete[] buff;
	}

	void push( int n ) { buff[top++] = n;}
	int  pop( ) { return buff[--top];}
};

���� ���Ӱ� ������� stack�� ����ϱ� ���� ������ 
main() �Լ��� ������ �ʿ䰡 ������ ?

Stack �� �����ϴ� 4���� �������̽�(�Լ�)�� �̸��� ���¸��� 
�������� �ʴ´ٸ� ������ ���� ���·� ������ ����������.


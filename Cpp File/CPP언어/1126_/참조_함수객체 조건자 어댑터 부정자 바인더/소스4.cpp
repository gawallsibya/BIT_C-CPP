//����������������������������������������
//  [ �Լ� 5 ] 
//����������������������������������������


//������������������������������������������������������������������������������
// FUNCTOR
//������������������������������������������������������������������������������
// �̸� ������� �پ��� �Լ� ��ü
//������������������������������������������������������������������������������

#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <algorithm>
#include <functional> // �̸� ������� �Լ� ��ü ����ϱ� ����
using namespace std;



// ex1)
//void goo( void(*f)() )

template<class T> goo( T f)	{		f();		}
// �Լ�

void foo( )	{		cout << "foo" << endl;		}

class FOO	{
public:
	void operator()()		{			cout << "foo" <<endl;		}	
};

void main()	{
//	goo( foo);
	FOO f;
	f();
	goo( f ); // �Լ� ȣ��� 
}



// ex2)
int Add( int a, int b)	{		return a + b;	}
// ����ڰ� ������ �ʾƵ� -> STL�ȿ� �Ʒ� �Լ���ü�� �ִ�.
struct Add	{
public:
	int operator()(int a, int b)		{			return a+b;		}
};
void main()	{
	int x[5] = { 1,2,3,4,5};		int y[5] = { 1,2,3,4,5};		vector<int> v( 5);
//	Add add;
	transform( x, x+5, y, v.begin(), Add);
	copy(v.begin(), v.end(), ostream_iterator<int>(cout, " " ));		cout << endl;
}




// ex3)  ����ڰ� ������ �ʾƵ� -> STL�ȿ� �Ʒ� �Լ���ü�� �ִ�.
void main()	{
	int x[5] = { 1,2,3,4,5};		int y[5] = { 1,2,3,4,5};		vector<int> v( 5);
//	multiplies<int> p; // ���ϱⰡ ������ �Լ���ü.
//	transform( x, x + 5,  y, v.begin(),  p );
	transform( x, x + 5,  y, v.begin(),  plus<int>() );
	copy( v.begin(), v.end(), ostream_iterator<int>(cout, " "));
}



// ex4)
void main(){
	int a[] = {1,2,3,4,5};	int b[] = {5,4,6,3,4};		vector<int> v(5);
	// �̸� ������� �Լ� ��ü ��� Add ����� �ϴ� plus
	// �Ķ���� 5�� plus(int, int) ���� �Լ��� ����
	transform(a, a+5, b, v.begin(), plus<int>() );

	copy(v.begin(), v.end(),	ostream_iterator<int>(cout, " "));

	cout << endl;

	// negate =>  ������ ������ش�. 
	// �Ķ���� 4��. negate(int) ���� �Լ��� ����
	transform(v.begin(), v.end(), v.begin(), negate<int>() );
	copy(v.begin(), v.end(),
		ostream_iterator<int>(cout, " "));
}


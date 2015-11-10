/**********************************************************
 [ static member function ] 
**********************************************************/
/*
 ��ü ���� ȣ���� �� �ִ� ��� �Լ�
 Class�̸�::�Լ��̸�()

 �Ϲ� ����Լ��� ȣ���Ϸ��� �ݵ�� ��ü�� �ʿ��ϴ�.

 ��� �Լ��� �ܺο� ������ ��� �Լ����𿡸�static�� ǥ��


class Point
{
private:
	int x, y;
	static int count;
public:
	Point( int _x=0, int _y=0) : x(_x), y(_y) {++count;}
	~Point() { --count;}

	void print() const
	{
		cout << x << ", " << y << endl;
	}
	static int GetCount() { return count;}
};

int Point::count = 0;

void main()
{
	cout << Point::print()	<< endl;  // Error ��ü�� �ʿ��ϴ�.
	cout << Point::GetCount() << endl;// Ok
}

  ------------------------------------------
  Static ��� �Լ��� ��ü ���� ȣ���� �� �ִ� �Լ��̴�. 
  ��ü�� �����Ƿ� static ��� ������ �ƴ� � ��� ������
  �޸𸮿� ���� ���� �ʴ�. 
  �׷��� static ��� �Լ� �������� Static ��� data�� 
  ������ �� �ִ�. 
  Static ��� �Լ��� ȣ���� �� �ִ�.
  this�� ����� �� ����.(��ü�� �����Ƿ� �翬�ϴ�.)

class Test
{
private:
	int one;
	static int two;

public:
	void foo()
	{
		one = 10; // Ok
		two = 10; // ok
	}
	static void goo()
	{
		one = 10; // Error
		two = 10; // Ok
		cout << this << endl; // Error
	}
};
int Test::two = 0;

[ ���� ���� ] 

Static ��� �Լ��� �����Լ��� ���� ����. 

*/
/**********************************************************
 [ static member data ] 
**********************************************************/
/*
 ������ Ŭ������ ��� ��ü�� �����ϴ� ����
class Point
{
public:
	int x;
	int y;
	static int count;

	Point( int _x, int _y) : x(_x), y(_y) {}
};
int Point::count = 0;

void main()
{
	cout << Point::count << endl;

	Point p1(1,1);
	Point p2(2,2);
	p1.x	 	= 10;
	p1.count	= 20;

	cout << p2.x	 	<< endl;
	cout << p2.count 	<< endl;
	cout << sizeof(p1) << endl;
}
-------------------------------------------------
*) Static member data

   ������ class�� ��� ��ü�� �����ϴ� ����� ����� �ִ�. 

   - �ݵ�� Ŭ���� �ܺο�(���� ���Ͽ���)�� ���ǵǾ�� �Ѵ�.
   - ��ü�� 1���� �������� �ʾƵ� �޸𸮴� �Ҵ�ȴ�.
   - ��� ��ü�� ���� ���� �ȴ�.
   - Ŭ���� �̸���  ��ü �̸� ��� ����ؼ� ������ �� �ִ�.
     (������ �ǵ��� Ŭ���� �̸��� ����ؼ� �����ϴ°� ����.)

*) Static ��� data�� ����ϸ� �Ʒ�ó�� ������ 
   ��ü�� ������ Count�� �� �ִ�.

class Point
{
public:
	int x, y;
	static int count;
	Point( int _x=0, int _y=0) : x(_x), y(_y) {++count;}
	~Point() { --count;}
};
int Point::count = 0;
void main()
{
	Point p1, p2;
	Point parr[5];

	cout 	<< "�� " << Point::count 
		<< "���� ���� �����Ǿ����ϴ�." << endl;
}

*) static const ���
  Ŭ������ const ��� data�� �ݵ�� �����ڿ��� �ݷ� 
  �ʱ�ȭ �ؾ� �Ѵ�. 
  ������ ��κ� const�� static���� ����� ����.
  �̶� static const ������ Ŭ������ ����ο��� �ʱ�ȭ 
  �� �� �ִ�. ���� �̶��� Ŭ������ ���� ���Ͽ��� ���� �Ǿ�
  �Ѵ�.
  ��, �����迭�� ���� ����� class ������ �ʱ�ȭ �� �� �ִ�.

class Some {
public:
	static const int sz = 10;
	char buf[sz];
};
const int Some::sz;


[ ���� ���� ]
1. �� PointŬ������ count�� static ��� ��� 
   ���������� �ٲپ� ������.
   Static ��� data�� ���������� �������� ������ ������ 
   ������ ������� ������ �̾߱��� ������.

*/

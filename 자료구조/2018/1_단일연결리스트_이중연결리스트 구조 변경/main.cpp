#include "List.h"


void print_all(list<int> s)
{
	if( s.get_first_position() == 0 )
		cout << "�����Ͱ� �����ϴ�" << endl;
	else
	{
		list<int>::POSITION cur = s.get_first_position();
		while(cur)
		{
			cout << s.get_data(cur)  << endl; 
			cur = s.get_next_position(cur);
		}
	}
}


list<int>::POSITION search_data(list<int> s, int data)
{
	if( s.get_first_position() == 0 )
	{
		return NULL;
	}
	else
	{
		list<int>::POSITION cur = s.get_first_position();
		while(cur)
		{
			int num = s.get_data(cur);
			//================================
			if( num == data)
				return cur;

			//================================
			cur = s.get_next_position(cur);
		}
		return NULL;
	}
}


void main()
{
	list<int> s; // ���� list�� template�� �̸��̴�.
				 // type�� �̸��� list<int> ��� ������� ����ؾ� �Ѵ�.

	// ������ ����,=============================================
	int num;
	cout << "�Է� : ";  cin >> num;
	s.push_front(num);		//head ->30 -> 20 ->10


	// ��ü ������ ��� ========================================
	cout << "��� :" << endl; 
	print_all(s);

	// ������ �˻� ==============================================
	cout << "������ �˻�" << endl;
	list<int>::POSITION cur = search_data(s, 30);
	if( cur != NULL)
	{
		int num = s.get_data(cur);
		cout << num << endl; 
	}
	else
	{
		cout << "�����Ͱ� �����ϴ�" << endl;
	}

	// ������ ����===============================================
	cout << "������ ����" << endl; 
	list<int>::POSITION cur1 = search_data(s, 30);
	if( cur1 != NULL)
	{
		int data = s.erase(cur1);
		cout << data <<"�� �����߽��ϴ�."<<endl;
	}
	else
	{
		cout << "�����Ͱ� �����ϴ�" << endl;
	}

	// ������ ����=================================
	cout << "������ ����" << endl; 
	list<int>::POSITION cur2 = search_data(s, 20);
	if( cur2 != NULL)
	{
		cur2->data	= 111;
		cout << "�����߽��ϴ�.."<<endl;
	}
	else
	{
		cout << "�����Ͱ� �����ϴ�" << endl;
	}

//	// ��ü ������ ��� 
	cout << "��� :" << endl; 
	print_all(s);
}
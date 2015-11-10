#include "List.h"


void print_all(list<int*> s)
{
	if( s.get_first_position() == 0 )
		cout << "�����Ͱ� �����ϴ�" << endl;
	else
	{
		list<int*>::POSITION cur = s.get_first_position();
		while(cur)
		{
			int *data = s.get_data(cur);
			cout << *data  << endl; 
			cur = s.get_next_position(cur);
		}
	}
}


list<int*>::POSITION search_data(list<int*> s, int data)
{
	if( s.get_first_position() == 0 )
	{
		return NULL;
	}
	else
	{
		list<int*>::POSITION cur = s.get_first_position();
		while(cur)
		{
			int* num = s.get_data(cur);
			//================================
			if( *num == data)
				return cur;

			//================================
			cur = s.get_next_position(cur);
		}
		return NULL;
	}
}


void main()
{
	list<int*> s; // ���� list�� template�� �̸��̴�.
				 // type�� �̸��� list<int> ��� ������� ����ؾ� �Ѵ�.

	// ������ ����,=============================================
	int *pnum = new int(10);
	s.push_front(pnum);		//head ->30 -> 20 ->10

	int *pnum1 = new int(20);
	s.push_front(pnum1);		//head ->30 -> 20 ->10

	int *pnum2= new int(30);
	s.push_front(pnum2);		//head ->30 -> 20 ->10

	// ��ü ������ ��� ========================================
	cout << "��� :" << endl; 
	print_all(s);

	// ������ �˻� ==============================================
	cout << "������ �˻�" << endl;
	list<int*>::POSITION cur = search_data(s, 30);
	if( cur != NULL)
	{
		int* num = s.get_data(cur);
		cout << *num << endl; 
	}
	else
	{
		cout << "�����Ͱ� �����ϴ�" << endl;
	}

	// ������ ����===============================================
	cout << "������ ����" << endl; 
	list<int*>::POSITION cur1 = search_data(s, 30);
	if( cur1 != NULL)
	{
		int* data = s.erase(cur1);
		cout << *data <<"�� �����߽��ϴ�."<<endl;
		delete data;	//<================================
	}
	else
	{
		cout << "�����Ͱ� �����ϴ�" << endl;
	}

	// ������ ����=================================
	cout << "������ ����" << endl; 
	list<int*>::POSITION cur2 = search_data(s, 20);
	if( cur2 != NULL)
	{
		int* num = s.get_data(cur2);
		*num	= 111;
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
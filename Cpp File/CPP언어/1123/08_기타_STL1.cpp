//-------------------------------------------------------------
// STL�� ����
//---------------------------------------------------------------


#include <iostream.h>
// ��� type�� �迭���� ���ϴ� ���� ã���� �ִ�. 
// type�� ������ �Լ�.!


template<class T1, class T2>
T1 find( T1 begin, T1 end, const T2 value)	
{
	while( begin != end && *begin != value)
		++begin;
	return begin;
}

void main()	
{
	double x[] = { 1,2,3,4,5,6,7,8,9,10};

	double* p = find( x, x+10, 5.0);

	cout << *p << endl; // ?
}


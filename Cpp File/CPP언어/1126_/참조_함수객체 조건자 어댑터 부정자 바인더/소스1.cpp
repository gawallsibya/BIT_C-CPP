//����������������������������������������
//  [ �Լ� 2 ] 
//����������������������������������������



//������������������������������������������������������������������������������
// ������ �Լ�(predicate) 
//   : bool�� �����ϴ� �Լ�
//������������������������������������������������������������������������������

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;

bool Is3times( int a )
{
	return ( a%3 ) == 0 ;
}
void main()
{
	ostream_iterator<int> out( cout, " ");

	int a[] = { 1,2,3,4,5,6,7,8,9,10};

	vector<int> v(a, a+10);

	remove_if(v.begin(), v.end(), Is3times); 

	copy(v.begin(), v.end(), out);

	
}






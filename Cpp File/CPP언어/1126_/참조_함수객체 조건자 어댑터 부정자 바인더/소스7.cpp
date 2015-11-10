//����������������������������������������
// [  ���δ�  ]
//����������������������������������������

//������������������������������������������������������������������������������
// binder => � �Լ��� �Ķ���� 2��¥���� �ϳ��� �ٲ�
//������������������������������������������������������������������������������

#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <algorithm>
#include <functional>

using namespace std;


// Binder -> ���� �Լ���ü�� ���� �Լ� ��ü��..
void main(){
	deque<int> s;		s.push_back(10);
	//..... s �� ������ ����� ���� �۾��� �Ѵ�.!!!
	int x[] = { 1,2,3,4,5,6,7,8,9,10};
	modulus<int> m;
	int* p = remove_if( x, x + 10, not1( bind2nd( m, 3) ) );  //
	copy( x, p, ostream_iterator<int>(cout, " ") );
}

void main(){
	int a[] = {1,2,3,4,5,6};
	int b[] = {6,5,4,3,2,1};
	vector<int> v(6);

	// plus() ���� �Լ��� �����Լ��� �ٲٰ��� �� ��
//	transform(a, a+6, b, v.begin(), plus<int>() );
	transform(a, a+6, v.begin(), bind2nd(plus<int>(), 1) );
	// bind1st() �� ù��° �Ķ���� ����, bind2nd�� �ι�° �Ķ���� ����

	copy(v.begin(), v.end(), ostream_iterator<int>(cout, " ") );

	list<int> li;
	li.push_back(10);
	li.push_back(5);
	li.push_back(6);
	li.push_back(9);
	li.push_back(11);

	// modulus �� % ��������.
	// 3�� ��� ����
	list<int>::iterator p = remove_if(li.begin(), li.end(),
		not1(bind2nd(modulus<int>(), 3)));
	// not1�� ������, bind2nd�� �ι�° �Ķ���� ����
	// bind2nd(Add, 2) => �̷��� �ȵ�. �Լ���ü�� �ȴ�.
	copy( li.begin(), p, 
		ostream_iterator<int>(cout, " "));
}

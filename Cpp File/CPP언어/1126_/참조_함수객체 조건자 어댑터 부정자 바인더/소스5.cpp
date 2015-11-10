//����������������������������������������
//  [ Adapter ]
//����������������������������������������


//������������������������������������������������������������������������������
// container adapter
//������������������������������������������������������������������������������


#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <stack>
#include <list>
using namespace std;

// list �� ��ġ stack ó�� ���̰� �Ѵ�
template<class T, class Container = deque<T>  > 
class stack	{
private:
	Container s;
public:
	void push( T n )	{		s.push_back(n);		}
	T pop()	{		return s.pop_back();		}
};
void main()	{
	stack< int, list<int> >  st;		st.push( 10);		st.push( 20);
	st.pop();
}

//����������������������������������������
// [ STL ]
//
//   0. ���� 
//   1. �Լ�(function)			
//   2. ������(predicate)
//   3. �Լ� ��ü(function object)
//   4. �Լ� �����(function adaptor)  
//   5. ������(negator)�� ���δ�(binder)
//����������������������������������������


//��������������������������������������
//  [ 0. ���� ] 
//��������������������������������������


// accumulate ���׸� �Լ� 
// �� ���� �ݺ��� first, init���� ���ڷ� �޾� 
// �ݺ��� ���̿� ��ġ�� ��簪�� init ���� ���� ����� ������ ����..
/*
template <typename InputInterator, typename T>
T accumulate( InputInterator first, InputInterator last, T init)
{
	while( first != last)
	{
		init = init + *first;
		++first;
	}
	return init;
}
*/
// ==> ���� accumulate�� ȣ���� �� �ٸ� ������ ����ǵ��� �Ϸ���??
//     ���ڷ� �̿� �ش��ϴ� �Լ��� �Ѱ��ָ� �ȴ�.
//     �Լ� �����͸� �ʿ�� �Ѵ�.



#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;
//��������������������������������������������������������������������
// 1) ó������ Ȯ��� accumulate ���ǿ� ȣ��.
//��������������������������������������������������������������������
/*
// �Լ������͸� ���ڷ� �ϴ� ���ø� �Լ� ����.
template <typename Inter, typename T>
T accumulate1( Inter first, Inter last, T init, T (*binary_function)(T x, T y))
{
	while( first != last)
	{
//		init = init + *first;
		init = (*binary_function)(init, *first);
		++first;
	}
	return init;
}

int multifun( int x, int y) { return x * y ; }
void main()
{
	int x[5] = { 2,3,5,7,11};
	vector<int> vector1( x, x+5);

	int product = accumulate1(vector1.begin(), vector1.end(), 1, &multifun);
	cout << product << endl;
}
// >> �� �ҽ��� ������ : ���뼺�� ��������. �Լ������ʹ� ������ �� �ۿ� ����.
//                       ������� �̵��ȴ�.
*/


//��������������������������������������������������������������������
// 2) �Լ� ��ü�� ���ø� ���ڷ� �����ϴ� ���� ���� 
//��������������������������������������������������������������������
/*
#include <numeric>
template <typename Inter, typename T, typename BinaryFunction>
T accumulate1( Inter first, Inter last, T init, BinaryFunction binary_function)
{
	while( first != last)
	{
//		init = init + *first;
		init = binary_function(init, *first);
		++first;
	}
	return init;
}

int multifun( int x, int y) { return x * y ; }
class multiply
{
public:
	int operator() (int x, int y) const { return x * y; }
};

void main()
{
	int x[5] = { 2,3,5,7,11};
	vector<int> vector1( x, x+5);		// 2, 3, 5, 7, 11

	multiply test;	// �Լ� ��ü 
	int product = accumulate(vector1.begin(), vector1.end(), 1, test);
	cout << product << endl;
}
*/
// >> �Լ� ��ü�� ������Ÿ���� �� �Լ� ��ü�� �� ����Ÿ���� �Լ����ο��� 
//    ��ȯ �����ϸ� �����ϴ�.
//    ���� ������ ������Ÿ���� �ƴ� �������� Ÿ�Ե� ����������.
/*






//������������������������������������������������������������������������������
	1 �Լ�(function)
//������������������������������������������������������������������������������
 
- ǥ�� ���̺귯������ �����ϴ� �˰����߿��� �Լ��� ���ڷ� �䱸�ϴ� �͵��� ����. 
  for_each() �˰����� �����̳ʿ� ��� ������ ���ҿ� ���ڷ� �Ѱܹ��� �Լ��� ����
*/


//	ex) printElement() �Լ��� ����Ͽ� ���� list�� ���ҵ��� ����ϴ� �ڵ�

	void printElement(int value, int temp)		// 1�� �Լ�
	{
		cout << "The list contains " << value << endl;
	}

	void main() 
	{
		vector<int> v(10);		// int�� 10���� �����Ű�� ���� + �ʱ�ȭ(0)
		for( int i=0; i<10; i++)
			v[i] = i;			// 0 1 2 3 4 5 6 7 8 9

		for_each(v.begin(), v.end(), printElement );
	}




/*
- ���� �Լ�(binary function)�� �ΰ��� ���ڸ� ���ϴµ�, 
  ���� �ٸ� �� ���������� ������ �ϳ��� ������ �Լ��� �Ѱ��ش�. 

   ex), ���ڿ� list�� ���� list�� �־�����, 
   ���ڿ� list�� ��� ������ ���ڿ��� ���� list�� ���� Ƚ����ŭ �����Ѵٰ� �� ��, 
   ǥ�� ���̺귯������ �����ϴ� transform() �Լ��� ����ϸ� ���� �� �� �ִ�. 
   �̸� ���� �켱 ���ϴ� ����� ���� ���� �Լ��� �����Ѵ�. 

	// 'base'�� 'number' ������ŭ �����Ѵ�. 
	string stringRepeat(const string& base, int number)
	{
		string result;   // 'result'�� ó���� ��� �ִ�.
		while (number--)  result += base;
		return result;
	}
	�׸���, ������ ���� transform()�� ȣ���ϸ� ���ϴ� ����� ���� �� �ִ�. 
	list<string> words;
	list<int> counts;
	...
	transform(words.begin(), words.end(), counts.begin(),
								words.begin(), stringRepeat);
	(one, two, three)�� (3, 2, 3)�� �Բ� transform()�� ȣ���ϸ�, 
	(oneoneone, twotwo, threethreethree)�� ����� ���� �� �ִ�. 



   
//������������������������������������������������������������������
   2. ������(predicate)
//������������������������������������������������������������������

- ������(predicate)�� �Ұ�(true/false) �Ǵ� �������� �����ϴ� �Լ�
- ������ C ���࿡ ����, ���� �ƴ� �������� ������ �����ϰ�, 
  ���� ��쿡�� �������� �����Ѵ�. 
  
  ex) �������� ���ڷ� �޾� �����̸� ����, �ƴϸ� ������ �����ϴ� �Լ�

	// 'year'�� ���⿡ �ش��ϸ� ���� �����Ѵ�.
	bool isLeapYear(unsigned int year)	{
		int flag = false;

		if ((year % 4) == 0) {              // 4�⸶�� �����̰�,
			flag = true;
        if((year % 100) == 0) {         // ���� 100�⸶�� ������ �ƴϰ�,
            flag = false;
            if((year % 400) == 0) {     // ���� 400�⸶�� ����
                flag = true;
            }
        }
    }
    return flag;
	}

- generic �˰����� ���ڷ� �����ڸ� ����� �� �ִ�.

  ex) find_if() �˰����� 
      �� �Լ��� �����ڸ� �����ϴ� ù��° ���Ҹ� �����ϴµ�, 
	  ���� �� �����ڸ� �����ϴ� ���Ұ� ������ end-of-range ���� �����Ѵ�. 
	  �� �˰����� ����Ͽ�, 
	  ������ ���� �⵵��� ������ list(aList)���� 
	  ù��°�� �߰ߵ� ������ ��ġ�� �����ϴ� �ڵ带 ���� �� �ִ�. 

	 list<int>::iterator firstLeap = 
				find_if(aList.begin(), aList.end(), isLeapYear);


  
   
//������������������������������������������������������������������
	3. �Լ� ��ü(function object)
//������������������������������������������������������������������

- ��ȣ �����ڸ� ����Լ��� ������ �ִ� Ŭ������ ��ü�̴�. 
  �Լ� ��ſ� �Լ� ��ü�� ����ϴ� ���� �� ���� ��찡 ������, 
  �Լ� ��ü�� �Լ��� ����ϸ�, 
  �Լ��� ȣ��� ������ �Լ� ��ü�� ��ȣ �����ڰ� ȣ��ȴ�. 
  
	ex)  
	class biggerThanThree 
	{
		public:
		bool operator()(int val) { return val > 3; }
	};

    ==> biggerThanThree Ŭ������ ��ü�� �Լ� ȣ�� ���¸� ����Ͽ� 
	    �����ϰ� �Ǹ�, 
		����Լ��� ���ǵ� ��ȣ �����ڰ� ȣ��ȴ�. 
		�̹����� �� Ŭ������ �Ϲ����� �뵵�� �� �� �ֵ��� �ٵ�� ����. 

		�����ڿ� ������ ����� �߰�����. 
	class biggerThan {
		public:
		const int testValue;
		biggerThan (int x) : testValue(x) { }

		bool operator()(int val) { return val > testValue; }
	};

	�̷��� �����ν� 'X����ũ��?'��� �Լ���ü�� ����� �ְ�, 
	���⼭ X�� ���� �Լ� ��ü�� ������ �� ���� �� �ִ�. 
	���ڷ� ������(predicate)�� �䱸�ϴ� generic �Լ��� �Լ� ��ü�� �ѱ� �� �ִµ�, 

	������ list���� 12���� ū ù��° ���� ã�Ƴ��� �ڵ��̴�. 
	list<int>::iterator firstBig =
		find_if(aList.begin(), aList.end(), biggerThan(12));

	�Ϲ� �Լ���ſ� �Լ� ��ü�� ����ϴ� ���� ū ������ ������
	1) ���ο� �Լ��� ������ �ʰ� ǥ�� ���̺귯������ �����Ǵ� �Լ���ü�� ���
	2) �ζ��� �Լ��� ȣ�������ν� ����ӵ��� ����ϰ��� �ϴ� ��
	3) �Լ���ü�� �Ͽ��� �ڽ��� ������ �ִ� ���������� �����ϰ�, 
	   ������ �� �ֵ��� ���ڴ� �� 
  
ex1) plus()�� ����Ͽ� ������� ������ �ΰ��� list�� ���Һ��� ���Ͽ�, 
     �� ����� ù��° list�� ��ġ�Ѵ�. 

	transform(listOne.begin(), listOne.end(), listTwo.begin(), 
		listOne.begin(), plus<int>());

ex2) �Ұ����� �̷���� vector���� ��� ���Ҹ� �����ϴ� ���̴�. 
	transform(aVec.begin(), aVec.end(), aVec.begin(),
		logical_not<bool>());

 

  
//������������������������������������������������������������������
   4. �Լ� �����(function adaptor)
//������������������������������������������������������������������

- �Լ��� �Լ���ü�� ����� �� �ֵ��� �����Լ� �Ǵ� ����Լ��� �ٲ��ִ� 
  Ŭ������ ��ü�̴�
  (�Լ� ��ü�� �Լ� �Ǵ� �Լ���ü�� �ൿ�� �ٲٴµ� ����� ���� �ִ�.) 

  ������ �Լ� ����ʹ� ���� �Լ� �Ǵ� ��� �Լ��� ���ڷ� �ϴ� ������ ���� 

  pointer_to_unary_function�� pointer_to_binary_function ���ø��� 
  �ϳ� �Ǵ� �ΰ��� ���ڸ� ������ ���� �Լ��� �����ϴµ� ���ȴ�. 
  �̵� ����ʹ� 
     1) ���� ������ ���� �ְ�, 
     2) ptr_fun �Լ� ���ø��� ����Ͽ� 
  ������ ����͸� �ڵ����� �����Ҽ��� �ִ�. 
  
  ex) �׳� �ܼ��� times3() �Լ��� �����Ͽ�, �̸� ���� vector�� ������ �� �ִ�. 

	int times3(int x)
	{
		return 3 * x;
	}

	int a{} {1,2,3,4,5};
	vector<int> v(a, a+5), v2;

	transform(v.begin(), v.end(), v2.end(), ptr_fun(times3));

	�Ǵ�, ����͸� �����Ͽ� ���Ӱ� ���۵� �Լ� ��ü�� vector�� �Ѱ��ش�. 
	pointer_to_unary_function<int, int> pf(times3);
	transform(v.begin(), v.end(), v2.end(), pf);

	�̷��� �ϴ� ���, �����Ϸ��� ptr_fun�� ����Ͽ� 
	pointer_to_unary_function�� �䱸�ϴ� Ÿ���� �߷��� �� �ִٴ� ������ �ִ�.  

	'mem_fun' �η��� ���ø��� �����Լ��� �ƴ� ����Լ��� �����ϴµ� ���ȴ�. 
	���� ���, list�� set�� ������ �ְ�, set���� �� list�� �����ϰ� �ʹٸ�, 
	mem_fun_t�� mem_fun�� ����Ͽ� set���� �� list�� list �����Լ��� ������ �� �ִ�. 

	set<list<int>* > s;

	// set ���ҵ��� list��� �ʱ�ȭ�Ѵ�
	...
	// set�� �����ִ� list���� ���� �����Ѵ�
	for_each(s.begin(),s.end(),mem_fun(&list<int>::sort));

	// ���� set�� ���� ������ list���� ��� ���ĵǾ���.

 

 
   
//������������������������������������������������������������������
	3.5 ������(negator)�� ���δ�(binder)
//������������������������������������������������������������������

- ������(negator)�� ���δ�(binder)�� ������ �ִ� �Լ� ��ü�κ��� 
  ���ο� �Լ� ��ü�� ����µ� ���Ǵ� �Լ� ������̴�. 
  �̵��� �ٸ� �Լ��� generic �˰����� ȣ���ϱ⿡ �ռ� ���� ����Ʈ�� 
    �����ϴ� ������ �Ϻη� ���Ǵ� ���� �����̴�. 


- ������ not1()�� not2()�� ���� ���װ� ���� ������ ��ü�� ���ڷ� �޾Ƶ鿩,
  ���� ���� �ݴ밪�� ����� ���ο� �Լ� ��ü�� �����Ѵ�. 
  ���� ���, �������� ������ widget �˻�� �Լ� ��ü�� �̿��ϸ�, �Լ���ü 

	not2(WidgetTester())
  �� widget �˻��� ���� ���ڸ� ������, widget �˻�Ⱑ ���϶� ������, 
  �����϶� ���� ��ȯ�ϴ� ���� �����ڸ� ������. 
  
  �����ڴ� unary_function�� binary_function Ŭ������ ���� Ŭ������ ���ǵ� 
  �Լ� ��ü�ϰ� ���ȴ�. 
	A Hot Idea 

- ���δ��� �ΰ��� ���ڸ� ������ �Լ��� �޾Ƽ�, 
  ù��° ���ڳ� �ι�° ���ڸ� Ư�� ������ ���ε���� �Ѱ��� ���ڸ� ������ 
  �Լ��� ����� ����. 
  �̶�, ���δ��� ���ڷ� �Ѿ���� �Լ��� binary_function Ŭ������ ���� Ŭ������ 
  ���ؾ� �Ѵ�.
  bind1st() ���δ��� ù��° ���ڸ� ���ε��ϰ�, bind2nd()�� �ι�° ���ڸ� ���ε��Ѵ�. 

  ���� ���, 
  ���δ� bind2nd(greater<int>(), 5)�� 5���� ū���� �˻��ϴ� �Լ���ü�� ������, 
  ������ ���� ���� �� �ִ�. 
  
  �Ʒ� ���� list���� ���� ���� �߰ߵǴ� 5���� ū ���� ����Ű�� �ݺ��ڸ� 
    ��ȯ�ϴ� �ڵ��̴�. 

  list<int>::iterator where = find_if(aList.begin(), aList.end(),
	         bind2nd(greater<int>(), 5));
  ���δ��� �����ڸ� �����ؼ�, ������ ���� �Լ���ü�� ������ �� �ִ�. 
  �� �Լ���ü�� ���ڰ� 3���� �������� ����, �׷��� ������ ������ ��ȯ�Ѵ�. 
    �Ʒ� �ڵ�� list�κ��� 3�� ����� �����Ѵ�. 
  list<int>::iterator where = remove_if(aList.begin(), aList.end(),
           not1(bind2nd(modulus<int>(), 3)));

  �Ʒ����� ���δ��� ���� �Լ� WidgetTester() �Լ��� ȣ���� �� widget ��ȣ�� 
  �������Ѽ�, widget���� ������ ���ڷ� ���ϴ� �Լ��� ������. 

  list<Widget>::iterator wehave = 
   find_if(on_hand.begin(), on_hand.end(), 
      bind2nd(WidgetTester(), wid));
*/
 

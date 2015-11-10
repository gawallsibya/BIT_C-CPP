#include <iostream>
using namespace std;

template <typename T>		// int ==> T
class Stack
{
private :
		T  data_arr[10]; //데이터 갯수 최대 10개인 스택 정의
		int  top;
		bool is_empty() const {return top<=0;};
		bool is_full() const {return top>=10;};
public :
		Stack():top(0){}; 	~Stack(){}
		bool push(const T&); //스택에 데이터를 저장한다.
		bool pop(T&); //스택에서 최상위 데이터를 꺼내온다.
};

template <typename T>
bool Stack<T>::push(const T& data)
{
    if (is_full()){
        cout << "PUSH Failure : The Stack Is Full" << endl;
        return false;
    }
    else {
        data_arr[top++] = data;
        return true;
    }
}

template <typename T>
bool Stack<T>::pop(T& data)
{
    if (is_empty()){
        cout << "POP Failure : The Stack Is Empty." << endl;
        return false;
    }
    else {
        data = data_arr[--top]; return true;
    }
}


int main(void)
{
 //   Stack<int> mydata; 
	Stack<char> mydata;	
	char n;
    for (int i=0; i<10; i++)
	{
        if (mydata.push(i*10))
            cout << "i: " << i << ", data: " << i*10 << ", Pushed!!" << endl;
	}
    for (i=9; i>=0; i--)
	{
        if (mydata.pop(n))   
			cout << "i : " << i << ", data : " << n << endl;
	}
    return 0;
}

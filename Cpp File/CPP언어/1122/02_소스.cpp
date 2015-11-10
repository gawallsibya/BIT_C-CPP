/*
#include <iostream.h>
#include <exception>  //exception 헤더파일 포함

class MyExcep : public exception
{
public:
	MyExcep(const char* s) : exception(s) {}
	virtual __exString what() const	{ return "내가 정의한 예외처리"; }
};

//   virtual __exString what() const;
void main()
{
	try
	{
		throw MyExcep("예외 발생....");
	}
	catch( exception& e )
	{
		cout << e.what() << endl; 
	}
	catch( ... )
	{
		cout << "예외 발생" << endl; 
	}
}
*/

/*
#include <iostream.h>
#include <exception>  //exception 헤더파일 포함

class Array{
	int size;
	int* arr;
public:
	class ESize : public exception
	{
		int index;
	public:
		ESize(int i):index(i){}
		const char* what() {return "[Out of Range]" ;};
		//가상 함수 what()을 재정의 하여 문자열을 지정하였다.
	};

	Array(){arr=NULL; size=0;};
	Array(int n);
	~Array(){ delete[] arr; }
	int getSize() { return size; }
	int summary();

	int& operator[](int i);
	const int& operator[](int i) const;
};

Array::Array(int n):size(n)
{
    arr = new int[size];
    for(int i=0; i<size; i++)  arr[i]=0;
}

int Array::summary()
{
    int sum=0;
    for (int i=0; i<size; i++)
        sum += arr[i];
    return sum;
}

int& Array::operator[](int i)
{
    if (i < 0 || i >= size)  throw ESize(i); 
    return arr[i];
}

const int& Array::operator[](int i) const
{
    if (i < 0 || i >= size)  throw ESize(i);
        return arr[i];
}

int main(void)
{
    try{
        Array mydata(3);

        for (int i=0; i<3; i++)
            mydata[i] = i*10;

        for (i=0; i<4; i++)
            cout << mydata[i] << endl;
    }
	catch(exception & err)
	{
		cout << err.what() << endl; 
	}
    catch(Array::ESize &err)
    {	
        cout << "## Exception ##\t" << err.what() << endl;
    }

    return 0;
}
*/


//[예제] Vector 클래스에 예외를 처리할 멤버 함수를 두는 예제 프로그램

#include <iostream.h>
class Vector
{
    int* p;  	int sz;
public:
    enum {MAX = 100};
    class Erange //exception class
    {
    public:
	int index;
	Erange(int i):index(i) {}
    };
    class ESize //exception class
    {
    public:
	int size;
	ESize(int s):size(s) {}
    };
    Vector(int s);
    ~Vector() {delete[] p;}
    int& operator [] (int i);
};
inline Vector::Vector(int s)
{   if (s < 0 || s > MAX) throw ESize(s);
    p = new int [sz = s];
}
inline int& Vector::operator[](int i)
{
    if (i >= 0 && i < sz) return p[i];
    throw Erange(i);
}
void use_vector()
{
    try {  Vector vec(10000);  }
    catch(Vector::ESize s) {throw Vector::ESize(s.size);}
}
int main(void)
{
    Vector vec(10);
    try{
        use_vector();
        cout << vec[11] << endl;
    }
    catch(Vector::ESize s)
    {
        cout << "Size Error : " << s.size << endl;
        try { cout << vec[11] << endl; }
        catch (Vector::Erange r){cout << "Range Error : " << r.index << endl;}
    }
    catch (Vector::Erange r) { cout << "Range Error : " << r.index << endl; }
    catch (...) { cout << "Another Error" << endl; }
    return 0;
}

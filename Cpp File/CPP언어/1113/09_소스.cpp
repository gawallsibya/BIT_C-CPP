// 추상화 클래스
// 순수 가상함수 

#include <iostream>
using namespace std;

// 추상 클래스(맴버 함수로 순수 가상함수를 하나라도 가지고 있다면) 
class Animal
{
public:
	virtual void Sound() =0;		//순수 가상함수
};

class Dog : public Animal
{
public:
	void Sound() { cout << "멍멍.." << endl; }
};

class Cat : public Animal
{
public:
	void Sound() { cout << "야옹.." << endl; }

};

void main()
{
	Animal *p[10];
	p[0]	= new Dog;		p[1] = new Cat;
	p[0]->Sound();
	p[1]->Sound();

}
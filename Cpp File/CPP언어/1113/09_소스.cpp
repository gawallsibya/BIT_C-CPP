// �߻�ȭ Ŭ����
// ���� �����Լ� 

#include <iostream>
using namespace std;

// �߻� Ŭ����(�ɹ� �Լ��� ���� �����Լ��� �ϳ��� ������ �ִٸ�) 
class Animal
{
public:
	virtual void Sound() =0;		//���� �����Լ�
};

class Dog : public Animal
{
public:
	void Sound() { cout << "�۸�.." << endl; }
};

class Cat : public Animal
{
public:
	void Sound() { cout << "�߿�.." << endl; }

};

void main()
{
	Animal *p[10];
	p[0]	= new Dog;		p[1] = new Cat;
	p[0]->Sound();
	p[1]->Sound();

}
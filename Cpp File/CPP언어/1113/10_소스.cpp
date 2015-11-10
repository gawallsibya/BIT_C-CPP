// RTTI

#include <iostream>
using namespace std;

class Animal
{
public:
	virtual void Sound() =0;		//¼ø¼ö °¡»óÇÔ¼ö
};

class Dog : public Animal
{
public:
	void Sound() { cout << "¸Û¸Û.." << endl; }
};

class Cat : public Animal
{
public:
	void Sound() { cout << "¾ß¿Ë.." << endl; }

};

void main()
{
	Animal *p[10];
	p[0]	= new Dog;		p[1] = new Cat;
	p[2]	= new Dog;		p[3] = new Cat;

	// 1. °³¸¸ Â¢¾î¶ó....
	for(int i=0; i<4; i++)
	{
		Dog *pDog = dynamic_cast<Dog*>(p[i]); // project->setting->C/C++
		if( pDog != NULL)					// C++ lan
			p[i]->Sound();
	}
}
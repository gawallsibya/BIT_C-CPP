//상속의 유형

#include <iostream>
using namespace std;

class CA
{
private :		int private_a;
protected :		int protected_a;
public :		int public_a;


};

class CB : public CA	// protected CA,   private CA
{
	void foo() 
	{
//		private_a;		// error
		protected_a;	// ok
		public_a;		// ok
	}
};

void main()
{
	CB			b;				b.public_a;
}

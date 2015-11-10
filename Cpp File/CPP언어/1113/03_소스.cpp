//protected
/*
#include <iostream>
using namespace std;

class CA
{
protected:		// 자식만 접근이 가능...
	int pta;
private:
	int pa;
public:
	int a;
};

class CB	: public CA
{
public:
	void woo()      { pta = 10;	}		// ok....
//	void goo()		{ pa = 10; }		// error...
	void foo()		{ a = 10;  }		// ok...
};

void main()
{
	CB		b;			b.a;		//ok...
//						b.pa;		// error..
						b.pta;		// error.
}
*/
/*
#include <iostream.h>
#include <string.h>

class Ancestor
{
private:	int back_money;
protected:	int hidden_money;
public:		int known_money;		char personality[20];
public:
	Ancestor(int b, int h, int k, char* p)
	    :back_money(b), hidden_money(h), known_money(k)
	{
	    strcpy(personality, p);
	}
};

class Descendent:public Ancestor
{
private:
	int his_back_money;
protected:
	int his_hidden_money;
public:
	int his_known_money;
public:
	Descendent(int ab,int ah,int ak,char* ap, int hb, int hh, int hk)
	    : Ancestor(ab, ah, ak, ap), his_back_money(hb), 
 	      his_hidden_money(hh), his_known_money(hk) {}

	void inheritance()
	{
	    his_back_money		+= back_money; //error : access denied ~!!!!
	    his_hidden_money	+= hidden_money;
	    his_known_money		+= known_money;
	}

	void print()
	{
	    cout << "Back_Money : " << his_back_money << endl;
	    cout << "Hidden_Money : " << his_hidden_money << endl;
	    cout << "Known_Money : " << his_known_money << endl;
	}
};

class Final:public Descendent
{
private:
	int final_back_money;
protected:
	int final_hidden_money;
public:
	int final_known_money;
public:
	Final(int ab, int ah, int ak, char* ap, int hb, int hh, int hk)
	    : Descendent(ab, ah, ak, ap, hb, hh, hk), final_back_money(0),
	      final_hidden_money(0), final_known_money(0) {}

	void inheritance()
	{
	    Descendent::inheritance();
	    final_back_money += his_back_money; //error : access denied~!!
	    final_hidden_money += his_hidden_money;
	    final_known_money += his_known_money;
	}

	void print()
	{
	    cout << "Back_Money : " << final_back_money << endl;
	    cout << "Hidden_Money : " << final_hidden_money << endl;
	    cout << "Known_Money : " << final_known_money << endl;
	}
};

int main(void)
{
	Descendent desc(1000, 2000, 3000, "kind", 100, 200, 300);
	Final desc_final(1000, 2000, 3000, "kind", 100, 200, 300);
	
	desc.inheritance();
	desc.print();

	desc_final.inheritance();
	desc_final.print();

	return 0;
}

*/
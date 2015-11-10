/**********************************************************
 [ Pointer to Member Operator ] 
**********************************************************/

/*
 .* 	연산자
 ->*	연산자

class Some
{
public:
	int data;
	void foo() { cout << "Some::foo" << endl;}
};
void main()
{
	int Some::*pdata = &Some::data;	// 멤버 data를 가르키는 Pointer
	void(Some::*f)() = Some::foo; 		// 멤버 함수를 가르키는 포인터.

	*pdata = 10;	// Error No Object!
	f();		 	// Error No Object

	Some some;
	some.*pdata = 10;
	(some.*f)();

	Some *pSome = new Some;
	pSome->*pdata = 20;
	(pSome->*f)();

	delete pSome;
}

*/

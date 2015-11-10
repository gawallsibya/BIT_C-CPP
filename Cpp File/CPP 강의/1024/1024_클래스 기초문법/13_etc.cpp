/**********************************************************
 [ Pointer to Member Operator ] 
**********************************************************/

/*
 .* 	������
 ->*	������

class Some
{
public:
	int data;
	void foo() { cout << "Some::foo" << endl;}
};
void main()
{
	int Some::*pdata = &Some::data;	// ��� data�� ����Ű�� Pointer
	void(Some::*f)() = Some::foo; 		// ��� �Լ��� ����Ű�� ������.

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

//main.cpp
#include "std.h"
#include "cintarray.h"

void main()
{
	CIntArray obj;

	obj.SetCapacity(10);

	obj.Add(10);

	obj.InsertAt(1, 20);
	obj.InsertAt(1, 30);
	obj.InsertAt(1, 40);
	obj.InsertAt(1, 50);

	for(int i=0; i< obj.GetSize(); i++)
	{
		cout << "obj [" << i << "] = " << obj.GetAt(i) << endl;
	}
	cout << endl; 

}
//main.cpp
#include "std.h"
#include "cstring.h"

void main()
{
	CString s1("Freedom");
	CString s2(" Peace");
	CString s3;

	cout << "s1 = " << s1.GetBuffer() << endl;	// s1 = Freedom
	cout << "s2 = " << s2.GetBuffer() << endl;	// s2 =  Peace

	if( s3.IsEmpty() )
	{
		s3.Assign(s1);
	}
	cout << "s3 = " << s3.GetBuffer() << endl;

	s3.Assign(s1.ConCat(s2));
	cout << "s3 = " << s3.GetBuffer() << endl;
}
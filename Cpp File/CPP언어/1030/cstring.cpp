//cstring.cpp
#include "std.h"
#include "cstring.h"

CString::CString()
{
	data	= NULL;
	size	= 0;
}

CString::CString(const char* str)
{
	data	= new char[strlen(str)+1];
	strcpy(data, str);

	size	= strlen(str);
}

CString::CString(const CString & rhs)
{
	data	= new char[strlen(rhs.data)+1];
	strcpy(data, rhs.data);

	size	= rhs.size;
}

CString::~CString()
{
	if( data != NULL)
		delete [] data;	
}

bool CString::IsEmpty() const
{
	if( size == 0 )
		return true;
	else
		return false;
}

//대입연산
CString& CString::Assign(const CString &arg)
{
	size	= arg.size;

	if( size != 0  )
	{
		delete [] data;
	}

	data = new char[arg.size + 1];
	strcpy(data, arg.data);
	return *this;
}

CString CString::ConCat(const CString &arg)
{
	char temp[256] = {0};
	size	= size + arg.size;

	if( size != 0  )
	{
		strcpy(temp, data);
		delete [] data;
	}

	data = new char[size+1];
	strcpy(data, temp);
	strcat(data, arg.data);
	return *this;
}
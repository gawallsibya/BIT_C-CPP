//cstring.h
#ifndef _CSTRING_H_
#define _CSTRING_H_

class CString
{
private:
	char* data;
	int   size;
public:
	CString();
	CString(const char* str);
	CString(const CString & rhs);
	~CString();
	
	const char* GetBuffer() const { return data; }
	bool IsEmpty() const;

	CString Assign(const CString &arg);
	CString ConCat(const CString &arg);

	int GetLength() const		{ return size;		}
	char GetAt(int idx) const	{ return data[idx]; }

	void SetAt(int idx, char ch) { data[idx] = ch;  }
};

#endif /*_CSTRING_H_*/
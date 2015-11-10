//cintarry.h

#ifndef _CINTARRAY_H_
#define _CINTARRAY_H_

class CIntArray
{
	int		*arr;
	int		aidx;
	int		size;
public:
	CIntArray();
	~CIntArray();
	
	void SetCapacity(int nsz);
	void Add(int val);
	void InsertAt(int idx, int val);

	int GetSize() const			{ return aidx;		}
	int GetAt(int idx) const	{ return arr[idx];	}

};

#endif /*_CINTARRAY_  */
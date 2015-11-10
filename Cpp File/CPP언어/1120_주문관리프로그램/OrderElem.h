//OrderElem.h

#ifndef _ORDERELEM_H_
#define _ORDERELEM_H_

class OrderElem
{
  int menu_idx;
  int menu_count;
public:
	OrderElem() {}
	OrderElem( int idx, int count) : menu_idx(idx), menu_count(count) {}

	void SetMenuIdx(int idx)		{ menu_idx		= idx;		}
	void SetCount(int count)		{ menu_count	= count;	}
	int  GetIdx() const				{ return menu_idx;			}
	int  GetCount() const			{ return menu_count;		}	
};

#endif	/*_ORDERELEM_H_*/
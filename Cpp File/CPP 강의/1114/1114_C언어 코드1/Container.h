// Container.h: interface for the CContainer class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CONTAINER_H__8677E684_B813_448D_AFA1_4B8F248AFF77__INCLUDED_)
#define AFX_CONTAINER_H__8677E684_B813_448D_AFA1_4B8F248AFF77__INCLUDED_

#include "Account.h"

class Container
{
	Account **	acc;
	int			index;
	int			max;
public:
	Container(int size = 10);
	~Container();

	bool push_back(Account * _acc);

	int GetIndex() const			{ return index; }
	Account * GetData(int idx)		{ return acc[idx]; }
};

#endif // !defined(AFX_CONTAINER_H__8677E684_B813_448D_AFA1_4B8F248AFF77__INCLUDED_)

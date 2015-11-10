//cintarray.cpp
#include "std.h"
#include "cintarray.h"

CIntArray::CIntArray()
{
	aidx	= 0;
	size	= 1;
//	arr		= (int*)malloc(sizeof(size));
	arr		= new int[size];
	memset(arr, 0, sizeof(int)*size);
}

CIntArray::~CIntArray()
{
	delete arr;
	arr	= NULL;
}
	
void CIntArray::SetCapacity(int nsz)
{	
	// 1. �ӽ� ����
	int *temp = new int[size];
	memcpy(temp, arr, sizeof(int)*size);
	//==========================================

	// 2. �޸� ���� �� ����
	delete [] arr;
	size	= nsz;
	arr	= new int[size];

	// 3. ���� ���� �� ���� 
	for(int i=0; i<aidx; i++)
	{
		arr[i] = temp[i];
	}

	delete [] temp;
}

void CIntArray::Add(int val)
{
	if( aidx >= size )
	{
		SetCapacity(size+1);
	}
	arr[aidx] = val;
	++aidx;
}

void CIntArray::InsertAt(int idx, int val)
{
	if( aidx >= size )
	{
		cout << "������ ������ �����ϴ�." << endl; 
		return;
	}

	for(int i= aidx; i > idx; i--)
	{
		arr[i] = arr[i-1];
	}
	arr[idx] = val;

	aidx++;
}
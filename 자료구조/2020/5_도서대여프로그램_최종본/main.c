#include "std.h"


//-------- ���� �̸��� ������ ���ڿ� ----
char	fileName[FILE_LENGTH] = FILENAME;
//-----------------------------------------

LIST		list;
treeNode	*root = NULL;

void main()
{
	fnInit();
	fnRun();
	fnExit();
}
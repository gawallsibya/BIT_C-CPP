#include "std.h"


//-------- 파일 이름을 저장할 문자열 ----
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
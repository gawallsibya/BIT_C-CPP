#ifndef _MANAGER_
#define _MANAGER_
#include "mylist.h"
LIST list;
void manager_init();
void manager_push_front();
void manager_printall();
void manager_search();
void manager_change();
void manager_dele();
NODE* find(char);
#endif /*_MANAGER_*/

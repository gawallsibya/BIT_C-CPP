#ifndef _MANAGER_H_
#define _MANAGER_H_
#include "stacklinklist.h"
#include "my.h"
Slist slist;
void manager_slist_init();

void manager_push_front();
void manager_printall(void (*)(void*));
NODE* manager_Search();
void manager_ChangeData();
void manager_delete();
void manager_update();
NODE* find(int (*)(void*,void*));



#endif /*_MANAGER_H_*/
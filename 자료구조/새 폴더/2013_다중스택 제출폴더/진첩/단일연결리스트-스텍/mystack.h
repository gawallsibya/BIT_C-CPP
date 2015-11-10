//mystack.h
#include "mylist.h"
#define MYSTACK List	

void stack_init(MYSTACK *pstack);
void push(MYSTACK *pstack, char ch);
void pop(MYSTACK *p, char *ch);

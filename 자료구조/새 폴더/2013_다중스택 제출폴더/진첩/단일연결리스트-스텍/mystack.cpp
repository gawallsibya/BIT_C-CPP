//mystack.cpp
#include "std.h"
#include "mylist.h"
#include "mystack.h"

void stack_init(MYSTACK *pstack)
{
	List_init(pstack);
}

void push(MYSTACK *pstack, char ch)
{
	List_push_front(pstack,  ch);
}

void pop(MYSTACK *p, char *ch)
{
	List_pop_back(p, ch);
}
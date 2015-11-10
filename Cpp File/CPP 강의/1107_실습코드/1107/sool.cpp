//sool.cpp
#include "std.h"
#include "sool.h"
#include "person.h"

void CSool::Visit(CPerson *p)
{
	p->AddSool(10);
}
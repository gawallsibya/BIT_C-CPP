//pcroom.cpp
#include "std.h"
#include "pcroom.h"
#include "person.h"

void CPCRoom::Visit(CPerson *p)
{
	p->AddPcRoom(10);
}
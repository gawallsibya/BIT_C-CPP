//library.cpp
#include "std.h"
#include "library.h"
#include "person.h"

void CLibrary::Visit(CPerson *p)
{
	p->AddLibrary(10);
}
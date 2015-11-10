//training.cpp
#include "std.h"
#include "training.h"
#include "person.h"

void CTraining::Visit(CPerson *p)
{
	p->AddTraining(10);
}
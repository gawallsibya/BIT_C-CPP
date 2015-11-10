//person.h

#ifndef _PERSON_H_
#define _PERSON_H_

class Person
{
	char name[20];
	char phone[30];
public:
	Person()	{} 
	Person(const char* n, const char* p);

	void SetName(char* n)		{ strcpy(name, n);	}
	void SetPhone(char* p)		{ strcpy(phone, p);	}
	const char*GetName()  const	{ return name;		}
	const char*GetPhoen() const { return phone;		}

	void DataPrint() const;
};


#endif /*_PERSON_H_*/
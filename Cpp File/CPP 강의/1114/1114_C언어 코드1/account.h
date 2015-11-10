//account.h
#ifndef _ACCOUNT_H_
#define _ACCOUNT_H_

#define NAME_LEN 20

class Account
{
	int		id;					// °èÁÂ¹øÈ£
	int		balance;			// ÀÜ    ¾×
	char	name[NAME_LEN];		// °í°´ ÀÌ¸§
public:
	Account(int _id, int _b, char* _name);

	int GetId() const			{ return id;		}
	int GetBalance() const		{ return balance;	}
	const char* GetName() const { return name;		}
	
	virtual void AddMoney(int m);
	bool MinMoney(int m);
	virtual void DataPrint();
};


#endif /*_ACCOUNT_H_ */
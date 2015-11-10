//menu.h
#ifndef _MENU_H_
#define _MENU_H_

class Menu
{
	char  m_name[20];		// �̸�( ������ �ʱ�ȭ)
    int   m_price;			// ����( ������ �ʱ�ȭ)
    int   m_count;			// �Ǹż��� = 0 
public:
	Menu() {}
	Menu(char* name, int price);

	const char* GetName() const	{ return m_name;	}
	int GetPrice() const		{ return m_price;	}
	int GetCount() const		{ return m_count;	}
	void SetName(char* name)	{ strcpy(m_name, name); }
	void SetPrice(int price)	{ m_price = price;		}
	void DataPrint() const;
};


#endif /*_MENU_H_ */